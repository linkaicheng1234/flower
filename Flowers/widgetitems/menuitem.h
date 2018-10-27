#ifndef MENUITEM_H
#define MENUITEM_H

#include <QWidget>

class MenuItem : public QWidget
{
    Q_OBJECT
public:
    explicit MenuItem(QWidget *parent = 0);
    ~MenuItem();
signals:

public slots:
};

#endif // MENUITEM_H
