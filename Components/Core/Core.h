//
// Created by 24118 on 2024/2/19.
//

#ifndef CANDY_CORE_H
#define CANDY_CORE_H


#include <QObject>
#include "../../Share/api/ICandyComponent.h"

class Core : public QObject, public ICandyComponent {
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


#endif //CANDY_CORE_H
