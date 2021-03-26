#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <QDir>
#include <QIODevice>
#include <QSettings>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->spinBox->value();
    QFile *logged_value();
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(write_to_file()));
    read_from_file();
}

MainWindow::~MainWindow()
{
    write_to_file();

    delete ui;
    qDebug() << "güle güleee";
}


//void MainWindow::on_spinBox_editingFinished()
//{

//    QDir dir(path);
//    if(!dir.exists()) {
//        QDir().mkdir(path);
//    }
//    logged_value() = new QFile(path);
//    logged_value()->open(QIODevice::ReadWrite | QIODevice::Text);
//    QTextStream out(logged_value());
//    out << QString::number(ui->spinBox->value())<<endl;
//    qDebug() << "iii";
//}

void MainWindow::write_to_file(void){
    QSettings my_file("/home/ahmet/Desktop/recordings.ini",QSettings::IniFormat);

    my_file.setValue("SILA",ui->spinBox->value());
    my_file.sync();
    qDebug() << "geldi";
}
void MainWindow::read_from_file(void){
    QSettings my_file("/home/ahmet/Desktop/recordings.ini",QSettings::IniFormat);

    ui->spinBox->setValue(my_file.value("SILA").toInt());
}

void MainWindow::on_pushButton_clicked()
{
        QString path = QFileDialog::getExistingDirectory(this, tr("Choose catalog"), ".", QFileDialog::ReadOnly);
}
