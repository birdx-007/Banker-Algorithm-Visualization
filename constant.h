#ifndef CONSTANT_H
#define CONSTANT_H
#include <QObject>

struct Constant
{
    static constexpr int ResourceTypeNum = 3;
    static constexpr int MaxClientNum = 5;

    static constexpr qreal CanvasWidth = 960;
    static constexpr qreal CanvasHeight = 720;
};

#endif // CONSTANT_H
