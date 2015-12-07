#include <fstream>

using namespace std;

void f(double* k, double* y,const double eta)
{
    k[0]=y[1];
    k[1]=(eta-y[0]*y[0])*y[0];  
    
    
}

int main(){
    const int N = 10000;;
    const double eta = 0.4;
    double step = 0.01;
    double y[N];
    double yabl[N];
    y[0]=0;
    yabl[0]=1e-5;
    double k1[2]; double k2[2]; double k3[3];
    double ytemp[2];
    
    
    for(int i=1;i<N;i++){
        
        ytemp[0]=y[i-1];
        ytemp[1]=yabl[i-1];
        f(k1,ytemp,eta);
        
        ytemp[0]=y[i-1]+step*.5*k1[0];
        ytemp[1]=yabl[i-1]+step*.5*k1[1];
        f(k2,ytemp,eta);
        
        ytemp[0]=y[i-1]+step*(-k1[0]+2*k2[0]);
        ytemp[1]=yabl[i-1]+step*(-k1[1]+2*k2[1]);
        f(k3,ytemp,eta);
        
        y[i]=y[i-1]+step/6*(k1[0]+4*k2[0]+k3[0]);
        yabl[i]=yabl[i-1]+step/6*(k1[1]+4*k2[1]+k3[1]);
    }
    
    
    ofstream out("Daten.txt");
    for(int i=0; i<N;i++)
        out << i*step << "\t" << y[i] << endl;
    out.close();
}
