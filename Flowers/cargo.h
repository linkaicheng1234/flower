#ifndef CARGO_H
#define CARGO_H

#include <QWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QLabel>
class CarGo: public QFrame
{
    Q_OBJECT
public:
    CarGo(QFrame *parent = 0);
    void setName(QString name);
    void setSelect(QStringList list);
    void setPic(QString picPath);
    QString name();
    void initParams(QString name,QStringList list,QString picPath = NULL);

private:
    QLabel* labelPic;
    QLabel* labelName;
    QSpinBox* sbNumber;
    QComboBox* cbselect;


};

#endif // CARGO_H
