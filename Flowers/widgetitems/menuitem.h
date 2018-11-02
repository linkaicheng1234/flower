#ifndef MENUITEM_H
#define MENUITEM_H

#include <QWidget>
#include <QGridLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QTableWidget>
class ExecList;
class CarGo;
class MenuItem : public QWidget
{
    Q_OBJECT
public:
    explicit MenuItem(QWidget *parent = nullptr);
    ~MenuItem();
    void initMenu();
    void mergeMes(QString name,int num,QString color);
signals:

public slots:
    void clickedSure();
    void clickedCanel();
    void choose();
private:
    QList<QList<QVariant>> menuList;
    QGridLayout* gLayout;
    ExecList* menuExec;
    CarGo* carGo;
    QTableWidget* tableMes;
    QPushButton* pbSure;
    QPushButton* pbCanel;
};

#endif // MENUITEM_H
