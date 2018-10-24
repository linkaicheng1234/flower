#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QToolBox>
#include <QPushButton>
#include "cargo.h"
#include "execlist.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void createUI();
    QFont font12;

    QLabel* labelLogo;
    QLabel* labelTheme;
    QFrame* upFrame;
    QFrame* rightFrame;
    QPushButton* pbNewOrder;
    QPushButton* pbFinishOrder;
    QPushButton* pbAllOrder;


};

#endif // MAINWINDOW_H
