#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffe->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbColor->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    money+=diff;
    ui->lcdNumber->display(money);
    ui->pbCoffe->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 200);
    ui->pbColor->setEnabled(money >= 200);
}

void Widget::on_pb10_clicked(){
   changeMoney(10);
}

void Widget::on_pb50_clicked(){
   changeMoney(50);
}

void Widget::on_pb100_clicked(){
   changeMoney(100);
}

void Widget::on_pb500_clicked(){
   changeMoney(500);
}

void Widget::on_pbCoffe_clicked(){
   changeMoney(-100);
}

void Widget::on_pbTea_clicked(){
   changeMoney(-200);
}

void Widget::on_pbColor_clicked(){
   changeMoney(-200);
}

void Widget::on_pb_Rejct_clicked(){
   int numOf500 = money / 500;
   int remainingMoney500 = money % 500;
   int numOf100 = remainingMoney500 / 100;
   int remainingMoney100 = remainingMoney500 % 100;

   QMessageBox mb;
   QString message = QString("500원: %1 개\n100원: %2 개\n잔액: %3 원").arg(numOf500).arg(numOf100).arg(remainingMoney100);
   mb.information(this, "잔돈 정보", message);

}


