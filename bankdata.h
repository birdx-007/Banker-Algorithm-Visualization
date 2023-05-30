#ifndef BANKDATA_H
#define BANKDATA_H
#include "requestdata.h"
#include <vector>

class BankData
{
public:
    friend class Bank;
    friend class BankManager;
    BankData();
    std::array<int,Constant::ResourceTypeNum> available;
    std::vector<std::array<int,Constant::ResourceTypeNum>> max;
    std::vector<std::array<int,Constant::ResourceTypeNum>> allocation;
private:
    std::vector<std::array<int,Constant::ResourceTypeNum>> need;
};

#endif // BANKDATA_H
