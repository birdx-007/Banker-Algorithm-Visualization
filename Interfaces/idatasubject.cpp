#include "idatasubject.h"
#include "idataobserver.h"
#include <algorithm>

IDataSubject::IDataSubject()
{
    observers.assign(5,nullptr);
}

void IDataSubject::attachObserver(IDataObserver *o)
{
    auto it=std::find(observers.begin(),observers.end(),nullptr);
    if(it!=observers.end())
    {
        *it=o;
    }
    else
    {
        observers.push_back(o);
    }
}

void IDataSubject::detachObserver(IDataObserver *o)
{
    auto it=std::find(observers.begin(),observers.end(),o);
    if(it!=observers.end())
    {
        *it=nullptr;
    }
}

void IDataSubject::notify(int index, RequestData request)
{
    for(auto o:observers)
    {
        if(o!=nullptr)
        {
            o->onNotify(index,request);
        }
    }
}

void IDataSubject::notify(int index)
{
    for(auto o:observers)
    {
        if(o!=nullptr)
        {
            o->onNotify(index);
        }
    }
}
