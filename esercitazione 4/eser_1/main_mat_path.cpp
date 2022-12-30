//
//  main.cpp
//  Backtracking_matrix_path
//
//  Created by Marco Di Fiandra on 04/11/22.
//

#include <iostream>
using namespace std;
#define DIMRIGHE 2
#define DIMCOL 3
#define ENDBACKTRACK stepCol == DIMCOL-1 && stepRow == DIMRIGHE-1

enum directions{
    destra,
    basso
};

void printSolution(int*,int);
void printMatrix(int[][DIMCOL]);
bool backtrackingPath(int[][DIMCOL],int,int,int*,int,int);
bool IsValid(int,int);
void fillMatrix(int[][DIMCOL]);

int main() {
    int matrice[DIMRIGHE][DIMCOL];
    int *path;
    path = new int[DIMRIGHE+DIMCOL];
    for(int i = 0; i<(DIMRIGHE+DIMCOL);i++){
        path[i] = 0;
    }
    fillMatrix(matrice);
    printMatrix(matrice);
    backtrackingPath(matrice, 0, 0, path, DIMRIGHE+DIMCOL, 0);
    delete[] path;
    return 0;
}

void fillMatrix(int mat[][DIMCOL]){
    int cont = 1;
    for(int i = 0; i<DIMRIGHE;i++){
        for(int j = 0; j<DIMCOL;j++){
            mat[i][j] = cont;
            cont++;
        }
    }
}

void printMatrix(int mat[][DIMCOL]){
    for(int i=0; i<DIMRIGHE;i++){
        for(int j = 0; j<DIMCOL; j++){
            cout<<mat[i][j];
        }
        cout<<endl;
    }
}

void printSolution(int* array,int n){
    cout<<"I percorsi sono: "<<endl;
    for(int i = 0; i<n;i++){
        cout<<array[i];
    }
    cout<<endl;
}

bool IsValid(int stepCol,int stepRow){
    if(stepCol >= DIMCOL){
        return false;
    }else if(stepRow >= DIMRIGHE){
        return false;
    }
    return true;
}

bool backtrackingPath(int mat[][DIMCOL],int stepCol,int stepRow,int* paths,int dim,int i){
    paths[i] = mat[stepRow][stepCol];
    if(ENDBACKTRACK){
        cout<<"[DEBUG], ENDBACKTRACK stepCol: "<<stepCol<<" StepROW "<<stepRow<<endl;
        printSolution(paths, i+1);
    }
    for(int j = 0; j<2;j++){
        //cout<<"[DEBUG] stepCol: "<<stepCol<<" StepROW "<<stepRow<<" Index: "<<i<<endl;
        //printSolution(paths, i+1);
        switch(j){
            case destra:
                stepCol++;
                break;
            case basso:
                stepRow++;
                break;
        }
        if(IsValid(stepCol, stepRow)){
            if(backtrackingPath(mat, stepCol, stepRow, paths, dim, i+1)){return true;}
        }
        //cout<<"[DEBUG] percorsi falliti stepCol: "<<stepCol<<" StepROW "<<stepRow<<" Index: "<<i<<endl;
        //printSolution(paths, i+1);
        switch(j){
            case destra:
                stepCol--;
                break;
            case basso:
                stepRow--;
                break;
        }
        //paths[i] = 0;
    }
    return false;
}


