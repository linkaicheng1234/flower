#include "menuitem.h"
#include <QLabel>
#include <QDebug>
#include <QVBoxLayout>
#include <QGridLayout>
#include "cargo.h"
MenuItem::MenuItem(QWidget *parent) : QWidget(parent)
{
    this->resize(800,400);
    this->setAttribute(Qt::WA_DeleteOnClose);
//    this->setWindowFlags(Qt::FramelessWindowHint);
    qDebug()<<"menu show";

    QList<QString> list;
    list<<"blue"<<"red"<<"yellow";
    CarGo* order1 = new CarGo;
    order1->initParams("first",QStringList(list),":/images/common/LoGo.jpg");

    QGridLayout* gLayout = new QGridLayout(this);
    gLayout->addWidget(order1,0,0,1,1);
    this->setLayout(gLayout);
}

MenuItem::~MenuItem()
{

}

