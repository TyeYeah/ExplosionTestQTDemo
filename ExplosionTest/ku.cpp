#include "ku.h"
#include "ui_ku.h"
#include <iostream>

using namespace std;
double getAlpha(double co2,double n2,double o2){
    //double alpha;

    return (co2-0.03)/(co2+n2-3.778*o2);
}
double getBeta(double o2, double pt, double ai, double bi, double alpha){

    return (20.93-(o2+0.2093*pt))/(ai-bi*alpha);
}

double getX(double ci[6],double di[6],double ei[6],double fi[6],double beta[6],double pi[6],double pt,double po2,double alpha){
    double X=0;
    int i = 0;
    while(i<6)
    {
    X+=(ci[i]+di[i]*pt+ei[i]*po2+alpha*beta[i]*fi[i])*pi[i]/pt;
    //cout<<ci[i]<<" "<<di[i]*pt<<" "<<ei[i]*po2<<" "<<alpha*beta[i]<<" "<<pi[i]<<" "<<pt<<" "<<(ci[i]+di[i]*pt+ei[i]*po2+alpha*beta[i]*fi[i])*pi[i]/pt<<endl;
    cout<<"turn "<<i<<" , X="<<X<<endl;
    i++;
    }
    return X;
}
double getY(double cii[6],double dii[6],double eii[6],double fii[6],double beta[6],double pi[6],double pt,double po2,double alpha){
    double Y=0;
    int i = 0;
    while(i<6)
    {
    Y+=(cii[i]+dii[i]*pt+eii[i]*po2+alpha*beta[i]*fii[i])*pi[i]/pt;
    i++;
    }
    return Y;
}
double f1(double x)
{
    double k = -10.41/0.18;
    double b = 19.88-5.00*k;

    return k*x+b;
}
double f2(double x)
{
    double k = 8.32/9.82;
    double b = 17.79-15.00*k;
    return k*x+b;
}
double f3(double x)
{
    double k = -0.209;
    double b = 19.88-5.00*k;
    return k*x+b;
}

bool kukuchika(double pco2,double pn2,double po2,double pi[6])
{

    cout<<"Please input the proportion of CO2:\n";
    //cin>>pco2;
    cout<<"Please input the proportion of N2:\n";
    //cin>>pn2;
    cout<<"Please input the proportion of O2:\n";
    //cin>>po2;


    //double pi[6]={0.3,0,0,0,0,0};//the order is: pch4, pc0, ph2, pc2h2, pc2h4, pc2h6
    cout<<"Please input the proportion of CH4:\n";
    //cin>>pi[0];
    cout<<"Please input the proportion of CO:\n";
    //cin>>pi[1];
    cout<<"Please input the proportion of H2:\n";
    //cin>>pi[2];
    cout<<"Please input the proportion of C2H2:\n";
    //cin>>pi[3];
    cout<<"Please input the proportion of C2H4:\n";
    //cin>>pi[4];
    cout<<"Please input the proportion of C2H6:\n";
    //cin>>pi[5];

    double ai[6]={10.376,13.039,14.918,15.308,14.269,11.872},bi[6]={3.016,3.396,3.533,3.577,3.526,2.909};
    double ci[6]={0,3.117,4.643,4.901,4.121,1.937},di[6]={1,0.167,0.14,0.127,0.385,1.052},ei[6]={0,-0.007,-0.01,-0.011,-0.009,-0.005},fi[6]={-0.78,-0.4,-0.107,-0.045,-0.216,-0.724};
    double cii[6]={0,3.622,5.401,5.719,4.849,2.233},dii[6]={0,0.133,0.116,0.115,0.072,-0.037},eii[6]={1,0.797,0.698,0.68,0.729,0.875},fii[6]={-2.852,-2.619,-2.435,-2.415,-2.519,-2.391};

    double alpha=getAlpha(pco2,pn2,po2);//get alpha
    cout<<"alpha="<<alpha<<endl;
    double pt=0;
    double beta[6];
    for(int i=0;i<6;i++)
    {pt+=pi[i];}//get pt
    cout<<"pt="<<pt<<endl;
    for(int i=0;i<6;i++)
    {
        beta[i]=getBeta(po2,pt,ai[i],bi[i],alpha);//get beta[i]
        if(beta[i]>1)beta[i]=1;
        cout<<"beta["<<i<<"]="<<beta[i]<<endl;
    }

    double X=getX(ci,di,ei,fi,beta,pi,pt,po2,alpha);
    cout<<"X="<<X<<endl;
    double Y=getY(cii,dii,eii,fii,beta,pi,pt,po2,alpha);
    cout<<"Y="<<Y<<endl;

    int flag=0;
    if(X>=5&&X<=15)
    {
        if(X<=5.18)
        {
            if(Y>=f1(X)&&Y<=f3(X))
            {
            flag=1;
            }
        }
        else
        {
            if(Y>=f2(X)&&Y<=f3(X))
            {
            flag=1;
            }
        }
    }
    cout<<"f1(x)="<<f1(X)<<", f2(x)="<<f2(X)<<", f3(x)="<<f3(X)<<endl;
    if(flag==1)
    {
    cout<<"boom"<<endl;
    }else {
    cout<<"peace"<<endl;
    }




}

ku::ku(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ku)
{
    ui->setupUi(this);
    setFixedSize(600,300);
    setWindowTitle("kukuchika");
}

ku::~ku()
{
    delete ui;
}

void ku::on_ku_check_clicked()
{
    double di[6]={ui->ch4->text().toDouble(),ui->co->text().toDouble(),ui->h2->text().toDouble(),ui->c2h2->text().toDouble(),ui->c2h4->text().toDouble(),ui->c2h6->text().toDouble()};
    bool b=kukuchika(ui->co2->text().toDouble(),ui->n2->text().toDouble(),ui->o2->text().toDouble(),di);
    if (b==0)
    {ui->result->setText("safe");}else{ui->result->setText("explosive");}
}
