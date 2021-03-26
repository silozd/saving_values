#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDir>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QFile *logged_value();

private slots:
    //void on_spinBox_editingFinished();
    void read_from_file();
    void write_to_file();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
