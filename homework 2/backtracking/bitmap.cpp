#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void print_matrix(vector<vector<bool>> mat)
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
void bitmap(vector<vector<bool>> &mat, vector<vector<bool>> &bit,int i, int j)
{
    if(mat[i][j]==false){
        if(i-1>=0){ //SOPRA
            bit[i-1][j]=false;
        }
        if(i+1<=mat.size()-1){ //Sotto
            bit[i+1][j]=false;
        }
        if(j-1>=0){ //sinistra
            bit[i][j-1]=false;
        }
        if(j+1<=mat[0].size()-1){ //destra
            bit[i][j+1]=false;
        }
        bit[i][j]=false;
    }
}
bool is_safe(vector<vector<bool>>mat,int u,int k ){
    if (k > mat[0].size() - 1 || u > mat.size() - 1||u < 0 || k < 0)
        return false;
    if(mat[u][k]==false)
    return false;
    return true;
}


void algorithm(int i, int j, vector<vector<bool>> &mat, int lenght, int &min_lenght)
{
    // condizione di terminazione
    //cout<<"la j è "<<j<<" la size è "<<mat[0].size()-1<<endl;
    
      //  cout<<"sono nella condizione di terminazione"<<endl<<lenght<<endl<<min_lenght<<endl;
        if ( j==mat[0].size()-1)
        {
            if(lenght<min_lenght){
            min_lenght = lenght;
            //cout<<min_lenght<<endl;
            
            }
            return;
        }
           //pongo la posizione attuale così non effettua il rollback finchè non termine l'algoritmo
            mat[i][j] = false;

for (int k = 0; k < 4; k++)
    {
        if (k == 0)
        {

            if (is_safe(mat,i,j+1))
            {
                //cout << "(DESTRA)sono in "<<i<<" , "<< j<< endl;
                algorithm(i, j + 1, mat, lenght+1 , min_lenght);
            }
            // destra
        }
        if (k == 1)
        {
            if (is_safe(mat,i+1,j))
            {
                //cout << "(BASSO)sono in "<<i<<" , "<< j<< endl;

                algorithm(i + 1, j, mat, lenght+1, min_lenght);
            }
            // basso
        }
        if (k == 2)
        {
            if (is_safe( mat,i,j-1))
            {
                //cout << "(SINISTRA)sono in "<<i<<" , "<< j<< endl;

                algorithm(i, j - 1, mat, lenght+1 , min_lenght);
            }
            // sinistra
        }
        if (k == 3)
        {
            if (is_safe( mat,i-1,j))
            {
                //cout << "(ALTO)sono in "<<i<<" , "<< j<< endl;

                algorithm(i - 1, j, mat, lenght+1 , min_lenght);
            }
            // alto
        }
    }
    //rimetto true per per
        mat[i][j] = true;

    return;
    }


//CASO IN CUI IL CAMMINO MINIMO é UN SOTTO INSIEME DI UN CAMMINO PIù GRANDE  
void testcase1(vector<vector<bool>> &mat, vector<vector<bool>> &bit)
{
    mat[0][0]=true;
    for (int i = 1; i < mat.size(); i++)
        for (int j = 0; j < mat[0].size(); j++)
            mat[i][j] = true;
    cout << "LA MATRICE DI PARTENZA è" << endl;
    print_matrix(mat);
    cout << "LA MATRICE DI BITMAP è" << endl;
    for(int i=0;i<bit.size();i++)
    for(int j=0;j<bit[0].size();j++)
    bitmap(mat,bit,i,j);
    print_matrix(bit);
    int min=INT_MAX;
    int l=1;
    for(int u=0;u<bit.size();u++){
    if(bit[u][0]==true){
            algorithm(u,0,bit,l,min);

    }
    }
 if(min==INT_MAX){
        cout<<"IL PROBLEMA NON HA SOLUZIONE"<<endl;
    }
    else{
        cout<<min<<endl;
    }
}
//CASO SENZA SOLUZIONE
void testcase2(vector<vector<bool>> &mat, vector<vector<bool>> &bit){
    mat[0][0] = true;
    mat[0][1] = true;
    mat[0][2] = true;
    mat[0][3] = true;
    mat[1][0] = true;
    mat[1][1] = false;
    mat[1][2] = true;
    mat[1][3] = true;
    mat[2][0] = true;
    mat[2][1] = true;
    mat[2][2] = true;
    mat[2][3] = false;
     cout << "LA MATRICE DI PARTENZA è" << endl;
    print_matrix(mat);
    cout << "LA MATRICE DI BITMAP è" << endl;
    for(int i=0;i<bit.size();i++)
    for(int j=0;j<bit[0].size();j++)
    bitmap(mat,bit,i,j);
    print_matrix(bit);
    int min=INT_MAX;
    int l=1;
    for(int u=0;u<bit.size();u++){
    if(bit[u][0]==true){
            algorithm(u,0,bit,l,min);

    }
    }
    if(min==INT_MAX){
        cout<<"IL PROBLEMA NON HA SOLUZIONE"<<endl;
    }
    else{
        cout<<min<<endl;
    }

}
//CASO IN CUI IL CAMMINO MINIMO é UN SOTTO INSIEME DI UN CAMMINO PIù GRANDE  
//con matrice quadrata
void testcase3(vector<vector<bool>> &mat, vector<vector<bool>> &bit){
  mat[0][1]=false;
     cout << "LA MATRICE DI PARTENZA è" << endl;
    print_matrix(mat);
    cout << "LA MATRICE DI BITMAP è" << endl;
    for(int i=0;i<bit.size();i++)
    for(int j=0;j<bit[0].size();j++)
    bitmap(mat,bit,i,j);
    print_matrix(bit);
    int min=INT_MAX;
    int l=1;
    for(int u=0;u<bit.size();u++){
    if(bit[u][0]==true){
            algorithm(u,0,bit,l,min);

    }
    }
 if(min==INT_MAX){
        cout<<"IL PROBLEMA NON HA SOLUZIONE"<<endl;
    }
    else{
        cout<<min<<endl;
    }
}
void testcase4(vector<vector<bool>> &mat, vector<vector<bool>> &bit){
  mat[0][0]=false;
  mat[2][3]=false;
     cout << "LA MATRICE DI PARTENZA è" << endl;
    print_matrix(mat);
    cout << "LA MATRICE DI BITMAP è" << endl;
    for(int i=0;i<bit.size();i++)
    for(int j=0;j<bit[0].size();j++)
    bitmap(mat,bit,i,j);
    print_matrix(bit);
    int min=INT_MAX;
    int l=1;
    for(int u=0;u<bit.size();u++){
    if(bit[u][0]==true){
            algorithm(u,0,bit,l,min);

    }
    }
 if(min==INT_MAX){
        cout<<"IL PROBLEMA NON HA SOLUZIONE"<<endl;
    }
    else{
        cout<<min<<endl;
    }
}

int main()
{
    vector<vector<bool>> mat(3, vector<bool>(4));
    vector<vector<bool>> bit(3, vector<bool>(4,true));
    //primo caso di test
    testcase1(mat, bit);
    //secondo caso di test
    testcase2(mat,bit);
    //cambio i vettori per usare matrici più grandi
    vector<vector<bool>>mat2(4,vector<bool>(4,true));
    vector<vector<bool>> bit2(4, vector<bool>(4,true));
    //terzo caso di test
    testcase3(mat2,bit2);
    //cambio i vettori
    vector<vector<bool>>mat3(3,vector<bool>(4,true));
    vector<vector<bool>> bit3(3, vector<bool>(4,true));
    //quarto caso di test
    testcase4(mat3,bit3);

    return 0;
}