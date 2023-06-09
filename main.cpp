#include "userwindow.h"
#include "engine.h"
#include "constant.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Constant constant;
    QApplication a(argc, argv);
    UserWindow w;
    Engine engine(&w);
    w.show();
    return a.exec();
}
