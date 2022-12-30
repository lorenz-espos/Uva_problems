#include <iostream>
#include <algorithm>

using namespace std;

void bubblesort( int A[]){
    int count=0;
for (int i=0; i<5;i++){
for(int j=i+1;j<5;j++){
    if( A[j]<A[i]){
swap(A[j],A[i]);
count++;
cout<<"count: "<<count<<endl;
    }
}

}
}

void print( int A[]){
    for(int z=0;z<5;z++){
    cout<<A[z]<<endl;
 }
}

int main(){
int A [5];
int B [5];

A[0]=9;
A[1]=1;
A[2]=0;
A[3]=5;
A[4]=4;

B[0]=3;
B[1]=1;
B[2]=2;
B[3]=3;
B[4]=0;
 bubblesort(A);
 print(A);
 cout<<"Starting bubble sort on B"<<endl;
 bubblesort(B);
 print(B);

 
return 0;
}

