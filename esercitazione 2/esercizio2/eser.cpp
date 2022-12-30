#include <iostream>
using namespace std;
void triangle(int d){
 for(int i=1;i<=d;i++){
    //il for permette di tornare a capo una volta finita una riga
        int number=1;
        //primo numero da inserire è 1
        for (int j=1;j<=i;j++){
        //il for scorre e crea la riga
        cout<<" "<<number<<" ";
        number=number*(i-j)/j;
        //equazione matematica del triangolo di tartaglia

        }
        cout <<endl;
    }

}
int main(){
    int a=3;
    int b=5;
    cout<<"starting triangle a"<<endl;
    triangle(a);
    cout<<"starting triangle b"<<endl;
    triangle(b);

   
    return 0;
}