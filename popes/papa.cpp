#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//upper bound function
int upper_bound(vector<int> &v, int l, int r, int x)
{
    int m;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        if (v[m] <= x)
            l = m + 1;
        else
            r = m - 1;
    }
    return l;
}

void algorithm(vector<int> v,int a){
    int max=0;
    int index=0;
    int index2=0;
    int index3=0;
    for(int i=0; i<v.size(); i++){
    index=upper_bound(v,i,v.size()-1,v[i]+a-1);



       if(index-i>max){
           max=index-i;
           index2=index-1;
           index3=i;
       }
    }
    cout<<max<<" "<<v[index3]<<" "<<v[index2]<<endl;
}
int main(){
int a=0;
int b=0;
cin>>a;
cin>>b;
vector<int> v(b);
for(int i=0;i<b;i++){
cin>>v[i];
}
algorithm(v,a);


    return 0;
}