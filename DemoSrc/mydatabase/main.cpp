#include <QCoreApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QStringList>
#include "connection.h"
#include <QSqlRecord>
#include <QSqlField>
#include <QSqlDriver>
#include <QSqlError>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if (!createConnection()) return 1;

    QSqlDatabase db1 = QSqlDatabase::database("connection1");
    QSqlQuery query(db1);
    qDebug() << "connection1:";
    query.exec("select * from student");
    while(query.next())
    {
        qDebug() << query.value(0).toInt() << query.value(1).toString();
    }

    QSqlDatabase db2 = QSqlDatabase::database("connection2");
    QSqlQuery query2(db2);
    qDebug() << "connection2:";
    query2.exec("select * from student");
    while(query2.next())
    {
        qDebug() << query2.value(0).toInt() << query2.value(1).toString();
    }

    int numRows;

    // 先判断该数据库驱动是否支持QuerySize特性，如果支持，则可以使用size()函数，
    // 如果不支持，那么就使用其他方法来获取总行数
    if (db2.driver()->hasFeature(QSqlDriver::QuerySize)) {
        qDebug() << "has feature: query size";
        numRows = query2.size();
    } else {
        qDebug() << "no feature: query size";
        query2.last();
        numRows = query2.at() + 1;
    }
    qDebug() << "row number: " << numRows;


    // 指向索引为1的记录，即第二条记录
    query2.seek(1);

    // 返回当前索引值
    qDebug() << "current index: " << query2.at();

    // 获取当前行的记录
    QSqlRecord record = query2.record();

    // 获取记录中“id”和“name”两个字段的值
    int id = record.value("id").toInt();
    QString name = record.value("name").toString();
    qDebug() << "id: " << id << "name: " << name;

    // 获取索引为1的字段，即第二个字段
    QSqlField field = record.field(1);

    // 输出字段名和字段值，结果为“name”和“MaLiang”
    qDebug() << "second field: " << field.name()
                << "field value: " << field.value().toString();

    query2.exec("insert into student (id, name) values (100, 'ChenYun')");
    qDebug() << "connection2-----insert1:";
    query2.exec("select * from student");
    while(query2.next())
    {
        qDebug() << query2.value(0).toInt() << query2.value(1).toString();
    }

    query2.prepare("insert into student (id, name) values (:id, :name)");
    int idValue = 101;
    QString nameValue = "ChenYun1";
    query2.bindValue(":id", idValue);
    query2.bindValue(":name", nameValue);
    query2.exec();
    qDebug() << "connection2-----insert2:";
    query2.exec("select * from student");
    while(query2.next())
    {
        qDebug() << query2.value(0).toInt() << query2.value(1).toString();
    }

    query2.prepare("insert into student (id, name) values (?, ?)");
    int idValue1 = 102;
    QString nameValue1 = "ChenYun2";
    query2.addBindValue(idValue1);
    query2.addBindValue(nameValue1);
    query2.exec();
    qDebug() << "connection2-----insert3:";
    query2.exec("select * from student");
    while(query2.next())
    {
        qDebug() << query2.value(0).toInt() << query2.value(1).toString();
    }

    query2.prepare("insert into student (id, name) values (?, ?)");
    QVariantList ids;
    ids << 20 << 21 << 22;
    query2.addBindValue(ids);
    QVariantList names;
    names << "xiaoming" << "xiaoliang" << "xiaogang";
    query2.addBindValue(names);
    if(!query2.execBatch()) qDebug() << query2.lastError();
    qDebug() << "connection2-----insert4:";
    query2.exec("select * from student");
    while(query2.next())
    {
        qDebug() << query2.value(0).toInt() << query2.value(1).toString();
    }

    // 更新
    query2.exec("update student set name = 'xiaohong' where id = 20");
    // 删除
    query2.exec("delete from student where id = 21");

    qDebug() << "connection2-----update:";
    query2.exec("select * from student");
    while(query2.next())
    {
        qDebug() << query2.value(0).toInt() << query2.value(1).toString();
    }

    return a.exec();
}
