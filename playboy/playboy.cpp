#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//binary search for first smaller element
int binarySearch(int array[], int elem, int low, int high)
{
    int ris=-1;
    // ripete finchè low e high non si toccano
    while (low <= high)
    {
        // mid è il mio pivot
        int mid = low + (high - low) / 2;

        if (array[mid] < elem)
        {   ris=array[mid];
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return ris;
}

//binary search for first bigger element
int binarySearch2(int array[], int elem, int low, int high)
{
    int ris=-1;
    // ripete finchè low e high non si toccano
    while (low <= high)
    {
        // mid è il mio pivot
        int mid = low + (high - low) / 2;

        if (array[mid] > elem)
        {   ris=array[mid];
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return ris;
}


void algorithm(int A[],int dim,int B[],int dim2){
for(int i=0;i<dim2;i++){
    int ris=binarySearch(A,B[i],0,dim-1);
    int ris2=binarySearch2(A,B[i],0,dim-1);
    if(ris==-1){
    cout<<"X"<<" "<<ris2<<endl;
    }
    if(ris2==-1){
    cout<<ris<<" "<<"X"<<endl;
    }
    if(ris!=-1 && ris2!=-1){
          cout<<ris<<" "<<ris2<<endl;
  
    }
}
}

int main(){
    int a=0;
    int b=0;
cin>>a;
int A[a];
for(int i=0;i<a;i++){
    cin>>A[i];
}
cin>>b;
int B[b];
for(int i=0;i<b;i++){
    cin>>B[i];
}
algorithm(A,a,B,b);
    return 0;
}