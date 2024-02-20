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

#include "Daemon.h"

Q_LOGGING_CATEGORY(daemonLogC, "core.daemon")

namespace Daemon {

    static DaemonObj *daemonPtr;
    static QThread *daemonThreadPtr;

    void init()
    {
        daemonThreadPtr = new QThread;
        daemonThreadPtr->setObjectName("守护线程");

        qCDebug(daemonLogC) << "新线程:" << daemonThreadPtr << "由" << QThread::currentThread() << "创建";

        daemonThreadPtr->start();

        daemonPtr = submit<DaemonObj>();
        daemonThreadPtr->setPriority(QThread::IdlePriority);
    }


    void exit()
    {
        daemonThreadPtr->exit(0);
        waitIf([] { return daemonThreadPtr->isRunning(); });
        qCDebug(daemonLogC) << "线程:" << daemonThreadPtr << "已退出";
        delete daemonThreadPtr; // 手动删除
    }

    DaemonObj *instance() { return daemonPtr; }

    void submitInternal(QObject *qObject)
    {
        qObject->moveToThread(daemonThreadPtr);
        QObject::connect(daemonThreadPtr, &QThread::finished, qObject, &QObject::deleteLater);
    }

    // Daemon Object Member

    DaemonObj::DaemonObj()
    {

    }
}
