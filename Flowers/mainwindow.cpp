#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QCheckBox>
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
    CarGo* OrderMenu = new CarGo() ;

    QVBoxLayout* rightLayout = new QVBoxLayout;
    rightLayout->addLayout(hLayout);
    rightLayout->addWidget(OrderMenu);

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
}
