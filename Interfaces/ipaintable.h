#ifndef IPAINTABLE_H
#define IPAINTABLE_H
#include <QObject>
#include <QPainter>
#include <QPixmap>

class IPaintable
{
public:
    IPaintable();
    virtual void paint(QPainter* painter);
    virtual void setPosition(qreal cx,qreal cy,qreal angleDeg);
    bool isValid;
    qreal centerX;
    qreal centerY;
    qreal facingAngleDeg;//以角度为单位的方向角，正左方向为0度，顺时针为正方向
    QPixmap sprite;
protected:
    qreal leftupX;
    qreal leftupY;
};

#endif // IPAINTABLE_H
