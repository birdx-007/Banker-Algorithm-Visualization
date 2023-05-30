#include "bank.h"

Bank::Bank()
{
    manager.setDataAccess(&data);
}

void Bank::onNotify(int index, RequestData request)
{

}

void Bank::onNotify()
{

}
