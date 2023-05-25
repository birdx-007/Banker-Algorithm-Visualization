#include "userwindow.h"
#include "ui_userwindow.h"
#include <QPainter>

UserWindow::UserWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("Welcome, Banker 014!  ^_^"));
    canvas=QPixmap(Constant::CanvasWidth,Constant::CanvasHeight);
}

UserWindow::~UserWindow()
{
    delete ui;
}

void UserWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    QRect ResizedCanvasRect=QRect(0,0,std::min(this->rect().width(),(int)(this->rect().height()/Constant::CanvasHeight*Constant::CanvasWidth)),std::min(this->rect().height(),(int)(this->rect().width()/Constant::CanvasWidth*Constant::CanvasHeight)));
    painter.drawPixmap(ResizedCanvasRect,canvas);
    canvas=QPixmap(Constant::CanvasWidth,Constant::CanvasHeight); // clear canvas
}

void UserWindow::paintCanvas(IPaintable& paintable)
{
    QPainter canvasPainter(&canvas);
    paintable.paint(&canvasPainter);
}
