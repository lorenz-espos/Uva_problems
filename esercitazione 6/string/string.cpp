#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// divide l'array in due sottoarray, li ordina e ne fa il merge

void print_vector(vector <string> app){
  for(int i=0;i<app.size();i++)
  cout<<app[i]<<endl;
}


void algorithm(vector <string> app)
{
  //ordino in funzione della stringa con la lunghezza più piccola fino alla più grande
  sort(app.begin(),app.end(),[](string a,string b){return a.length()<b.length();});
  //complessità O(nlogn)
    print_vector(app);


}
int main()
{
  vector<string> app{
    "apple", "ape", "april", "applied"
  };
  algorithm(app);

  return 0;
}