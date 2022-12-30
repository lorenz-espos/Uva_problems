#include <iostream>
using namespace std;

void algorithm(int coins,int coins_t,int line){
    if(coins<coins_t){
        cout<<line-1<<endl;
        return;
    }
    if(coins==coins_t){
        cout<<line<<endl;
        return;
    }
    line++;
    coins_t+=line;
    algorithm(coins,coins_t,line);
}

void input(){
  int num_of_cases = 0;
    cin >> num_of_cases;
    int A[num_of_cases];
    for(int i=0;i<num_of_cases;i++)
    {
        cin >> A[i];
        
    }
    cout<<endl;
    for(int i=0;i<num_of_cases;i++)
    algorithm(A[i],0,0);
}

int main()
{
  input();
    return 0;
}