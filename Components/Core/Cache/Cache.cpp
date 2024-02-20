//
// Created by 24118 on 2024/2/17.
//

#include "Cache.h"

Q_LOGGING_CATEGORY(cacheLogC, "core.cache")

void Cache::init()
{
    Daemon::submit<Cache>();
}

template<typename T>
int Cache::hasResource(const QString &id, QObject *owner)
{
    if (m_cache.contains(id)) {
        auto &res = m_cache[id];
        if (res.permissions & Public || owner == res.owner) {
            return Exist | Visit;
        }
        return Exist;
    } else return 0;
}

template<typename T>
T *Cache::takeResource(const QString &id, QObject *owner, int permissions)
{
    return removeResource<T>(id, owner, permissions);
}

template<typename T>
T *Cache::removeResource(const QString &id, QObject *owner, int permissions)
{
    switch (hasResource<T>(id, owner)) {
        case 0:
        case Exist:
            return nullptr;
        case Exist | Visit:
            auto res = m_cache.take(id);
            if (res.owner == owner || res.permissions & Write) { // 自己可读
                return res.resource;
            } else return nullptr;
    }
}

template<typename T>
T *Cache::getResource(const QString &id, QObject *owner, int permissions)
{
    switch (hasResource<T>(id, owner)) {
        case 0:
        case Exist:
            return nullptr;
        case Exist | Visit:
            auto &res = m_cache[id];
            if (res.owner == owner || res.permissions & Read) { // 自己可读
                return res.resource;
            } else return nullptr;
    }
}

template<typename T>
void Cache::submitResource(const QString &id, const T *resource, QObject *owner, int permissions)
{
    switch (hasResource<T>(id, owner)) {
        case 0:
            qCDebug(cacheLogC) << "新缓存创建:" << id << "resource:"
                               << QString::number(reinterpret_cast<qulonglong>(resource), 16) << "owner:"
                               << QString::number(reinterpret_cast<qulonglong>(resource), 16);
            m_cache.insert(id, {resource, owner, permissions});
            return;
        case Exist:
            return;
        case Exist | Visit:
            auto res = m_cache[id];
            if (res.permissions & Write) {
                if (!(res.permissions & NotDelete))
                    delete m_cache[id].resource;        // 自动释放
                m_cache.insert(id, {resource, owner, permissions});
            }
            return;
    }

}

Cache::~Cache()
{   // 删除所有资源
    for (auto &res: m_cache) {
        if (!(res.permissions & NotDelete))
            delete res.resource;
    }
}


