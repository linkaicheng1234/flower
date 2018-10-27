#ifndef WIDGETITEM_H
#define WIDGETITEM_H

#include <QWidget>
#include <QLabel>
#include <QToolButton>
#include <QButtonGroup>
#include <QStackedWidget>
#include <QMap>
class WidgetItem : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetItem(QWidget *parent = 0);
    int WidgetOpenInStackwidget(QString btObjectName);
signals:

public slots:
   // void displayTime();
    void btGroupClick(int ids);
private:
    QLabel* labelTime;

    QButtonGroup* btGroup;
    QStringList btNameList;
    QStackedWidget* rightStackWidget;
    QMap<QString,int> objectMap;
};

#endif // WIDGETITEM_H
