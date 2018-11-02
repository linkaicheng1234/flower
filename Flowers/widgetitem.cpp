#include "widgetitem.h"
#include <QTimer>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMapIterator>
#include "menuitem.h"
#include "ordermanage.h"
#include <QDebug>
WidgetItem::WidgetItem(QWidget *parent) : QWidget(parent)
{
//    QTime timer = new QTimer;
//    connect(timer,SIGNAL(timeout()),this,SLOT(displayTime()));
//    timer->setInterval(1000);
//    timer->start();
    this->resize(1000,520);
    this->setMaximumSize(1000,520);
    objectMap.clear();

    //left
    QVBoxLayout* leftLayout = new QVBoxLayout;
    leftLayout->setContentsMargins(5,5,5,5);
    leftLayout->setSpacing(20);

    btNameList.append(tr("new order"));
    btNameList.append(tr("finish order"));
    btNameList.append(tr("all order"));

    btGroup = new QButtonGroup;
    for(int i=0;i<btNameList.count();i++)
    {
        QToolButton *menuBts = new QToolButton;
        menuBts->setObjectName(btNameList.at(i));
        menuBts->setText(btNameList.at(i));
        btGroup->addButton(menuBts,i+1);
        leftLayout->addWidget(menuBts);
    }
    connect(btGroup,SIGNAL(buttonClicked(int)),this,SLOT(btGroupClick(int)));

    //right
    rightStackWidget = new QStackedWidget;
    rightStackWidget->setFrameStyle(QFrame::Box | QFrame::Raised);
    rightStackWidget->resize(900,520);
    rightStackWidget->setMaximumSize(900,520);
    QHBoxLayout* hLayout = new QHBoxLayout;
    hLayout->addLayout(leftLayout);
    hLayout->addWidget(rightStackWidget);
    this->setLayout(hLayout);

}

int WidgetItem::WidgetOpenInStackwidget(QString btObjectName)
{
    QMapIterator<QString, int> it(objectMap);
    while (it.hasNext()) {
        it.next();
        if(it.key() == btObjectName){
            return it.value();
        }
    }
    return -1;
}

void WidgetItem::btGroupClick(int ids)
{
    QToolButton *pToolbt = qobject_cast<QToolButton*>(btGroup->button(ids));
    QString btObjectName = pToolbt->objectName();
    int index = WidgetOpenInStackwidget(btObjectName);
    if(index >= 0)
    {
        rightStackWidget->setCurrentIndex(index);
        return ;
    }
    if(btObjectName.compare("new order") == 0)
    {
        MenuItem* widgetItem = new MenuItem();
        if(widgetItem){
           rightStackWidget->addWidget(widgetItem);
           rightStackWidget->setCurrentWidget(widgetItem);
           objectMap.insert(btObjectName,rightStackWidget->currentIndex());
        }
    }

    if(btObjectName.compare("finish order") == 0)
    {
        OrderManage* orderManage = new OrderManage();
        if(orderManage){
           rightStackWidget->addWidget(orderManage);
           rightStackWidget->setCurrentWidget(orderManage);
           objectMap.insert(btObjectName,rightStackWidget->currentIndex());
        }
    }

    if(btObjectName.compare("all order") == 0)
    {
        OrderManage* orderManage = new OrderManage();
        if(orderManage){
           rightStackWidget->addWidget(orderManage);
           rightStackWidget->setCurrentWidget(orderManage);
           objectMap.insert(btObjectName,rightStackWidget->currentIndex());
        }
    }

}
//    for(int i=1;i<btGroup->buttons().count()+1;++i){
//        QToolButton *pToolbt = qobject_cast<QToolButton*>(btGroup->button(i));
//        if(i == ids)
//            pToolbt->setStyleSheet("background-color:#7ECDEF");
//        else
//            //pToolbt->setStyleSheet("background-color:transparent");
//            pToolbt->setStyleSheet("background-color:#00FF00");
//    }



//void WidgetItem::displayTime()
//{
//    QDateTime curTime = QDateTime::currentDateTime();
//    labelTime->setText(curTime.toString("hh-mm-ss"));
//}

