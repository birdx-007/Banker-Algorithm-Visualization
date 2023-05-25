#include "bank.h"

Bank::Bank()
{
    this->max.reserve(Constant::MaxClientNum);
    this->allocation.reserve(Constant::MaxClientNum);
}

void Bank::onNotify(int index, RequestData request)
{

}
