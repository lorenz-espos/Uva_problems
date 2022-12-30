#include <iostream>
#include <algorithm>

using namespace std;

#define N 5

void print_stack(int A[],int low,int top){
    for(int i=low;i<top;i++){
        cout<<A[i]<<endl;
    }
}
void stack_reverse(int A[],int low, int top){
reverse(A,A+(top));
}

int max_index(int A[], int low, int top){
    int index=0;
 for(int i=low;i<top;i++){
    if(A[i]>A[index]){
        index=i;
    }
 }   
 return index;
}

void pancake_sort(int A[], int dim){
    int max=0;
    int low=0;
    while(dim>1){
    max=max_index(A,low,dim);
    if(A[max]!=A[dim-1]){
    cout<<" Flip at "<<max+1<<endl;
    stack_reverse(A,low,max);
    cout<<" Flip at "<<dim<<endl;
    stack_reverse(A,low, dim);
    }
    dim--;
    
        
    }

}

void testcase1(){
int A[N];
A[0]=1;
A[1]=2;
A[2]=3;
A[3]=4;
A[4]=5;
print_stack(A,0,N);
cout<<"Avvio pancake sort"<<endl;
pancake_sort(A,N);
print_stack(A,0,N);
}
void testcase2(){
int A[N];
A[0]=5;
A[1]=4;
A[2]=3;
A[3]=2;
A[4]=1;
print_stack(A,0,N);
pancake_sort(A,N);
cout<<"Avvio pancake sort"<<endl;
print_stack(A,0,N);

}

void testcase3(){
int A[N];
A[0]=4;
A[1]=3;
A[2]=2;
A[3]=1;
A[4]=5;
print_stack(A,0,N);
pancake_sort(A,N);
cout<<"Avvio pancake sort"<<endl;
print_stack(A,0,N);

}
int main(){
cout<<"Avvio testcase 1"<<endl;
testcase1();
cout<<"Avvio testcase 2"<<endl;
testcase2();
cout<<"Avvio testcase 3"<<endl;
testcase3();
    return 0;
}