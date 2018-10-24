#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QCheckBox>
#include <QAxObject>
#include <QDebug>
#include <QStandardPaths>
#include <QFileDialog>
#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    createUI();
}

MainWindow::~MainWindow()
{
}

void MainWindow::createUI()
{
//    this->setAttribute(Qt::WA_DeleteOnClose);
//    this->setWindowFlags(Qt::FramelessWindowHint);
    this->resize(800,600);
    font12.setFamily("宋体");
    font12.setPointSize(12);
    this->setFont(font12);

    //top
    upFrame = new QFrame;

    labelLogo = new QLabel;
    QPixmap pixmap(":/images/common/LoGo.jpg");
    QPixmap fitpixmap=pixmap.scaled(186, 46, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    labelLogo->setPixmap(fitpixmap);

    labelTheme = new QLabel;
    labelTheme->setText(tr("welcome"));

    QHBoxLayout* topLayout = new QHBoxLayout;
    topLayout->addWidget(labelLogo);
    topLayout->addWidget(labelTheme);
    upFrame->setLayout(topLayout);
    upFrame->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);
    upFrame->setMinimumHeight(80);
    upFrame->setAutoFillBackground(true);

    //填充背景
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/common/TopBG.jpg")));
    upFrame->setPalette(palette);

    //center  left
    pbNewOrder = new QPushButton;
    pbFinishOrder = new QPushButton;
    pbAllOrder = new QPushButton;

    pbNewOrder->setText(tr("new order"));
    pbFinishOrder->setText(tr("finish order"));
    pbAllOrder->setText(tr("all order"));

    QVBoxLayout* leftLayout = new QVBoxLayout;
    leftLayout->setContentsMargins(5,5,5,5);
    leftLayout->setSpacing(20);
    leftLayout->addWidget(pbNewOrder);
    leftLayout->addWidget(pbFinishOrder);
    leftLayout->addWidget(pbAllOrder);

    //center  right
    QCheckBox* cbSelectAll = new QCheckBox;
    cbSelectAll->setText(tr("select all"));
    QHBoxLayout* hLayout = new QHBoxLayout;
    hLayout->addWidget(cbSelectAll);


    //订单界面，自己做成QWidget基类
    QList<QString> list;
    list<<"blue"<<"red"<<"yellow";
    CarGo* order1 = new CarGo() ;
    order1->initParams("first",QStringList(list),":/images/common/LoGo.jpg");

    CarGo* order2 = new CarGo() ;
    order2->initParams("two",QStringList(list),":/images/common/LoGo.jpg");

    CarGo* order3 = new CarGo() ;
    order3->initParams("three",QStringList(list),":/images/common/LoGo.jpg");

    CarGo* order4 = new CarGo() ;
    order4->initParams("four",QStringList(list),":/images/common/LoGo.jpg");

    CarGo* order5 = new CarGo();
    order5->initParams("five",QStringList(list),":/images/common/LoGo.jpg");


    QGridLayout* rightgLayout = new QGridLayout;
    rightgLayout->addWidget(order1,0,0,1,1);
    rightgLayout->addWidget(order2,0,1,1,1);
    rightgLayout->addWidget(order3,0,2,1,1);
    rightgLayout->addWidget(order4,1,2,1,1);
    rightgLayout->addWidget(order5,2,0,1,1);

    QWidget* rightWidget = new QWidget;
    rightWidget->setLayout(rightgLayout);

    QVBoxLayout* rightLayout = new QVBoxLayout;
    rightLayout->addLayout(hLayout);
    rightLayout->addWidget(rightWidget);


    rightFrame = new QFrame;
    rightFrame->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);
    rightFrame->setMinimumHeight(500);
    rightFrame->setLayout(rightLayout);

    QHBoxLayout* cetLayout = new QHBoxLayout;
    cetLayout->addLayout(leftLayout);
    cetLayout->addWidget(rightFrame);

    //bottom

    QWidget *m_pCenterWidget = new QWidget(this);
    setCentralWidget(m_pCenterWidget);
    QVBoxLayout *mainVBoxLayout = new QVBoxLayout(m_pCenterWidget);
    mainVBoxLayout->addWidget(upFrame);
    mainVBoxLayout->addLayout(cetLayout);
    mainVBoxLayout->setContentsMargins(0, 0, 0, 0);
    mainVBoxLayout->setSpacing(2);
    this->setLayout(mainVBoxLayout);

    //获取execl表格
    QString applicationDirPathStr = QCoreApplication::applicationDirPath();
    qDebug()<< "applicationDirPathStr:" << applicationDirPathStr;

    QString excel_file_path = applicationDirPathStr + "/1.xlsx";
    qDebug()<<"excel_file_path"<<excel_file_path;
    ExecList *exc = new ExecList;
    exc->openExec(excel_file_path);
    exc->showData();
    exc->closeExec();
}
