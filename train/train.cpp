#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bubblesort( vector<int> &A,int &count){
for (int i=0; i<A.size();i++){
for(int j=i+1;j<A.size();j++){
    if( A[j]<A[i]){
swap(A[j],A[i]);
count++;
//cout<<"count: "<<count<<endl;
    }
}

}
}
void algorithm(vector<int> arr){
    int count=0;
bubblesort(arr,count);
cout<<"Optimal train swapping takes "<<count<<" swaps"<<endl;
}
void input(){
    int a=0;
    cin>>a;
    while(a){
        int b=0;
        cin>>b;
        vector<int> A(b);
        for(int i=0;i<b;i++){
            cin>>A[i];
        }
        algorithm(A);
        a--;
    }
}

int main(){
    input();

}