#include <iostream>
#include "math.h"
using namespace std;
// la funzione di merge serve a dividere il vettore per effettuare il mergesort
void merge(int *array, int low, int high, int mid, int dim)
{
    int i, j, k, c[dim];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (array[i] < array[j])
        {
            c[k] = array[i];
            k++;
            i++;
        }
        else
        {
            c[k] = array[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = array[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = array[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        array[i] = c[i];
    }
}
void merge_sort(int *array, int low, int high, int dim)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        // divido a metà l'array e chiamo merge sort sulla prima metà
        merge_sort(array, low, mid, dim / 2);
        merge_sort(array, mid + 1, high, dim / 2);
        // chiamo merge sort sulla seconda metà
        merge(array, low, high, mid, dim);
    }
}
//complessità O(nlogn)
void algorithm(int A[],int dim){
    //ordino l'array con complessità O(nlogn)
    merge_sort(A,0,dim-1,dim);
    //trovo la mediana
    int mediana=A[dim/2];
    int somma=0;
    //complessità O(n)
    for(int i=0;i<dim;i++){
    //sommo tutte le differenze tra la mediana e gli elmenti dell'array ordinato
       somma+= abs(mediana-A[i]);
        
    }
    cout<<somma<<endl;

}


//funzione di input
void input(){
int a=0;
int num=0;
cin>>a;
while(a){
int num=0;
cin>>num;
int A[num];
for(int i=0;i<num;i++)
cin>>A[i];

algorithm(A,num);

a--;

}


}
int main(){
input();
    return 0;
}