#include "requestdata.h"
#include <QDebug>

RequestData::RequestData()
{
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
