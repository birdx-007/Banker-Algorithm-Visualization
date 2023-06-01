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
    simulationInitiate();
    this->userWindow=window;
    this->timer=new QTimer(this);
    this->timer->setInterval(20);
    connect(this->timer,&QTimer::timeout,[=]()
    {
        onUpdate();
    });
    this->timer->start();
}

void Engine::simulationInitiate()
{
    std::array<int,Constant::ResourceTypeNum> available {3,3,2};
    std::vector<std::array<int,Constant::ResourceTypeNum>> max {{7,5,3},
                                                                {3,2,2},
                                                                {9,0,2},
                                                                {2,2,2},
                                                                {4,3,3}};
    std::vector<std::array<int,Constant::ResourceTypeNum>> allocation {{0,1,0},
                                                                       {2,0,0},
                                                                       {3,0,2},
                                                                       {2,1,1},
                                                                       {0,0,2}};
    bank.data.available=available;
    bank.data.max=max;
    bank.data.allocation=allocation;
    bank.selfCheck();
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
