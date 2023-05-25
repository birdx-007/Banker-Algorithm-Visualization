#ifndef IDATASUBJECT_H
#define IDATASUBJECT_H
#include "requestdata.h"
#include <vector>

class IDataObserver;

class IDataSubject
{
public:
    IDataSubject();
    void attachObserver(IDataObserver*);
    void detachObserver(IDataObserver*);
    void notify(int index, RequestData request);
private:
    std::vector<IDataObserver*> observers;
};

#endif // IDATASUBJECT_H