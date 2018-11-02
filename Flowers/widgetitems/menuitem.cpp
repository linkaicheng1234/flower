#include "menuitem.h"
#include <QLabel>
#include <QDebug>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFile>
#include <QScrollArea>
#include <QCoreApplication>
#include <QSpacerItem>
#include <QHeaderView>
#include "cargo.h"
#include "execlist.h"
MenuItem::MenuItem(QWidget *parent) : QWidget(parent)
{
    this->resize(800,400);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowFlags(Qt::FramelessWindowHint);
    initMenu();
}

MenuItem::~MenuItem()
{

}

void MenuItem::initMenu()
{
    //获取execl表格
    QString applicationDirPathStr = QCoreApplication::applicationDirPath();

    QString excel_file_path = applicationDirPathStr + "/1.xlsx";
    qDebug()<<"excel_file_path"<<excel_file_path;
    if(QFile(excel_file_path).exists())
    {
        menuExec = new ExecList;
        menuExec->openExec(excel_file_path);
        //menuExec->showData();
        menuList = menuExec->getList();
        menuExec->closeExec();
    }

    gLayout = new QGridLayout;
    int row,col = 0;
    int lineNumber = 5;
    int num = 0;
    int line = 0;
    menuExec->getrowcol(row,col);
    for(int i=0;i<row;i++)
    {
        carGo = new CarGo;
        QString name = menuList.at(i).at(0).toString();
        QString color = menuList.at(i).at(1).toString();
        QStringList colors = color.split('/');
        carGo->initParams(name,colors);
        qDebug()<<carGo->name()<<carGo->colors();
        if(num == lineNumber)
        {
            num = 0;
            line++;
        }
        gLayout->addWidget(carGo,line,num,1,1);
        connect(carGo,SIGNAL(numberChange()),this,SLOT(choose()));
        num++;
    }
    QWidget* scrollWidget = new QWidget;
    //scrollWidget->resize(800,300);
    scrollWidget->setLayout(gLayout);
    QScrollArea* scrollArea = new QScrollArea;
    scrollArea->setWidget(scrollWidget);

    //mid
    QStringList headText;
    headText<<tr("name")<<tr("color")<<tr("number");
    tableMes = new QTableWidget;
    tableMes->setColumnCount(headText.count());
    tableMes->setHorizontalHeaderLabels(headText);
    tableMes->horizontalHeader()->setFixedHeight(25); //设置表头的高度
    tableMes->resize(800,100);
    tableMes->horizontalHeader()->setStretchLastSection(true);
    tableMes->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableMes->horizontalHeader()->setVisible(true);
//    QScrollArea* scrollAreaMess = new QScrollArea;
//    scrollAreaMess->setWidget(tableMes);

    //bottom
    pbSure  = new QPushButton(tr("Sure"));
    pbCanel = new QPushButton(tr("Canel"));
    QHBoxLayout* hBottomLayout = new QHBoxLayout;
    hBottomLayout->addSpacerItem(new QSpacerItem(40,20,QSizePolicy::Expanding, QSizePolicy::Minimum));
    hBottomLayout->addWidget(pbSure);
    hBottomLayout->addWidget(pbCanel);
    //    QList<QString> list;
    //    list<<"blue"<<"red"<<"yellow";
    //    CarGo* order1 = new CarGo;
    //    order1->initParams("first",QStringList(list),":/images/common/LoGo.jpg");

    QVBoxLayout* vLayout = new QVBoxLayout;
    vLayout->addWidget(scrollArea);
    vLayout->addWidget(tableMes);
    vLayout->addLayout(hBottomLayout);
    setLayout(vLayout);
    connect(pbSure,SIGNAL(clicked()),this,SLOT(clickedSure()));
    connect(pbCanel,SIGNAL(clicked()),this,SLOT(clickedCanel()));
}

void MenuItem::mergeMes(QString name, int num, QString color)
{
    QTableWidgetItem* item;
    QList<QTableWidgetItem *> listItem = tableMes->findItems(name,Qt::MatchCaseSensitive);
    if(!listItem.isEmpty())
    {
        foreach(item,listItem)
        {
            if(!tableMes->item(item->row(),1)->text().compare(color))
            {
                if(num == 0)
                    tableMes->removeRow(item->row()); //删除行
                else
                    tableMes->item(item->row(),2)->setText(QString::number(num,10));//修改数量
                return ;
            }
        }
    }
    //不在tabwidget里
    int row = tableMes->rowCount();
    tableMes->insertRow(row);
    item = new QTableWidgetItem(name);
    item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    tableMes->setItem(row,0,item);
    item = new QTableWidgetItem(color);
    item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    tableMes->setItem(row,1,item);
    item = new QTableWidgetItem(QString::number(num,10));
    item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    tableMes->setItem(row,2,item);
}

void MenuItem::clickedSure()
{

}

void MenuItem::clickedCanel()
{

}

void MenuItem::choose()
{
    CarGo* item = qobject_cast<CarGo*> (sender());
//    if(!item->number())
//        teOrderMes->find()
    QString name = item->name();
    int num = item->number();
    QString color = item->color();
    mergeMes(name,num,color);
}

