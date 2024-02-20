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

#ifndef CANDY_SHARE_H
#define CANDY_SHARE_H

#include "api/ICandyComponent.h"
#include <QObject>

class Share : public QObject, public ICandyComponent {
Q_OBJECT

    Q_PLUGIN_METADATA(IID "Candy.ComponentInterFace/0.1")
    Q_INTERFACES(ICandyComponent)

public:
    ID id() override;

    QString name() override;

    QString desc() override;

    int version() override;

    QString versionString() override;

    QString errorMessage() override;

    ErrorCode init() override;

    ErrorCode exit() override;
};


#endif //CANDY_SHARE_H
