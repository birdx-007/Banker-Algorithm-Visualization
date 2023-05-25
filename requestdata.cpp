#include "requestdata.h"
#include <QDebug>

RequestData::RequestData()
{
    this->resourceNeed.reserve(Constant::ResourceTypeNum);
}

RequestData::RequestData(std::vector<int> need)
{
    this->resourceNeed.reserve(Constant::ResourceTypeNum);
    setData(need);
}

void RequestData::setData(std::vector<int> need)
{
    if(need.size()!=Constant::ResourceTypeNum)
    {
        qDebug()<<"Error: the size of NEED vector is not equal to Constant::ResourceTypeNum.";
        return;
    }
    for(int i=0;i<Constant::ResourceTypeNum;i++)
    {
        resourceNeed[i]=need[i];
    }
}
