#include "cargo.h"
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
CarGo::CarGo(QFrame *parent):QFrame(parent)
{

    this->resize(50,50);
    this->setMaximumSize(150,150);

    //不能设置边框颜色
    //this->setFrameShape(QFrame::Box);

    //setStyleSheet这种边框设置父控件会影响子控件
    //this->setStyleSheet ("background-image:url(:/images/common/border.png);");

    //边框设置
    this->setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(this->backgroundRole(),QBrush(QPixmap(":/images/common/border.png")));
    this->setPalette(palette);

    this->show();

    labelPic = new QLabel;
    labelName = new QLabel;
    sbNumber = new QSpinBox;
    cbselect = new QComboBox;

    labelPic->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    labelName->setAlignment(Qt::AlignHCenter);

    QHBoxLayout* HLayout = new QHBoxLayout;
    HLayout->addWidget(sbNumber);
    HLayout->addWidget(cbselect);

    QVBoxLayout* VLayout = new QVBoxLayout;
    VLayout->addWidget(labelPic);
    VLayout->addWidget(labelName);
    VLayout->addLayout(HLayout);
    this->setLayout(VLayout);

}

void CarGo::setName(QString name)
{
    labelName->setText(name);
}

void CarGo::setSelect(QStringList list)
{
    cbselect->addItems(list);
}

void CarGo::setPic(QString picPath)
{
    QPixmap pixmap(picPath);
    QPixmap fitpixmap=pixmap.scaled(186, 46, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    labelPic->setPixmap(fitpixmap);

}

QString CarGo::name()
{
    return labelName->text();
}

void CarGo::initParams(QString name, QStringList list, QString picPath)
{

    labelName->setText(name);
    cbselect->addItems(list);
    if(picPath.isNull())
        return ;
    QPixmap pixmap(picPath);
    QPixmap fitpixmap=pixmap.scaled(186, 46, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    labelPic->setPixmap(fitpixmap);


}

