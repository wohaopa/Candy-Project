//
// Created by 24118 on 2024/2/20.
//

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
