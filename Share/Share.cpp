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

#include "Share.h"

ICandyComponent::ID Share::id()
{
    return "candy.share";
}

ICandyComponent::ErrorCode Share::init()
{
    return NoError;
}

ICandyComponent::ErrorCode Share::exit()
{
    return NoError;
}

QString Share::errorMessage()
{
    return "May be?";
}

QString Share::versionString()
{
    return "0.0.1";
}

int Share::version()
{
    return 000001;
}

QString Share::desc()
{
    return "Candy's share Libraries for others. by 初夏同学";
}

QString Share::name()
{
    return "Candy Share Libraries";
}
