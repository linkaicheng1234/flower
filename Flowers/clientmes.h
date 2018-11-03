#ifndef CLIENTMES_H
#define CLIENTMES_H

#include <QtSql>
#include <stdarg.h>

class ClientMes: public QSqlQuery
{
public:
    ClientMes();
    bool openDb(QString dbName);
    void closeDb();
    QSqlQuery* query;
private:
    QSqlDatabase db;

   /* QString leTheme;
    QLabel* leTime;
    QLabel* leName;
    QLabel* leMoney;
    QLabel* leOther;
    bool isPayOff*/

};

#endif // CLIENTMES_H
