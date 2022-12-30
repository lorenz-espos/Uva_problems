#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
using namespace std;

void algorithm(int n){

    cout<< n-1 + int(log2(n-1))<<endl;
    }

int main(){
    int n=0;
    while(1){
        cin>>n;
        algorithm(n);
    }
    return 0;
}