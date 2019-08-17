#include "ter.h"
#include "ui_ter.h"
#include <iostream>
#include <cmath>
using namespace std;


char terr(double h,double o,double n)
{


 //   cout << "first enter the proportion of H2" << endl;
//   cin>>h;
 //   cout << "then the proportion of O2" << endl;
//    cin>>o;
//    cout << "at last enter the proportion of N2" << endl;
//    cin>>n;
    while(fabs(h+n+o-1)>0.000001)
    {
        cout << "wrong composition" << endl;
        return 'w';
        /*
        cout << "please retype" << endl;
        cout << "enter the proportion of H2 again" << endl;
        cin>>h;
        cout << "the proportion of O2 again" << endl;
        cin>>o;
        cout << "the proportion of N2 again" << endl;
        cin>>n;
        */
    }

    if(h<0.04||o<0.06)
    {
        cout<<"safe"<<endl;
        return 's';
    }else{
        cout<<"explosive"<<endl;
        return 'e';
    }

}
ter::ter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ter)
{
    ui->setupUi(this);
    setFixedSize(600,300);
    setWindowTitle("mao");
}

ter::~ter()
{
    delete ui;
}

void ter::on_ter_check_clicked()
{
    char b=terr(ui->h2->text().toDouble(),ui->o2->text().toDouble(),ui->n2->text().toDouble());
    if (b=='s')
    {ui->lineEdit_4->setText("safe");}
    else if(b=='e'){ui->lineEdit_4->setText("explosive");}
    else{ui->lineEdit_4->setText("wrong composition!");}
}
