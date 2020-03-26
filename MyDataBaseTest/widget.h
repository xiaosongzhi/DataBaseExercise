#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    
    void showDataBase();
    bool connectDataBase();

private slots:
    void on_dataBaseShow_Btn_clicked();

    void on_addDataBase_Btn_clicked();

    void on_dataBaseConnect_Btn_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
