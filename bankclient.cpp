#include "bankclient.h"

int BankClient::clientNum=0;

BankClient::BankClient()
{
    clientNum++;
    this->clientIndex=clientNum;
    this->sprite.load(QString(":/Sprites/BankClient.png"));
}

void BankClient::submitRequest(std::vector<int> need)
{
    this->request.setData(need);
    this->notify(this->clientIndex,this->request);
}

