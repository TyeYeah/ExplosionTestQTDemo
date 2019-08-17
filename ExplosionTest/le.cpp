#include "le.h"
#include "ui_le.h"
#include <iostream>

using namespace std;

class range     //a class to set every ratio's limit range and check it
{
public:
    double up,down;
    range(double ddown=0.0,double uup=0.0)
    {
        up=uup;
        down=ddown;
    }
    bool check(double val)//return true  if val is in the limit range; return false if not
    {
        return true?(val>=down&&val<=up):false;
    }

};


bool le_chart(double rat,double val)
{
    range* data1=new range(4,72);
    range* data2=new range(6,73);
    range* data3=new range(8,74);
    range* data4=new range(10,75);
    range* data5=new range(12,75);
    range* data6=new range(15,74);
    range* data7=new range(16,76);
    range* data8=new range(20,76);
    range* data9=new range(22,76);
    range* data10=new range(24,76);
    range* data11=new range(26,76);
    range* data12=new range(28,76);
    range* data13=new range(30,76);
    range* data14=new range(32,76);
    range* data15=new range(35,76);
    range* data16=new range(37,76);
    range* data17=new range(40,76);
    range* data18=new range(42,76);
    range* data19=new range(44,76);
    range* data20=new range(46,76);
    range* data21=new range(48,76);
    range* data22=new range(51,76);
    range* data23=new range(52,76);
    range* data24=new range(55,76);
    range* data25=new range(56,76);
    range* data26=new range(59,76);
    range* data27=new range(61,76);
    range* data28=new range(64,76);
    range* data29=new range(66,76);
    range* data30=new range(68,76);
    range* data31=new range(70,76);
    range* data32=new range(72,76);
    range* data33=new range(74,76);
    range* data34=new range(76,76);
    //use 34 to cover the limit of  17 and every half
    range* s[34]= {data1,data2,data3,data4,data5,data6,data7,data8,data9,data10,
                   data11,data12,data13,data14,data15,data16,data17,data18,data19,data20,
                   data21,data22,data23,data24,data25,data26,data27,data28,data29,data30,
                   data31,data32,data33,data34
                  };

    range* lim;
    //cout<<"input the ratio and the value"<<endl;
    //cin>>rat>>val;
    lim=s[(int)rat*2];//match the rat with every ratio's index
    if(lim->check(val))
    {
        // cout<<"explosive"<<endl;
        return 1;
    }
    else
    {
        //cout<<"safe"<<endl;
        return 0;
    }
}



le::le(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::le)
{
    ui->setupUi(this);
    setFixedSize(600,300);
    setWindowTitle("le chart");
}

le::~le()
{
    delete ui;
}

void le::on_le_check_clicked()
{
    bool b=le_chart(ui->rat->text().toDouble(),ui->val->text().toDouble());
    if (b==0)
    {ui->lineEdit_3->setText("safe");}else{ui->lineEdit_3->setText("explosive");}
}
