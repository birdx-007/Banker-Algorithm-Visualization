#ifndef ENGINE_H
#define ENGINE_H
#include "userwindow.h"
#include "bankclient.h"
#include <QObject>
#include <QTimer>

class Engine : QObject
{
public:
    Engine(UserWindow*);
    void onUpdate();
    std::vector<BankClient> clients;
private:
    QTimer* timer;
    UserWindow* userWindow;
};

#endif // ENGINE_H
