#ifndef CANDY_CORE_ICOMPONENT_H
#define CANDY_CORE_ICOMPONENT_H

#include <QtPlugin>
#include <QString>

class ICandyComponent {

public:
    enum ErrorCode {
        NoError = 0, Unknown
    };

    using ID = QString;
    /**
     * @return 组件ID，只包含 A-Za-z. 识别区分组件
     * 如：candy.minecraft
     */
    virtual ID id() = 0;
    /**
     * @return 组件名
     * 如：Minecraft启动器
     */
    virtual QString name() = 0;
    /**
     * @return 组件描述
     * 用于在Candy中启动Minecraft的组件，by 初夏同学
     */
    virtual QString desc() = 0;
    /**
     * @return 代码可比较的版本号
     * 如：010203
     */
    virtual int version() = 0;
    /**
     * @return 人类可读的版本号
     * 如：1.2.3
     */
    virtual QString versionString() = 0;
    /**
     * @return 组件加载/卸载时产生的错误消息，当错误码不为NoError时调用
     */
    virtual QString errorMessage() = 0;
    /**
     * 加载组件，注册事件、窗口、监听器
     * @return 错误码
     */
    virtual ErrorCode init() = 0;
    /**
     * 卸载组件，资源回收
     * @return 错误码
     */
    virtual ErrorCode exit() = 0;
};

QT_BEGIN_NAMESPACE

Q_DECLARE_INTERFACE(ICandyComponent, "Candy.ComponentInterFace/0.1");

QT_END_NAMESPACE

#endif //CANDY_CORE_ICOMPONENT_H
