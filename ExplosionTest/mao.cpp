#include "mao.h"
#include "ui_mao.h"

bool maoo(double x,double y,double z,double o2)
{

//	cout<< "enter the CH4's percentage" << endl;
//	cin>>x;
//	cout<< "enter the H2's percentage" << endl;
//	cin>>y;
//	cout<< "enter the CO's percentage" << endl;
//	cin>>z;
//	cout<< "enter the O2's percentage" << endl;
//	cin>>o2;
double r=x/(x+y+z);
double mao=5.0+7.0*r;

if(mao>o2)
{
//cout<<"safe"<<endl;
    return 0;
}else
{
//cout<<"boom"<<endl;
    return 1;
}
}

mao::mao(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mao)
{
    ui->setupUi(this);

    setFixedSize(600,300);
    setWindowTitle("mao");
}

mao::~mao()
{
    delete ui;
}

void mao::on_mao_check_clicked()
{
    bool b=maoo(ui->ch4->text().toDouble(),ui->h2->text().toDouble(),ui->co->text().toDouble(),ui->o2->text().toDouble());
    if (b==0)
    {ui->lineEdit_5->setText("safe");}else{ui->lineEdit_5->setText("explosive");}
}
