#include "cargo.h"
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
CarGo::CarGo(QFrame *parent):QFrame(parent)
{

    this->resize(150,150);
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

    hasNumber = false;
    connect(sbNumber,SIGNAL(valueChanged(int)),this,SLOT(ChangeValue(int)));
    connect(cbselect,SIGNAL(currentTextChanged(QString)),this,SLOT(Changecolor(QString)));

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

QStringList CarGo::colors()
{
    QStringList list;
    for(int i = 0;i<cbselect->count();i++)
        list<<cbselect->itemText(i);
    return list;
}

QString CarGo::color()
{
    return cbselect->currentText();
}

int CarGo::number()
{
    return sbNumber->text().toInt();
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

void CarGo::ChangeValue(int number)
{
    if(number)
        hasNumber = true;
    else
        hasNumber = false;
    emit numberChange();
}

void CarGo::Changecolor(QString Color)
{

}

