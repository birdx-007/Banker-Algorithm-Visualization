#include "bankdata.h"

BankData::BankData()
{
    this->max.reserve(Constant::MaxClientNum);
    this->allocation.reserve(Constant::MaxClientNum);
}
