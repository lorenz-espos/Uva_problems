#include <iostream>
#include <algorithm>
using namespace std;

void merge(int *, int, int, int, int);
// funzione che riempie il vettore di zeri
void clear_vector(int A[], int dim)
{
    for (int i = 0; i < dim; i++)
        A[i] = 0;
}
// funzione che stampa il vettore
void print_vector(int A[], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        cout << A[i] << endl;
    }
}
// funzione per l'ordinamento del vettore in O(nlogn)
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

int lineary_search(int A[], int dim,int value)
{
    for (int i = 0; i < dim; i++)
    {
       if(A[i]==value){
        return i;
       }
    }
    return -1;
}

void algorithm(int A[],int dim,int value)
{
merge_sort(A,0,dim,dim);
print_vector(A,dim);
int a=lineary_search(A,dim,value);
cout<<"output:"<< endl;
if(a!=-1)
cout<<value<< " found at "<<a+1<<endl;
else
cout<<value<<" not found"<<endl;
}


void test_case_1()
{
    int dim = 4;
    int dim2=1;
    int B[dim2];
    int A[dim];
    A[0] = 2;
    A[1] = 3;
    A[2] = 5;
    A[3] = 1;
    B[0]=5;
    print_vector(A, dim);
    for(int i=0;i<dim2;i++){
    algorithm(A,dim,B[i]);
    }

   
}

void test_case_2()
{
    int dim = 5;
    int dim2=2;
    int B[dim2];
    int A[dim];
    A[0] = 1;
    A[1] = 3;
    A[2] = 3;
    A[3] = 3;
    A[4]=1;
    B[0]=2;
    B[1]=3;
    print_vector(A, dim);
    for(int i=0;i<dim2;i++){
    algorithm(A,dim,B[i]);
    }

   
}


int main()
{
    cout << "AVVIO IL TESTCASE 1" << endl;
    test_case_1();
    cout << "AVVIO IL TESTCASE 2" << endl;
    test_case_2();
    
   
    return 0;
}