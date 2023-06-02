#ifndef ENGINE_H
#define ENGINE_H
#include "userwindow.h"
#include "bankclient.h"
#include "bank.h"
#include "bankmanager.h"
#include <QObject>
#include <QTimer>

class Engine : QObject
{
    Q_OBJECT
public:
    Engine(UserWindow*);
    void simulationInitiate();
    void simulationStepForward();
    void onUpdate();
    std::vector<BankClient> clients;
    Bank bank;
private:
    QTimer* timer;
    UserWindow* userWindow;
    int step=0;
public slots:
    void onUserWindowKeyEnterPressed();
};

#endif // ENGINE_H
