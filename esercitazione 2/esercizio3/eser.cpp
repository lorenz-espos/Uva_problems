#include <iostream>
#include "math.h"
#include <cmath>


using namespace std;
void solve(double p,double q,double r, double s,double t,double u){
   if((p>=0) && (r<=20) && (q>=-20) && (s<=0) && (t<=0)){
    //check del dominio dell'equazione
        cout<<"l'input non viola il dominio "<<endl;
         double y=1;
         double x=0;
        while (y!=0 && x<1){
        y=((p*exp(x))+(q*cos(x))+(s*tan(x))+(t*x*x)+u);
        //equazione da risolvere in cui sostituisco i termini
        float n=ceil(y*100)/100;
        //funzione per abbassare le cifre decimali che vedo della y
        x+=0.0001;
        //faccio avanzare x fino alla quarta cifra decimale
        if(n==0){
     cout<<"x è "<<x<<endl;
     //caso in cui l'equazione ha soluzione nel dominio
     break;
    }
    if(x>=1 && n!=0){
        cout<<"nessuna soluzione nel dominio"<<endl;
    }
    }
    

    }
    else{
        cout<<"dominio violato"<<endl;
    }

}

int main(){
    double p=0;
    double q=0;
    double r=0;
    double s=0;
    double t=-2;
    double u=1;
cout<<"starting first case"<<endl;
solve(p,q,r,s,t,u);
cout<<"starting second case"<<endl;
    p=0;
    q=1;
    r=0;
    s=0;
    t=-1;
    u=2;  
solve(p,q,r,s,t,u);
  
    return 0;
}