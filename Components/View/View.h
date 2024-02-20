//
// Created by 24118 on 2024/2/20.
//

#ifndef CANDY_VIEW_H
#define CANDY_VIEW_H


#include <QObject>
#include "../../Share/api/ICandyComponent.h"

class View : public QObject, public ICandyComponent {
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


#endif //CANDY_VIEW_H
