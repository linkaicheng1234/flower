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

    //获取execl表格
//    QString applicationDirPathStr = QCoreApplication::applicationDirPath();

//    QString excel_file_path = applicationDirPathStr + "/1.xlsx";
//    qDebug()<<"excel_file_path"<<excel_file_path;
//    if(QFile(excel_file_path).exists())
//    {
//        ExecList *exc = new ExecList;
//        exc->openExec(excel_file_path);
//        exc->showData();
//        exc->closeExec();
//    }
}
