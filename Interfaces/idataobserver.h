#ifndef IDATAOBSERVER_H
#define IDATAOBSERVER_H

#include "requestdata.h"

class IDataObserver
{
public:
    IDataObserver();
    virtual void onNotify(int index, RequestData request) = 0;
};

#endif // IDATAOBSERVER_H
