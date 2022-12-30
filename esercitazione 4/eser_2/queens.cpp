#include <iostream>
using namespace std;

#define N 8
void fill_matrix(bool mat[][N])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            mat[i][j] = false;
        }
    }
}
void print_matrix(bool mat[][N])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

bool is_safe(int i, int j, bool A[][N])
{

    for (int u = 0; u < i; u++)
    {
        // controlla le righe
        if (A[u][j] == true)
        {
            /*
            cout << "VIOLI SOPRA "
                 << "i= " << i << " j= " << j << endl;
*/
            return false;
        }
    }

    for (int u2 = i, k2 = j; k2>=0 && u2 >= 0; k2--, u2--)
    {
        // controlla le diagonali
        if (A[u2][k2] == true)
        {
         //   cout << "VIOLI LA DIAGONALE SINISTRA "
          //       << "i= " << i << " j= " << j << endl;
            return false;
        }
    }

    for (int u1 = i, k1 = j; k1 < N && u1<N ; u1--, k1++)
    {
        // controlla le diagonali
        if (A[u1][k1] == true)
        {
         //   cout << "VIOLI LA DIAGONALE DESTRA "
         //        << "i= " << i << " j= " << j << endl;

            return false;
        }
    }
    //cout << "I e J sono safe: " << i << " " << j << endl;
    return true;
}

bool algorithm(bool A[][N], int i, int j, int &count)
{
    // i riga
    // j colonna

    if (i >= N)
    {
        count++;
        cout<<"Count è "<<count<<endl;
      print_matrix(A);
        return true;
    }

    for (int j = 0; j < N; j++)
    {
      //  cout << "LA I  che passo é " << i << " la J che passo è " << j << endl;
        if (is_safe(i, j, A) == true)
        {
            A[i][j] = true;
            algorithm(A,i+1,j,count);
/*
            if (algorithm(A, i + 1, j, count) == true)
            {
                return true;
            }
*/
            A[i][j] = false;
        }
    }

    return false;
}

void testcase1()
{
    int i = 0;
    int j = 0;
    int count = 0;
    bool A[N][N];
    fill_matrix(A);
    cout << "Stampa iniziale \n";
    print_matrix(A);
    cout << "\n\n";
    algorithm(A,i,j,count);
    
}
int main()
{
    testcase1();
    return 0;
}
