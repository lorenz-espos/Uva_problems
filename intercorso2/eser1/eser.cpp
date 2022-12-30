#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct m
{
    int num;
    int index;
};

void merge(m arr[], int p, int q, int r)
{

    // Crea le grandezze dei sottoarray L ← arr[p..q] and M ← arr[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    m L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Indici dei sotto array e dell'array principale
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // ordiniamo gli elementi di L e M fino alle estremità
    while (i < n1 && j < n2)
    {
        if (L[i].num <= M[j].num)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // al terminare degli elementi di uno dei due sotto array prendo tutti gli elementi dell'altro
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// divide l'array in due sottoarray, li ordina e ne fa il merge
void mergeSort(m arr[], int l, int r)
{
    if (l < r)
    {

        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
// trovo la più lunga sottosequenza passando la mia struct
int lcs(m a[], m b[], int n, int m)
{
    //matrice che conterrà la soluzione
    int L[n + 1][m + 1];
    // scorro sulle dimensioni degli array
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            // caso base
            if (i == 0 || j == 0)
            {
                L[i][j] = 0;
            }
            // lavoro ovviamente solo sugli indici
            else 
            if (a[i - 1].index == b[j - 1].index)
            {
                L[i][j] = L[i - 1][j - 1] + 1;
            }
            else
            {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }
    return L[n][m];
}

void algorithm(m A[], m B[], int a)
{
    // riordino le strutture per tenere traccia dell'indice
    mergeSort(A, 0, a - 1);
   mergeSort(B, 0, a - 1);
    // l'idea ora è di trovare la sottosequenza più lunga in comune tra le due strutture guardando gli indici
    /*
    testcase1: [4] [3] [2] [1]
                [1] [2] [4] [3]
                unisco 4 con 4 e 3 con 3 e ottengo 2
    */
    cout << lcs(A, B, a, a) << endl;
}

int main()
{
    int n = 0;
    cin >> n;
    while (n--)
    {
        int a = 0;
        cin >> a;
        struct m A[a];
        struct m B[a];
        for (int i = 0; i < a; i++)
        {
            cin >> A[i].num;
            A[i].index = i;
        }
        for (int i = 0; i < a; i++)
        {
            cin >> B[i].num;
            B[i].index = i;
        }
        algorithm(A, B, a);
    }
    return 0;
}

// la complessità è O(n^2+nlogn) quindi sarà O(n^2) a causa dell approccio bottom up che ho impiegato nella dp
