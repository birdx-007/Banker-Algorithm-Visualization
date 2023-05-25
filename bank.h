#ifndef BANK_H
#define BANK_H
#include "Interfaces/idataobserver.h"
#include <array>
#include <vector>

class Bank : public IDataObserver
{
public:
    Bank();
    virtual void onNotify(int index, RequestData request) override;
    std::array<int,Constant::ResourceTypeNum> available;
    std::vector<std::array<int,Constant::ResourceTypeNum>> max;
    std::vector<std::array<int,Constant::ResourceTypeNum>> allocation;
private:
    std::vector<std::array<int,Constant::ResourceTypeNum>> need;
};

#endif // BANK_H
