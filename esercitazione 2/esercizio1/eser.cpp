#include <iostream>
using namespace std;
#define L 4
#include <algorithm>

void sum( int A []){
    //inizializzo la somma globale al minimo del tipo senno non funziona con tutti numeri negativi
    int sumg=INT_MIN;
    int suml=0;
    //somma locale nel caso misto
    int sumln=0;
    //somma locale nel caso di tutti negativi o tutti positivi
    for (int i=0;i<L;i++){
        //il for mi gira l'array
    suml+=A[i];
    sumln=suml;
    //somma locale si aggiorna e ha memoria del giro precedente del for la somma locale negativa cambia a ogni giro
    //effettuo la somma locale man mano che scorro l'array in avanti
if(suml<0){
    suml=0;
    //inizializzazione necessaria se ho numeri positivi nell'array
}
cout<<"la somma locale mista è "<<suml<<endl;
cout<<"la somma locale negativa o positiva è "<<sumln<<endl; 
if(sumg<sumln ){
    // se la somma locale negativa è maggiore della somma globale la nuova somma globale è la locale negativa
    sumg=sumln;
}
cout<<"la somma globale è "<<sumg<<endl;
}
}


int main(){
    int A[L];
    int B[L];
    int C[L];
    // first case test
    A[0]=-1;
    A[1]=-3;
    A[2]=4;
    A[3]=2;
    //second case test
    B[0]=-1;
    B[1]=2;
    B[2]=-5;
    B[3]=7;
    //third case test
    C[0]=-1;
    C[1]=-2;
    C[2]=-5;
    C[3]=-7;
    

cout<<"start algorithm for array A"<<endl;
sum(A);
cout<<"start algorithm for array B"<< endl;
sum(B);
cout<<"start algorithm for array C"<< endl;
sum(C);


    return 0;
}