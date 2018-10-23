#include "cargo.h"
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
CarGo::CarGo(QWidget *parent):QWidget(parent)
{

    labelPic = new QLabel;
    labelName = new QLabel;
    sbNumber = new QSpinBox;
    cbselect = new QComboBox;

    QPixmap pixmap(":/images/common/LoGo.jpg");
    QPixmap fitpixmap=pixmap.scaled(186, 46, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    labelPic->setPixmap(fitpixmap);


    QHBoxLayout* HLayout = new QHBoxLayout;
    HLayout->addWidget(sbNumber);
    HLayout->addWidget(cbselect);

    QVBoxLayout* VLayout = new QVBoxLayout;
    VLayout->addWidget(labelPic);
    VLayout->addWidget(labelName);
    VLayout->addLayout(HLayout);
    this->setLayout(VLayout);

    this->resize(50,50);
    this->setMaximumSize(150,150);
    this->show();
}

