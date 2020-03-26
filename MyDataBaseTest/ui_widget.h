/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *dataBaseShow_Btn;
    QPushButton *dataBaseConnect_Btn;
    QPushButton *addDataBase_Btn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 300);
        dataBaseShow_Btn = new QPushButton(Widget);
        dataBaseShow_Btn->setObjectName(QStringLiteral("dataBaseShow_Btn"));
        dataBaseShow_Btn->setGeometry(QRect(60, 60, 75, 23));
        dataBaseConnect_Btn = new QPushButton(Widget);
        dataBaseConnect_Btn->setObjectName(QStringLiteral("dataBaseConnect_Btn"));
        dataBaseConnect_Btn->setGeometry(QRect(60, 110, 75, 23));
        addDataBase_Btn = new QPushButton(Widget);
        addDataBase_Btn->setObjectName(QStringLiteral("addDataBase_Btn"));
        addDataBase_Btn->setGeometry(QRect(60, 160, 75, 23));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        dataBaseShow_Btn->setText(QApplication::translate("Widget", "\346\224\257\346\214\201\347\261\273\345\236\213", Q_NULLPTR));
        dataBaseConnect_Btn->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\345\272\223\350\277\236\346\216\245", Q_NULLPTR));
        addDataBase_Btn->setText(QApplication::translate("Widget", "\346\267\273\345\212\240\346\225\260\346\215\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
