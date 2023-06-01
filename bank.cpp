#include "bank.h"

Bank::Bank()
{
    manager.setDataAccess(&data);
    this->sprite.load(QString(":/Sprites/Bank.png"));
}

QString Bank::getDisplayContent()
{
    QString displayContent;
    displayContent.append(QString(" Bank\n\n"));
    displayContent.append(QString(" Available:\n"));
    for(int j=0;j<Constant::ResourceTypeNum;j++)
    {
        displayContent.append(QString(" %1").arg(this->data.available[j]));
    }
    displayContent.append(QString("\n\n Max:\n"));
    for(int i=0;i<(int)this->data.max.size();i++)
    {
        for(int j=0;j<Constant::ResourceTypeNum;j++)
        {
            displayContent.append(QString(" %1").arg(this->data.max[i][j]));
        }
        displayContent.append(QString("\n"));
    }
    if(this->data.max.size()==0)
    {
        displayContent.append(QString(" (empty)\n"));
    }
    displayContent.append(QString("\n\n Allocation:\n"));
    for(int i=0;i<(int)this->data.allocation.size();i++)
    {
        for(int j=0;j<Constant::ResourceTypeNum;j++)
        {
            displayContent.append(QString(" %1").arg(this->data.allocation[i][j]));
        }
        displayContent.append(QString("\n"));
    }
    if(this->data.allocation.size()==0)
    {
        displayContent.append(QString(" (empty)\n"));
    }
    displayContent.append(QString("\n\n Need:\n"));
    for(int i=0;i<(int)this->data.need.size();i++)
    {
        for(int j=0;j<Constant::ResourceTypeNum;j++)
        {
            displayContent.append(QString(" %1").arg(this->data.need[i][j]));
        }
        displayContent.append(QString("\n"));
    }
    if(this->data.need.size()==0)
    {
        displayContent.append(QString(" (empty)\n"));
    }
    return displayContent;
}

void Bank::paint(QPainter *painter)
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
        QRectF dataDisplayRect = QRectF(this->centerX-this->sprite.width()*1,this->leftupY+this->sprite.height()*1.25,this->sprite.width()*2,this->sprite.height()*3.5);
        painter->drawPixmap(this->leftupX,this->leftupY,this->sprite.width(),this->sprite.height(),this->sprite);
        painter->setPen(QColor(255,255,255));
        painter->setBrush(QBrush(QColor(255,255,255,191)));
        painter->drawRect(dataDisplayRect);
        painter->setPen(QColor(0,0,0));
        painter->drawText(dataDisplayRect,getDisplayContent());
        painter->restore();
    }
}

void Bank::onNotify(int index, RequestData request)
{
    if(index>=(int)this->data.allocation.size()) // 银行尚未收录该客户请求
    {
        this->data.max.push_back(request.getData());
        this->data.allocation.push_back(std::array<int,Constant::ResourceTypeNum>());
        this->data.need.push_back(std::array<int,Constant::ResourceTypeNum>());
    }
    bool allocationFinish = manager.bankerAlgorithm(index,request);
    if(allocationFinish)
    {
        qDebug()<<"The request from Client"<<index<<"is satisfied.";
    }
    else
    {
        qDebug()<<"The request from Client"<<index<<"fails.";
    }
}

void Bank::onNotify(int index) //客户归还资源
{
    if(index>=(int)this->data.allocation.size()) // 银行尚未收录该客户请求
    {
        qDebug()<<"Error: Client"<<index<<"is not in the bank data. Return resources failed!";
        return;
    }
    for(int j=0;j<Constant::ResourceTypeNum;j++)
    {
        this->data.available[j] += this->data.allocation[index][j];
        this->data.max[index][j] = this->data.need[index][j] = this->data.allocation[index][j] = 0;
    }
    qDebug()<<"Client"<<index<<"return resources to the bank.";
}
