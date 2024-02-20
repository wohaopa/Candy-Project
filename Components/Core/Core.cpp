/*
 *  Candy Framework - Plug-in Development Framework
 *  Copyright (C)  2024 初夏同学 2411829240@qq.com
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

#include "Core.h"
#include "Daemon/Daemon.h"
#include "Cache/Cache.h"
#include <QApplication>


ICandyComponent::ID Core::id()
{
    return "candy.core";
}

QString Core::name()
{
    return tr("Candy核心组件");
}

QString Core::desc()
{
    return tr("Candy的框架的基础。");
}

int Core::version()
{
    return 1;
}

QString Core::versionString()
{
    return "0.0.1";
}

QString Core::errorMessage()
{
    return {};
}

ICandyComponent::ErrorCode Core::init()
{

    QApplication::setApplicationName("Candy");
    QApplication::setOrganizationDomain("com.github.wohaopa");

    // 初始化Log
    // Log::init();
    // 初始化Daemon 用于各模块通信，挂载各种信号槽对象
    Daemon::init();
    // 初始化Cache 全局缓存，拥有权限系统
    Cache::init();
    // 初始化Config 配置，所有模块插件的配置文件
    // Config::init();
    // 初始化EventBus 事件总线，分发各种Candy事件，用于Api式编程
    // EventBus:init();
    // 初始化Task 任务模块，异步处理
    // Task::init();
    // 初始化组件管理 加载管理其他组件
    // ComponentsManager::init();
    // 初始化插件管理器 加载管理插件
    // PluginManager::init();


    return ICandyComponent::NoError;
}

ICandyComponent::ErrorCode Core::exit()
{
    return ICandyComponent::NoError;
}
