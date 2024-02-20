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

#include "View.h"

ICandyComponent::ID View::id()
{
    return "candy.view";
}

QString View::name()
{
    return tr("Candy视图组件");
}

QString View::desc()
{
    return tr("Candy的框架的基础。");
}

int View::version()
{
    return 1;
}

QString View::versionString()
{
    return "0.0.1";
}

QString View::errorMessage()
{
    return {};
}

ICandyComponent::ErrorCode View::init()
{
    return ICandyComponent::NoError;
}

ICandyComponent::ErrorCode View::exit()
{
    return ICandyComponent::NoError;
}
