#include "bankdata.h"

BankData::BankData()
{
    this->available.fill(0);
    this->max.reserve(Constant::MaxClientNum);
    this->allocation.reserve(Constant::MaxClientNum);
}
