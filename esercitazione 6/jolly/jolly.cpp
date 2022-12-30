#include <iostream>
#include <algorithm>
#include "math.h"
#include <vector>
using namespace std;

// la complessità dell algoritmo è O(2n-1)==O(n)

void algorithm(int A[], int dim)
{
    if (dim == 0)
    {
        cout << "OUTPUT: Jolly" << endl;
        return;
    }
    int B[dim - 1];
    for (int i = 0; i < dim; i++)
    {
        // vettore B delle differenze in modulo
        B[i] = abs(A[i] - A[i + 1]);
       // cout << "B[" << i << "] " << B[i] << endl;
    }
    int count = 1;
    for (int i = 0; i < dim - 1; i++)
    {
        // verifico se vale la sequenza jolly con una variabile counter
        if (B[i] == B[i + 1] + 1)
        {
            count++;
        }
    }
//    cout << count << endl;
    // stampo la soluzione
    if (count == dim)
    {
        cout << "OUTPUT: Jolly" << endl;
    }
    else
    {
        cout << "OUTPUT: Not Jolly" << endl;
    }
}
void input()
{
    int a = 0;
    while (1)
    {
        cout<<"INPUT: ";
        cin >> a;
        int A[a];
        for (int i = 0; i < a; i++)
            cin >> A[i];
        algorithm(A, a - 1);
    }
}
int main()
{
    input();

    return 0;
}