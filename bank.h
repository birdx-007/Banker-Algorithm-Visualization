#ifndef BANK_H
#define BANK_H
#include "Interfaces/idataobserver.h"
#include "bankmanager.h"
#include "bankdata.h"
#include <array>
#include <vector>

class Bank : public IDataObserver
{
public:
    Bank();
    virtual void onNotify(int index, RequestData request) override;
    virtual void onNotify() override;
    BankData data;
private:
    BankManager manager;
};

#endif // BANK_H
