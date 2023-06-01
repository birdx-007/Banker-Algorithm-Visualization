#ifndef BANK_H
#define BANK_H
#include "Interfaces/idataobserver.h"
#include "Interfaces/ipaintable.h"
#include "bankmanager.h"
#include "bankdata.h"
#include <array>
#include <vector>

class Bank : public IDataObserver, public IPaintable
{
public:
    Bank();
    virtual QString getDisplayContent() override;
    virtual void paint(QPainter *painter) override;
    virtual void onNotify(int index, RequestData request) override;
    virtual void onNotify(int index) override;
    BankData data;
private:
    BankManager manager;
};

#endif // BANK_H
