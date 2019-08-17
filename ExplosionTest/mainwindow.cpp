#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mao.h"
#include "ter.h"
#include "le.h"
#include "ku.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_maobt_clicked()
{
    mao* m=new mao();
    m->show();
}

void MainWindow::on_lebt_clicked()
{
    le* ll=new le();
    ll->show();
}

void MainWindow::on_terbt_clicked()
{
    ter* tt=new ter();
    tt->show();
}

void MainWindow::on_kubt_clicked()
{
    ku* kk=new ku();
    kk->show();
}
