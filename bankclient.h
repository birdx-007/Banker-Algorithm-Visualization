#ifndef BANKCLIENT_H
#define BANKCLIENT_H
#include "Interfaces/idatasubject.h"
#include "Interfaces/ipaintable.h"

class BankClient : public IDataSubject, public IPaintable
{
public:
    BankClient();
    void submitRequest(std::array<int,Constant::ResourceTypeNum> need);
    static int clientNum;
    int clientIndex;
private:
    RequestData request;
};

#endif // BANKCLIENT_H
