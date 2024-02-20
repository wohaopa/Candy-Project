//
// Created by 24118 on 2024/2/19.
//
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
