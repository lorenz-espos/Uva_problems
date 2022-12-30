#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print_vector(int  v[], int n) {
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
/*
//merge sort int 
void merge(int arr[], int p, int q, int r) {

  // Crea le grandezze dei sottoarray L ← arr[p..q] and M ← arr[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  //int L[n1], M[n2];
  int L[n1], M[n2];


  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Indici dei sotto array e dell'array principale
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  //ordiniamo gli elementi di L e M fino alle estremità
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  //al terminare degli elementi di uno dei due sotto array prendo tutti gli elementi dell'altro
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// divide l'array in due sottoarray, li ordina e ne fa il merge
void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}
*/


//algoritmo che scorre e cerca le occorrenze dell elemento x
int binarysearch(int arr[], int low, int high, int x)
{
    int result = 0;

    if ((low > high) || (low == high && arr[low] != x))
        return 0;

    if (low == high && arr[low] == x)
        return 1;

    result = binarysearch(arr, low, (low + high) / 2, x) + binarysearch(arr, 1 + (low + high) / 2,high, x);
    return result;
}
void algorithm(int v[], int dim, int elem)
{

    //ordino l'array con il merge sort O(nlogn)
    //mergeSort(v, 0, dim - 1);
    //print_vector(v, dim);
    //cerco con una ricerca binaria modificata il numero di occorrenze
    cout << binarysearch(v, 0, dim - 1, elem);
}

// input numero di test case numero di elementi poi elementi
void input()
{
    int a = 0;
    cin >> a;
    while (a)
    {
        int b = 0;
        int dim = 0;
        cin >> b;
        cin >> dim;
        int v[dim];
        for (int i = 0; i < dim; i++)
        {
            cin >> v[i];
        }
        algorithm(v, dim, b);
        a--;
    }
}

int main()
{
    input();
    return 0;
}
