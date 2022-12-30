#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_vector(vector<int> arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}


//funzione di merge con conteggio delle inversioni
int merge(vector<int> &v, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++)
    {
        L[i] = v[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = v[m + 1 + i];
    }

    int i = 0, j = 0, k = l;
    int count = 0;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[k] = R[j];
            j++;
            //aggiorno il conteggio dell'inversione
            count += n1 - i;
        }
        k++;
    }
    while (i < n1)
    {
        v[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        v[k] = R[j];
        j++;
        k++;
    }
    return count;
}

//merge sort con conteggio delle inversioni
int mergeSort(vector<int> &v, int l, int r)
{
    int count = 0;
    if (l < r)
    {
        int m = l + (r - l) / 2;
        count += mergeSort(v, l, m);
        count += mergeSort(v, m + 1, r);
        count += merge(v, l, m, r);
    }
    return count;
}
void algorithm(vector<int> arr)
{
  int count = 0;
  count=mergeSort(arr, 0, arr.size() - 1);
  //print_vector(arr);
  cout << "Optimal train swapping takes " << count << " swaps" << endl;
}
void input()
{
  int a = 0;
  cin >> a;
  while (a)
  {
    int b = 0;
    cin >> b;
    vector<int> A(b);
    for (int i = 0; i < b; i++)
    {
      cin >> A[i];
    }
    algorithm(A);
    a--;
  }
}

int main()
{
  input();
}