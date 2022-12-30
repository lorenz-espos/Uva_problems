#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Rapporto_hmulta{
    double number;
    int position;
};

    void print_vector(Rapporto_hmulta A[], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        cout << A[i].position+1 << " ";
    }
}
void merge(Rapporto_hmulta arr[], int p, int q, int r) {

  // Crea le grandezze dei sottoarray L ← arr[p..q] and M ← arr[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  //double L[n1], M[n2];
  Rapporto_hmulta L[n1], M[n2];


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
    if (L[i].number <= M[j].number) {
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
void mergeSort(Rapporto_hmulta arr[], int l, int r) {
  if (l < r) {

    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}
void algorithm(Rapporto_hmulta A[],int num_jobs)
{
    //ordino la struct portandomi dietro gli indici 
    mergeSort(A,0,num_jobs-1);
    //stampo la soluzione
    print_vector(A,num_jobs);
    

}
int main()
{
    int num_cases = 0;
    int num_jobs = 0;
    cin >> num_cases;
    while (num_cases)
    {
        int count = 0;
        cin >> num_jobs;
        double A[num_jobs];
        double B[num_jobs];
        Rapporto_hmulta C[num_jobs];

        while (count != num_jobs)
        {
            cin >> A[count];
            cin >> B[count];
          //  cout<<" A"<<A[count]<<" B"<<B[count]<<endl;
            C[count].number= double(A[count] / B[count]);
            C[count].position=count;
            count++;
        }
        cout<<endl;
      algorithm(C,num_jobs);

        num_cases--;
    }

    return 0;
}