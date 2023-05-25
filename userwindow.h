#ifndef WIDGET_H
#define WIDGET_H
#include "Interfaces/ipaintable.h"
#include "requestdata.h"
#include <vector>
#include <QWidget>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class UserWindow; }
QT_END_NAMESPACE

class UserWindow : public QWidget
{
    Q_OBJECT

public:
    UserWindow(QWidget *parent = nullptr);
    ~UserWindow();
    virtual void paintEvent(QPaintEvent *) override;
    void paintCanvas(IPaintable&);
private:
    QPixmap canvas;
    Ui::UserWindow *ui;
};
#endif // WIDGET_H
