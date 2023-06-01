#include "requestdata.h"
#include <QDebug>

RequestData::RequestData()
{
    resourceNeed.fill(0);
}

RequestData::RequestData(std::array<int,Constant::ResourceTypeNum> need)
{
    setData(need);
}

void RequestData::setData(std::array<int,Constant::ResourceTypeNum> need)
{
    for(int i=0;i<Constant::ResourceTypeNum;i++)
    {
        resourceNeed[i]=need[i];
    }
}

std::array<int, Constant::ResourceTypeNum> RequestData::getData()
{
    return resourceNeed;
}
