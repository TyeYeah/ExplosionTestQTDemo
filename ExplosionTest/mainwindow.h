#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_maobt_clicked();

    void on_lebt_clicked();

    void on_terbt_clicked();

    void on_kubt_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
