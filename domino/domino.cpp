#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct card
{
    int a = 0;
    int b = 0;
};
void print(card arr[],int dim){
    cout<<endl;
    for(int i=0;i<dim;i++){
        cout<<arr[i].a<<" "<<arr[i].b<<endl;
    }
}
int linear_search(card arr[], card elm, int dim)
{
    for (int i = 0; i < dim - 1; i++)
    {
        if (arr[i].a == elm.a && arr[i].b == elm.b)
        {
            return i;
        }
    }
    return -1;
}

bool is_safe(card e[], int fill)
{
    if (e[fill].a == e[fill - 1].a || e[fill].b == e[fill - 1].b)
    {
        return true;
    }
    return false;
}
bool algorithm(card in[], int dim, card e[],int dim2, int fill)
{
    card p;
    p.a = 0;
    p.b = 0;
    if (fill==dim2-1)
    {
        //print(e,dim2);
        if (e[fill].a==e[fill-1].a || e[fill].b==e[fill-1].b)
        {
            return true;
        }
        return false;
        // condizione di terminazione
    }
    for (int i = 0; i < dim; i++)
    {
        //verifica che il mio candidato non sia già stato impiegato
        if (linear_search(e, in[i], dim2) == -1)
        {
            e[fill] = in[i];
            if (is_safe(e, fill) == true)
            {
                if(algorithm(in, dim, e,dim2, fill + 1)==true){
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    int n = 0;
    int m = 0;
    cin >> n;
    cin >> m;
    n+=2;
    card input[m];
    card estremi[n];
    cin >> estremi[0].a;
    cin >> estremi[0].b;
    cin >> estremi[n-1].a;
    cin >> estremi[n-1].b;
    for (int i = 0; i < m; i++)
    {
        cin >> input[i].a;
        cin >> input[i].b;
    }
    if (algorithm(input, m, estremi,n, 1) == true)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
