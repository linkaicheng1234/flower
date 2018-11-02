#include "execlist.h"
#include <QDebug>
ExecList::ExecList(QString execPath)
{
    if(!execPath.isNull())
        openExec(execPath);
}

bool ExecList::openExec(QString execPath)
{
    this->execPath = execPath;
    excel = new QAxObject("Excel.Application");//连接Excel控件
    QAxObject *workbooks = excel->querySubObject("WorkBooks");//获取工作簿(excel文件)集合
    workbook = workbooks->querySubObject("Open(const QString&)", execPath);//打开一个已有的工作簿
    allWorkSheets = workbook->querySubObject("Sheets");//获取所有工作表


    //QAxObject *num = allWorkSheets->querySubObject("Sheets");
    int inum = allWorkSheets->property("Count").toInt();
    qDebug()<<inum<<"inum";

    curWorkSheet = allWorkSheets->querySubObject("Item(int)",1);//根据序号获取某个工作表

    QAxObject* usedrange = curWorkSheet->querySubObject("UsedRange");//sheet范围

    //获取所有内容
    QVariant var = usedrange->dynamicCall("Value");//这里是所有的内容
    castVariant2ListListVariant(var);

     //获取行列数
//    int intRowStart = usedrange->property("Row").toInt();//起始行数
//    int intColStart = usedrange->property("Column").toInt(); //起始列数
    QAxObject *rows, *columns;
    rows = usedrange->querySubObject("Rows");//行
    columns = usedrange->querySubObject("Columns");//列
    intRow = rows->property("Count").toInt();//行数
    intCol = columns->property("Count").toInt();//列数

//    for(int i = intRowStart;i<=intRow;i++)
//    {
//        for(int j = intColStart;j<=intCol;j++)
//        {
//            QAxObject* cell = curWorkSheet->querySubObject("Cells(int, int)", i,j);
//            QVariant cell_value = cell->property("Value");
//            qDebug()<<cell_value.toString()<<"  ";
//        }
//        qDebug("\n");
//    }
    return true;
}

void ExecList::closeExec()
{
    workbook->dynamicCall( "Close(Boolean)", false );
    excel->dynamicCall( "Quit(void)" );
    delete excel;
}

QVariant ExecList::readData(int row, int column)//,QList<QList<QVariant>> list)
{
    //if(list.isEmpty())
        return  execList.at(row).at(column);
    //return list.at(row).at(column);

}

void ExecList::writeData(int row, int column, QVariant data)//,QList<QList<QVariant>> list)
{
    execList.at(row).at(column).toString() = data.toString();
}


void ExecList::getrowcol(int &row, int &col)
{
    row = intRow;
    col = intCol;
}

void ExecList::showData()
{
    int row = execList.size();
    for(int i = 0;i<row;i++)
    {
        int col = execList.at(i).size();
        for(int j = 0;j<col;j++)
        {
            qDebug()<<execList.at(i).at(j)<<"   ";
        }
        qDebug("\n");
    }
}

QList<QList<QVariant>> ExecList::getList()
{
    return execList;
}

void ExecList::castVariant2ListListVariant(const QVariant &var)
{
    QVariantList varRows = var.toList();
    if(varRows.isEmpty())
    {
        return;
    }
    const int rowCount = varRows.size();
    QVariantList rowData;
    for(int i=0;i<rowCount;++i)
    {
        rowData = varRows[i].toList();
        execList.push_back(rowData);
    }
}

