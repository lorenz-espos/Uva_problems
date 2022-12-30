#include <iostream>
#include <algorithm>
using namespace std;
//APPROCCIO BOTTOM-UP
int algorithm(int num){
    //struttura dati
    int DP[num+1];
    for(int i=0;i<num+1;i++)
    if(i<=2){
        //caso base 
        DP[i]=i;
    }
    else
    DP[i]=DP[i-1]+(i-1)*DP[i-2];

    return DP[num];
}

void testcase1(){
   cout<<algorithm(3)<<endl;
}

void testcase2(){
   cout<<algorithm(4)<<endl;
}
void testcase3(){
   cout<<algorithm(1)<<endl;
}
int main(){
cout<<"AVVIO TESTCASE 1"<<endl;
testcase1();
//output previsto 4
cout<<"AVVIO TESTCASE 2"<<endl;
testcase2();
//output previsto 10
cout<<"AVVIO TESTCASE 3"<<endl;
//output previsto 1
testcase3();
//caso base 


return 0;
}
