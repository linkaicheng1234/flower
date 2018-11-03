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
#include <QFile>
#include <QWidget>
#include <QtSql>
#include "clientmes.h"
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
    this->resize(1000,600);

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
    //upFrame->setMinimumHeight(80);
    upFrame->resize(1000,80);
    upFrame->setAutoFillBackground(true);

    //填充背景
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/common/TopBG.jpg")));
    upFrame->setPalette(palette);



    //center  left
    cetWidget = new WidgetItem;


    //bottom

    QWidget *m_pCenterWidget = new QWidget();
    setCentralWidget(m_pCenterWidget);
    QVBoxLayout *mainVBoxLayout = new QVBoxLayout(m_pCenterWidget);
    mainVBoxLayout->addWidget(upFrame);
    mainVBoxLayout->addWidget(cetWidget);
    mainVBoxLayout->setContentsMargins(0, 0, 0, 0);
    mainVBoxLayout->setSpacing(2);
    m_pCenterWidget->setLayout(mainVBoxLayout);



    ClientMes* mes = new ClientMes;
    mes->openDb("client.db");
    mes->query->exec("create table automobil(id int, name varchar)");//,cargo varchar,color varchar,num int)");
    //插入记录
    for(int i = 0; i < 10; i++)
    {
//        mes->query->prepare("INSERT INTO ordmes(id, cargo,color,num)VALUES (:id, :cargo,:color,:num)");
//        mes->query->bindValue(":id", i);
//        mes->query->bindValue(":cargo", "furong");
//        mes->query->bindValue(":color", "blue");
//        mes->query->prepare("INSERT INTO ordmes (id,num)VALUES (:id,:num)");
//        mes->query->bindValue(":id", i);
//        mes->query->bindValue(":num", 10);
        mes->query->prepare("INSERT INTO automobil (id, name) "
                              "VALUES (:id, :name)");
        mes->query->bindValue(":id", i);
        mes->query->bindValue(":name", "furong");
        if(!mes->query->exec())
        {
            QSqlError lastError = mes->query->lastError();
            qDebug() << lastError.driverText() << QString(QObject::tr("INSERT failed."));
        }
    }
    mes->closeDb();
}
