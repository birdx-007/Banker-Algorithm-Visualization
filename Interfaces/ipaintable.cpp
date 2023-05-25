#include "ipaintable.h"

IPaintable::IPaintable()
{
    isValid=true;
    sprite=QPixmap();
}

void IPaintable::paint(QPainter *painter)
{
    if(isValid)
    {
        this->leftupX=this->centerX-this->sprite.width()/2.0;
        this->leftupY=this->centerY-this->sprite.height()/2.0;
        painter->save();
        painter->translate(this->centerX,this->centerY);
        painter->rotate(this->facingAngleDeg+90);
        painter->translate(-this->centerX,-this->centerY);
#ifdef QT_DEBUG
        painter->setPen(QColor(255,0,0));
        painter->drawRect(this->leftupX,this->leftupY,this->sprite.width(),this->sprite.height());
#endif
        painter->drawPixmap(this->leftupX,this->leftupY,this->sprite.width(),this->sprite.height(),this->sprite);
        painter->restore();
    }
}

void IPaintable::setPosition(qreal cx, qreal cy, qreal angleDeg)
{
    this->centerX=cx,this->centerY=cy;
    this->facingAngleDeg=angleDeg;
}
