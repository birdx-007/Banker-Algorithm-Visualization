#include "engine.h"

Engine::Engine(UserWindow* window)
{
    this->clients.reserve(Constant::MaxClientNum);
    for(int i=0;i<Constant::MaxClientNum;i++)
    {
        this->clients.push_back(BankClient());
        this->clients[i].setPosition(100,100+i*125,-90);
        this->clients[i].attachObserver(&bank);
        this->clients[i].setDataAccess(&bank.data);
    }
    bank.setPosition(725,100,-90);
    this->userWindow=window;
    this->timer=new QTimer(this);
    this->timer->setInterval(20);
    connect(this->timer,&QTimer::timeout,[=]()
    {
        onUpdate();
    });
    this->timer->start();
}

void Engine::onUpdate()
{
    for(int i=0;i<(int)this->clients.size();i++)
    {
        this->userWindow->paintCanvas(this->clients[i]);
    }
    this->userWindow->paintCanvas(this->bank);
    this->userWindow->update();
}
