#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QStringList>
#include <QSqlQuery>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showDataBase()
{
    QStringList drivers = QSqlDatabase::drivers();
//    qDebug()<<drivers;
    QList<QString>::iterator it;
    for(it = drivers.begin();it != drivers.end();it++)
    {
        qDebug()<<*it;
    }
}
bool Widget::connectDataBase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("myselfDataBase");

    if(!db.open())
    {
        return false;
    }
    else
    {
        qDebug()<<"success";
        return true;
    }

}

void Widget::on_dataBaseShow_Btn_clicked()
{
    showDataBase();
}

void Widget::on_addDataBase_Btn_clicked()
{

}

void Widget::on_dataBaseConnect_Btn_clicked()
{
    connectDataBase();
}
