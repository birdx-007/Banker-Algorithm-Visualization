#include "bankclient.h"

int BankClient::clientNum=0;

BankClient::BankClient()
{
    this->clientIndex=clientNum;
    clientNum++;
    this->sprite.load(QString(":/Sprites/BankClient.png"));
    qDebug()<<"Client"<<this->clientIndex<<"is created!";
}

QString BankClient::getDisplayContent()
{
    QString displayContent;
    displayContent.append(QString(" Client %1\n").arg(this->clientIndex));
    if(this->clientIndex<(int)dataAccess->allocation.size()) // 用户已在银行登记需求
    {
        for(int j=0;j<Constant::ResourceTypeNum;j++)
        {
            displayContent.append(QString(" %1").arg(request.getData()[j]));
        }
    }
    else
    {
        displayContent.append(QString(" No request for now."));
    }
    return displayContent;
}

void BankClient::paint(QPainter *painter)
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
        QRectF dataDisplayRect = QRectF(this->leftupX+this->sprite.width()*1.25,this->leftupY+this->sprite.height()*0.2,this->sprite.width()*Constant::ResourceTypeNum,this->sprite.height()*0.6);
        painter->setPen(QColor(255,255,255));
        painter->setBrush(QBrush(QColor(255,255,255,191)));
        painter->drawRect(dataDisplayRect);
        painter->setPen(QColor(0,0,0));
        painter->drawText(dataDisplayRect,getDisplayContent());
        painter->restore();
    }
}

void BankClient::setDataAccess(BankData *access)
{
    this->dataAccess = access;
}

void BankClient::submitRequest(std::array<int,Constant::ResourceTypeNum> need)
{
    this->request.setData(need);
    this->notify(this->clientIndex,this->request);
}

void BankClient::returnResource()
{
    this->notify(this->clientIndex);
}

