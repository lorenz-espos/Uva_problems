#include <iostream>
#include <algorithm>
#define N1 10
#define N2 1
#define N3 4
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
int binarySearch(int array[], int elem, int low, int high)
{
    // ripete finchè low e high non si toccano
    while (low <= high)
    {
        // mid è il mio pivot
        int mid = low + (high - low) / 2;

        if (array[mid] == elem)
            return mid;

        if (array[mid] < elem)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}
// funzione di ricerca lineare che trova le occorrenze su un vettore già ordinato
void find_occurences(int A[], int B[], int dim)
{
    int occ = 0;
    for (int i = dim; i >= 0; i--)
    {
        if (A[i] == A[i - 1] && i > -1)
        {
            occ++;
            B[i] = occ;
        }
        else
        {
            occ = 0;
            B[i] = occ;
        }
    }
}

void algorithm(int A[], int B[], int C[], int D[], int dim)
{
    int a = 0;
    // L'array A è l'array originale
    // L'array B sarà impiegato per contenere le soluzioni dell'algoritmo
    // L'array C è una copia dell'array A su cui effettuare l'ordinamento
    // chiamo merge sort per riordinare l'array
    merge_sort(C, 0, dim - 1, dim);
    cout << "stampo C dopo il merge sort" << endl;
    print_vector(C, dim);
    cout << "stampo il vettore delle occorrenze" << endl;
    find_occurences(C, D, dim);
    print_vector(D, dim);
    for (int i = 0; i < dim; i++)
    {
        a = binarySearch(C, A[i], 0, dim);
        B[i] = a + D[a + 1];
    }
    cout << "stampo B" << endl;
    print_vector(B, dim);
}
void test_case_1()
{
    int dim = N1;
    int A[dim];
    int B[dim];
    int C[dim];
    int D[dim];
    A[0] = 4;
    A[1] = 67;
    A[2] = 66;
    A[3] = 10;
    A[4] = 1;
    A[5] = 4;
    A[6] = 11;
    A[7] = 3;
    A[8] = 43;
    A[9] = 32;
    print_vector(A, dim);
    copy(A, dim + A, C);
    algorithm(A, B, C, D, dim);
}

void test_case_2()
{
    int dim = N1;
    int A[dim];
    int B[dim];
    int C[dim];
    int D[dim];
    A[0] = 4;
    A[1] = 67;
    A[2] = 66;
    A[3] = 10;
    A[4] = 1;
    A[5] = 2;
    A[6] = 11;
    A[7] = 3;
    A[8] = 43;
    A[9] = 32;
    print_vector(A, dim);
    copy(A, dim + A, C);
    algorithm(A, B, C, D, dim);
}

void test_case_3()
{
    int dim = N1;
    int A[dim];
    int B[dim];
    int C[dim];
    int D[dim];
    A[0] = 4;
    A[1] = 4;
    A[2] = 4;
    A[3] = 10;
    A[4] = 1;
    A[5] = 2;
    A[6] = 11;
    A[7] = 3;
    A[8] = 43;
    A[9] = 32;
    print_vector(A, dim);
    copy(A, dim + A, C);
    algorithm(A, B, C, D, dim);
}

void test_case_4()
{
    int dim = N3;
    int A[dim];
    int B[dim];
    int C[dim];
    int D[dim];
    A[0] = 4;
    A[1] = 4;
    A[2] = 2;
    A[3] = 2;
    print_vector(A, dim);
    copy(A, dim + A, C);
    algorithm(A, B, C, D, dim);
}
void test_case_5()
{
    int dim = N3;
    int A[dim];
    int B[dim];
    int C[dim];
    int D[dim];
    A[0] = 4;
    A[1] = 4;
    A[2] = 4;
    A[3] = 4;
    print_vector(A, dim);
    copy(A, dim + A, C);
    algorithm(A, B, C, D, dim);
}
int main()
{
    cout << "AVVIO IL TESTCASE 1" << endl;
    test_case_1();
    cout << "AVVIO IL TESTCASE 2" << endl;
    test_case_2();
    cout << "AVVIO IL TESTCASE 3" << endl;
    test_case_3();
    cout << "AVVIO IL TESTCASE 4" << endl;
    test_case_4();
    cout << "AVVIO IL TESTCASE 5" << endl;
    test_case_5();
    return 0;
}