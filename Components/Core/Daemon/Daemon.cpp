//
// Created by 24118 on 2024/2/17.
//

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
