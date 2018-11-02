#include "ordermanage.h"
#include <QLabel>
#include <QDebug>
OrderManage::OrderManage(QWidget *parent) : QWidget(parent)
{
    this->resize(800,400);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowFlags(Qt::FramelessWindowHint);

}

OrderManage::~OrderManage()
{

}
