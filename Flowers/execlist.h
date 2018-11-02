#ifndef EXECLIST_H
#define EXECLIST_H

#include <QObject>
#include <QAxBase>
#include <QAxObject>

class ExecList
{
public:
    ExecList(QString execPath = NULL);
    ~ExecList();
    bool openExec(QString execPath);
    void closeExec();
    QVariant readData(int row,int column);//,QList<QList<QVariant>> list = NULL);
    void writeData(int row,int column,QVariant data);//,QList<QList<QVariant>> list = NULL);
    void getrowcol(int& row,int& col);
    void showData();
    QList<QList<QVariant>> getList();
    //void findData(QVariant data);
    void castVariant2ListListVariant(const QVariant &var);

private:
    QList<QList<QVariant>> execList;
    QString execPath;

    QAxObject *excel;

    QAxObject* workbook;//工作簿
    QAxObject *allWorkSheets;//工作表
    QAxObject *curWorkSheet;//当前工作表
    int intRow;
    int intCol;
};

#endif // EXECLIST_H
