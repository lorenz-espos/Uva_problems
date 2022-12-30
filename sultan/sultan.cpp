#include <iostream>
#include <vector>
using namespace std;
void fill_matrix(vector<vector<int>> &mat){
    //vector va passato per riferimento
     int i, j;
     int count=1;
    for (i = 0; i < mat.size(); i++)
    {
        for (j = 0; j < mat[0].size(); j++)
        {
            mat[i][j]=count;
            count++;
        }
    }
}
void print_matrix(vector<vector<bool>>mat)
{
    int i, j;
    for (i = 0; i < mat.size(); i++)
    {
        for (j = 0; j < mat[0].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
void print_matrix2(vector<vector<int> >mat)
{
    int i, j;
    for (i = 0; i < mat.size(); i++)
    {
        for (j = 0; j < mat[0].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int sum(vector<vector<int>> matrix, vector<vector<int>> position ){
    int totale = 0;
    for(int i = 0; i < position.size(); i++){
            int u = position[i][0];
            int t = position[i][1];
        totale += matrix[u][t];
    }
    return totale;
}

bool is_safe(int i, int j, vector<vector<bool>> A)
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

    for (int u = i, k = j; k>=0 && u >= 0; k--, u--)
    {
        // controlla le diagonali
        if (A[u][k] == true)
        {
         //   cout << "VIOLI LA DIAGONALE SINISTRA "
          //       << "i= " << i << " j= " << j << endl;
            return false;
        }
    }

    for (int u = i, k = j; k < A.size()&& u<A[0].size() ; u--, k++)
    {
        // controlla le diagonali
        if (A[u][k] == true)
        {
         //   cout << "VIOLI LA DIAGONALE DESTRA "
         //        << "i= " << i << " j= " << j << endl;

            return false;
        }
    }
    //cout << "I e J sono safe: " << i << " " << j << endl;
    return true;
}
void algorithm(vector<vector<bool>> A , int i, int j, int &count,vector<vector<int>> &B,int &totale,vector<vector<int>>board_n)
{
    // i riga
    // j colonna

    if (i >= A[0].size())
    {
        count++;
        cout<<"Count è "<<count<<endl;
      print_matrix(A);
      int totale_temp = sum(board_n,B);
      if(totale_temp>totale){
        totale= totale_temp;
      }
        return ;
    }

    for (int j = 0; j < A.size(); j++)
    {
      //  cout << "LA I  che passo é " << i << " la J che passo è " << j << endl;
        if (is_safe(i, j, A) == true)
        {
            A[i][j] = true;
            B[i][0]=i;
            B[i][1]=j;
            algorithm(A,i+1,j,count,B,totale,board_n);
/*
            if (algorithm(A, i + 1, j, count) == true)
            {
                return true;
            }
*/
            A[i][j] = false;
            B[i][0]=0;
            B[i][1]=0;
        }
    }

}
int main(){
int count=0;
int totale=0;
vector<vector<bool>> board(8, vector<bool>(8));
vector<vector<int>> board_n(8, vector<int>(8));
vector<vector<int>> position(8,vector<int>(2));
fill_matrix(board_n);
print_matrix(board);
cout<<endl<<endl;
print_matrix2(board_n);
algorithm(board,0,0,count,position,totale,board_n);
cout<<endl;
cout<<"il totale è "<<totale<<endl;

    return 0;
}