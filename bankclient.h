#ifndef BANKCLIENT_H
#define BANKCLIENT_H
#include "Interfaces/idatasubject.h"
#include "Interfaces/ipaintable.h"
#include "bankdata.h"

class BankClient : public IDataSubject, public IPaintable
{
public:
    BankClient();
    virtual QString getDisplayContent() override;
    virtual void paint(QPainter *painter) override;
    void setDataAccess(BankData* access);
    void submitRequest(std::array<int,Constant::ResourceTypeNum> need);
    void returnResource();
    static int clientNum;
    int clientIndex;
private:
    RequestData request;
    BankData* dataAccess;
};

#endif // BANKCLIENT_H
