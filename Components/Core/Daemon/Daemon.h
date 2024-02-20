//
// Created by 24118 on 2024/2/17.
//

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
