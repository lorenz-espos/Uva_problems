#include <iostream>
#include <algorithm>
using namespace std;
void algorithm(int A[][3],int num_of_cases){
    cout<<endl;
for(int i=0;i<num_of_cases;i++){
if(A[i][0]+A[i][1]==A[i][2]||A[i][0]==A[i][1]+A[i][2]||A[i][0]+A[i][2]==A[i][1])
cout<<"YES"<<endl;
else
cout<<"NO"<<endl;
}
}
void input(){
int num_of_cases=0;
cin>>num_of_cases;
int A[num_of_cases][3];
for(int i=0;i<num_of_cases;i++){
    for(int j=0;j<3;j++){
    cin>>A[i][j];
    }
}
    algorithm(A,num_of_cases);
}
int main(){

input();

    return 0;
}