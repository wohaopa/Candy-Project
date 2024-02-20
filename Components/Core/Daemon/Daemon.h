/*
 *  Candy Framework - Plug-in Development Framework
 *  Copyright (C) 2024 初夏同学 <2411829240@qq.com>
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

#ifndef CANDY_CORE_DAEMON_H
#define CANDY_CORE_DAEMON_H

#include "qcoreapplication.h"
#include <QtLogging>
#include <QLoggingCategory>
#include <QThread>

Q_DECLARE_LOGGING_CATEGORY(daemonLogC)
namespace Daemon {
    class DaemonObj;

    DaemonObj *instance();

    void init();

    void exit();

    /**
     * 休眠调用者所在的线程，但是不终止消息队列
     * @tparam Func 返回int/bool形的函数
     * @param func
     */
    template<typename Func>
    void waitIf(Func func)
    {
        qCDebug(daemonLogC) << "暂停线程: " << QThread::currentThread();
        while (func()) {
            QThread::msleep(100);
            QCoreApplication::processEvents();
        }
        qCDebug(daemonLogC) << "唤醒线程: " << QThread::currentThread();
    }

    void submitInternal(QObject *qObject);

    /**
     * 将对象移动迷到守护线程，要求对象在堆中
     * @param object
     */
    template<class T>
    T *submit()
    {
        auto *object = new T;
        submitInternal(object);
        return object;
    }


    class DaemonObj : public QObject {
    Q_OBJECT

    public:
        DaemonObj();
    };

}
#endif //CANDY_CORE_DAEMON_H
