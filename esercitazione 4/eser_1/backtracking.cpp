#include <iostream>
#include <algorithm>
#include "math.h"
#define M 3
#define N 2
#define T 4

using namespace std;
void print_matrix(int n, int m, int mat[][M])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << mat[i][j];
        }
        cout << endl;
    }
}

void print_array(int A[], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        cout << A[i];
    }
            cout << endl;

}

bool is_safe(int i, int j, int n, int m)
{
    // verifica se sono fuori dalla matrice
    if (i > N - 1)
    {
        cout << "fuori massimo n, la i vale: " << i << "\n";
        return false;
    }
    if (j > M - 1)
    {
        cout << "fuori massimo m, la j vale: " << j << "\n";
        return false;
    }
    cout << "è safe: i e j valgono:" << i << " " << j << "\n";

    return true;
}

bool algorithm(int A[][M], int B[], int n, int m, int i, int j, int h)
{

    // righe i
    // colonne j

    B[h] = A[i][j];
    if (A[i][j] == A[n - 1][m - 1])
    {
        // cout<<"L'ultimo valore deve essere 6 = "<<A[i][j]<<endl;
        // cout<<"Print finale"<<endl;

        print_array(B, h + 1);
        // cout<<"h è "<<h<<endl;
    }

    for (int a = 0; a < 2; a++)
    {

        if (a == 0)
        {
            j++;
            h++;

            // colonna affianco
        }
        else if (a == 1)
        {
            i++;
            h++;

            // riga sotto
        }
        if (is_safe(i, j, n, m) == true)
        {
            if (algorithm(A, B, n, m, i, j, h) == true)
            {
                return true;
            }
        }

        // step di rollback
        if (a == 0)
        {
            j--;
            h--;
        }
        else if (a == 1)
        {
            i--;
            h--;
        }
    }
    return false;
}

void testcase1()
{
    // row n
    // columns m
    int n = 2;
    int m = 3;
    int i = 0;
    int j = 0;
    int h = 0;
    int A[N][M];
    int B[T];

    A[0][0] = 1;
    A[0][1] = 2;
    A[0][2] = 3;
    A[1][0] = 4;
    A[1][1] = 5;
    A[1][2] = 6;
    print_matrix(n, m, A);
    algorithm(A, B, n, m, i, j, h);
}
int main()
{
    testcase1();
    return 0;
}