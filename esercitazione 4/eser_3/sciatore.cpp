#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print(vector<vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
bool is_safe(int i,int j,vector<vector<int>>mat,int u,int k ){
    if (k > mat[0].size() - 1 || u > mat.size() - 1||u < 0 || k < 0)
        return false;
    if(mat[u][k]<=mat[i][j])
    return false;
    return true;
}


void algorithm(int i, int j, vector<vector<int>> mat, int lenght, int &max_lenght)
{
    // condizione di terminazione
    
        if (lenght > max_lenght)
        {
            max_lenght = lenght;
            cout<<max_lenght<<endl;
            
        }

    for (int k = 0; k < 4; k++)
    {
        if (k == 0)
        {

            if (is_safe(i, j, mat,i,j+1))
            {
                cout << "sono destra "
                     << "l'elemento " << mat[i][j] << endl<<"sono l "<<lenght+1<<endl;
                algorithm(i, j + 1, mat, lenght + 1, max_lenght);
            }
            // destra
        }
        if (k == 1)
        {
            if (is_safe(i, j, mat,i+1,j))
            {
                cout << "sono sotto "
                     << "l'elemento " << mat[i][j] << endl<<"sono l "<<lenght+1<<endl;

                algorithm(i + 1, j, mat, lenght + 1, max_lenght);
            }
            // basso
        }
        if (k == 2)
        {
            if (is_safe(i, j, mat,i,j-1))
            {
                cout << "sono sinistra "
                     << "l'elemento " << mat[i][j] << endl<<"sono l "<<lenght+1<<endl;

                algorithm(i, j - 1, mat, lenght + 1, max_lenght);
            }
            // sinistra
        }
        if (k == 3)
        {
            if (is_safe(i, j, mat,i-1,j))
            {
                cout << "sono sopra "
                     << "l'elemento " << mat[i][j] << endl<<"sono l "<<lenght+1<<endl;

                algorithm(i - 1, j, mat, lenght + 1, max_lenght);
            }
            // alto
        }
    }
}

int main()
{
    int l = 1;
    
    vector<vector<int>> matiniziale

        {
            {1, 2, 3, 4, 5},
            {16, 17, 18, 19, 6},
            {15, 24, 25, 20, 7},
            {14, 23, 22, 21, 8},
            {13, 12, 11, 10, 9}};
    for(int i=0;i<matiniziale[0].size();i++)
    for(int j=0;j<matiniziale.size();j++)
    algorithm(i, j, matiniziale, 1, l);
    cout << l << endl;
    l=1;
    cout<<endl<<endl<<endl;
    

   
    vector<vector<int>> mat

        {
            {56 ,14 ,51, 58, 88},
            { 26, 94, 24, 39, 41},
            { 24, 16, 8, 51, 51,},
            { 76, 72, 77, 43, 10},
            { 38 ,50, 59 ,84 ,81},
            { 5, 23, 37, 71, 77},
            { 96, 10, 93, 53, 82},
            { 94, 15, 96 ,69, 9},
            { 74 ,0, 62, 38, 96},
            { 37 ,54 ,55, 82 ,38}};
    print(mat);
    cout<<mat.size()<<"righe o colonne "<<mat[0].size();
    //int R=mat.size();
    //int C=mat[0].size();
    
    for(int i=0;i<mat.size();i++)
    for(int j=0;j<mat[0].size();j++)
    algorithm(i, j, mat, 1, l);
    cout << l << endl;

    return 0;
}