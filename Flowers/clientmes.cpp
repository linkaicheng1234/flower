#include "clientmes.h"
#include <QDebug>
#include <QMessageBox>
ClientMes::ClientMes(): QSqlQuery()
{
    db = QSqlDatabase::addDatabase("QSQLITE","sqlite1"); // 采用QSQLITE数据库，QMYSQL数据库有问题？

}

bool ClientMes::openDb(QString dbName)
{
    db.setHostName("localhost"); //设置数据库主机名
    db.setDatabaseName(dbName); //设置数据库名
    db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    query = new QSqlQuery(db);
   //    db.setUserName("root"); //设置数据库登入用户名
   //    db.setPassword("123456"); //设计数据库登入密码
    //打开数据库连接
    if(!db.open())
    {
        //QMessageBox::warning(this,"error",db.lastError().text());
        return false;
    }
    return true;
}

void ClientMes::closeDb()
{
    db.close();//释放数据库
}


