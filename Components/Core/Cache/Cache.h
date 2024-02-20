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

#ifndef CANDY_CORE_CACHE_H
#define CANDY_CORE_CACHE_H

#include <QObject>
#include <QVariant>
#include <QHash>
#include <QUuid>
#include <QLoggingCategory>
#include "../Daemon/Daemon.h"

Q_DECLARE_LOGGING_CATEGORY(cacheLogC)

class Cache : public QObject {
Q_OBJECT

public:
    static void init();

public:
    enum Type {
        Read = 1, Write = 2, Public = 4, NotDelete = 8
    };

    struct Resource {
        void *resource;
        QObject *owner;
        int permissions;
    };

    enum StateCode {
        Exist = 1, Visit = 2,
    };


    template<typename T>
    int hasResource(const QString &id, QObject *owner);

    /**
     * 自己的资源自己永远可读，写通过Write控制
     * 别人的资源只有在设置为Public 时才可以使用，读写通过 Read Write控制
     * 写是指复写资源 读是读取资源
     * @tparam T 资源类型
     * @param id 资源ID
     * @param resource 资源 资源必须是new在堆上的，缓存系统会自动释放内存
     * @param owner 资源所有者 所有者析构不会导致资源释放
     * @param permissions 资源权限
     */
    template<typename T>
    void submitResource(const QString &id, const T *resource, QObject *owner, int permissions = 0);

    /**
     * 获得资源
     * @tparam T
     * @param id
     * @param owner
     * @param permissions
     * @return 当资源不存在或者没有权限时返回nullptr
     */
    template<typename T>
    T *getResource(const QString &id, QObject *owner, int permissions = 0);

    /**
     * 移除资源
     * @tparam T
     * @param id
     * @param owner
     * @param permissions
     * @return 当资源不存在或者没有权限时返回nullptr
     */
    template<typename T>
    T *removeResource(const QString &id, QObject *owner, int permissions = 0);

    /**
     * removeResource的别名
     * @tparam T
     * @param id
     * @param owner
     * @param permissions
     * @return 当资源不存在或者没有权限时返回nullptr
     */
    template<typename T>
    T *takeResource(const QString &id, QObject *owner, int permissions = 0);


    Cache() = default;

    ~Cache() override;

private:
    QHash<QString, Resource> m_cache;

};


#endif //CANDY_CORE_CACHE_H
