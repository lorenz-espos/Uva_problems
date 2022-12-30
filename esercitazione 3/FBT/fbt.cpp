#include <iostream>
#include <algorithm>
#include "math.h"
using namespace std;

void algorithm(int node, int balls, int first_leaf)
{
    int left = node * 2;
    int right = left + 1;
    if (left < first_leaf)
    {
        if (balls % 2 == 0)
        {
            //cout << "right è " << right << endl;
            node = right;
            algorithm(right, balls / 2, first_leaf);
        }
        else
        {
           // cout << "left è " << left << endl;
            node = left;
            algorithm(left, balls / 2 + 1, first_leaf);
        }
    }
    else
    {
    cout<<"OUTPUT:"<<node;
    }
    
}

void testcase1()
{
    int D = 0;
    int balls = 0;
    int node=1;
    int input=0;
    cout<<"INSERISCI LA D"<<endl;
    cin>>D;
    cout<<"INSERISCI IL NUMERO DI PALLINE"<<endl;
    cin>>balls;
    if(D<=2 || D>=20){
        cout<<"LA D NON é VALIDA"<<endl;
        return;
    }
    if(balls<=1 || balls>=524288){
        cout<<"INPUT PALLINE NON VALIDO"<<endl;
        return;
    }
    int first_leaf = pow(2, D);
    // cout<<first_leaf<<endl;
    algorithm(node, balls, first_leaf);

}
int main()
{

    testcase1();

    return 0;
}