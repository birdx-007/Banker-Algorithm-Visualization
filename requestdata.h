#ifndef REQUESTDATA_H
#define REQUESTDATA_H
#include "constant.h"
#include <vector>

class RequestData
{
public:
    RequestData();
    RequestData(std::vector<int>);
    void setData(std::vector<int>);
private:
    std::vector<int> resourceNeed;
};

#endif // REQUESTDATA_H
