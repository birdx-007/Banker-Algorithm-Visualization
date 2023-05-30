#ifndef BANKMANAGER_H
#define BANKMANAGER_H
#include "bankdata.h"
#include "requestdata.h"

class BankManager
{
public:
    BankManager();
    void setDataAccess(BankData* access);
    bool safetyCheck();
    bool bankerAlgorithm(const int& index,const RequestData& request);
private:
    BankData* dataAccess;
};

#endif // BANKMANAGER_H
