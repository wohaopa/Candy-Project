/*
 *  Candy Framework - Plug-in Development Framework
 *  Copyright (C)  2024 初夏同学 <2411829240@qq.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <QtNetwork>
#include <QFile>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QApplication>
#include "../Share/api/ICandyComponent.h"

Q_LOGGING_CATEGORY(launcherLogC, "launcher")

static QPluginLoader *mainLoader;

inline int loadMainComponent(const QString &libPath, int version)
{
    mainLoader = new QPluginLoader(libPath);

    QObject *obj = mainLoader->instance();
    if (obj) {
        ICandyComponent *plugin = qobject_cast<ICandyComponent *>(obj);
        if (plugin) {
            if (version == plugin->version()) {

                qCDebug(launcherLogC) << "加载:" << plugin->name() << "版本:" << plugin->versionString() << "来自:"
                                      << mainLoader->fileName();
                if (plugin->init() == ICandyComponent::NoError) {
                    return 0;   // 模块正确加载并正确初始化，返回进入消息循环
                }
                QString string("模块: %1 初始化失败！\n错误信息: %2");
                string = string.arg(libPath).arg(plugin->errorMessage());
                qCCritical(launcherLogC) << string;
                QMessageBox::critical(nullptr, "Candy遇到了致命错误！", string, QMessageBox::Close);
                delete mainLoader;
                return -1;
            } else {
                QString string("指定模块: %1 版本: %2 不满足要求: %3！");
                string = string.arg(libPath).arg(plugin->version()).arg(version);
                qCCritical(launcherLogC) << string;
                QMessageBox::critical(nullptr, "Candy遇到了致命错误！", string, QMessageBox::Close);
                delete mainLoader;
                return -1;
            }
        }
    }
    auto string = "无法加载指定的入口模块：" + libPath + "\n" + "错误信息：" + mainLoader->errorString();
    qCCritical(launcherLogC) << string;
    QMessageBox::critical(nullptr, "Candy遇到了致命错误！", string, QMessageBox::Close);
    delete mainLoader;
    return -1;
}


int main(int argc, char *argv[])
{
    qCDebug(launcherLogC) << "你好，世界！";

    QApplication app(argc, argv);

    qCInfo(launcherLogC) << "Candy - Launcher";
    int exitCode;
    {
        QElapsedTimer elapsedTimer;
        elapsedTimer.start();   //开始计时

        QSettings settings("candy.ini", QSettings::IniFormat);
        if (!QFileInfo("candy.ini").exists()) {
            settings.setValue("component", "Components/Core");
            settings.setValue("version", 000001);
        }
        QString component = settings.value("component").toString();
        int version = settings.value("version").toInt();

        exitCode = loadMainComponent(component, version);
        qCInfo(launcherLogC) << "启动用时:"
                             << QString::number(static_cast<double>(elapsedTimer.nsecsElapsed()) / 1000000000.0, 'f', 3)
                             << "秒";
    }
    if (!exitCode) {
        return QApplication::exec();
    }
    return -1;
}