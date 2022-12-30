#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print_vector(vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << endl;
    }
}
void MergeSortVector(vector<int> &v, int low, int m, int high, int &count)
{

    vector<int> temp;

    int i, j;
    i = low;
    j = m + 1;

    while (i <= m && j <= high)
    {

        if (v[i] <= v[j])
        {
            temp.push_back(v[i]);
            ++i;
        }
        else
        {
            temp.push_back(v[j]);
            ++j;
            count = count + (m-low-1);
        }
    }

    while (i <= m)
    {
        temp.push_back(v[i]);
        ++i;
    }

    while (j <= high)
    {
        temp.push_back(v[j]);
        ++j;
    }

    for (int i = low; i <= high; ++i)
        v[i] = temp[i - low];
}

// funzione per l'ordinamento del vettore in O(nlogn)
void MergeSort(vector<int> &v, int low, int high, int &count)
{
    if (low < high)
    {
        int m = (low + high) / 2;
        // divido a metà l'array e chiamo merge sort sulla prima metà
        MergeSort(v, low, m, count);
        // chiamo merge sort sulla seconda metà
        MergeSort(v, m + 1, high, count);
        MergeSortVector(v, low, m, high, count);
    }
}

void algorithm(vector<int> A)
{
    cout << "sono il merge sort" << endl;
    int count = 0;
    MergeSort(A, 0, A.size() - 1, count);
    cout << endl;
    if (count % 2 == 0)
    {
        cout << "OUTPUT CARLOS" << endl;
    }
    else
    {
        cout << "OUTPUT MARCELO" << endl;
    }
}

void input()
{
    while (1)
    {
        int a = 0;
        cin >> a;
        vector<int> A(a);
        for (int i = 0; i < a; i++)
        {
            cin >> A[i];
        }
        cout << endl;
        algorithm(A);
    }
}

int main()
{
    input();
}