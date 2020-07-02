#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    List A();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()  //добавление
{
    A.Adding(ui->lineEdit_5->text().toInt(), ui->lineEdit_4->text().toInt(),ui->lineEdit->text(),ui->lineEdit_3->text(),A.endptr);
}

void MainWindow::on_pushButton_8_clicked()   //вывод файлом
{
    A.Output(ui->lineEdit_5->text().toInt());
}

void MainWindow::on_pushButton_9_clicked()       //ввод файлом
{
    A.Input();
}

void MainWindow::on_pushButton_7_clicked()       //поиск
{
    A.Find(ui->lineEdit_6->text().toInt());
}

void MainWindow::on_pushButton_10_clicked()        //вывод на экран
{
    ui->label_16->setText(QString::number(A.returnerEAN(A.freeptr)));
    ui->label_15->setText(QString::number(A.returnerPrice(A.freeptr)));
    ui->label_7->setText(A.returnerName(A.freeptr));
    ui->label_6->setText(A.returnerManufacter(A.freeptr));
}

void MainWindow::on_pushButton_clicked()  //удаление
{
   ui->label_17->setText( A.Deletion(ui->lineEdit_6->text().toInt()));
}



void MainWindow::on_pushButton_3_clicked()  //изменения в штрих коде
{
    A.CorrcetEAN(A.freeptr,ui->lineEdit_9->text().toInt());
}

void MainWindow::on_pushButton_4_clicked()   // изменения в цене
{
    A.CorrcetPrice(A.freeptr, ui->lineEdit_7->text().toInt());
}

void MainWindow::on_pushButton_5_clicked()   // изменения в имени
{
    A.CorrcetName(A.freeptr, ui->lineEdit_2->text());
}


void MainWindow::on_pushButton_6_clicked()   //   изменения производителя
{
    A.CorrcetManufacter(A.freeptr, ui->lineEdit_8->text());
}
