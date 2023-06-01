#ifndef REQUESTDATA_H
#define REQUESTDATA_H
#include "constant.h"
#include <array>

class RequestData
{
public:
    friend class BankManager;
    RequestData();
    RequestData(std::array<int,Constant::ResourceTypeNum>);
    void setData(std::array<int,Constant::ResourceTypeNum>);
    std::array<int,Constant::ResourceTypeNum> getData();
private:
    std::array<int,Constant::ResourceTypeNum> resourceNeed;
};

#endif // REQUESTDATA_H
