#ifndef CARGO_H
#define CARGO_H

#include <QWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QLabel>
class CarGo: public QWidget
{
    Q_OBJECT
public:
    CarGo(QWidget *parent = 0);
private:
    QLabel* labelPic;
    QLabel* labelName;
    QSpinBox* sbNumber;
    QComboBox* cbselect;

};

#endif // CARGO_H
