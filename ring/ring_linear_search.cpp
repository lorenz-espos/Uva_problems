#include <iostream>
#include <vector>
using namespace std;

void print_circle(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
int linear_search(vector<int> arr,int elm){
    for(int i=0;i<arr.size();i++){
    if(arr[i]==elm){
        return i;
    }}
    return -1;
}

bool is_safe_sum(vector<int> &circle, int i, int sum)
{
    vector<int> prime{2, 3, 5, 7, 11, 13};
    // se la somma non è presente nell'array dei numeri primi ritorna false
    if (linear_search(prime, sum) == -1)
    {
        return false;
    }
    return true;
}

void algorithm(vector<int> circle, int i)
{

   if(linear_search(circle,0)==-1)
    {
        int sum=circle[circle.size()-1]+circle[0];
        if(is_safe_sum(circle,i,sum)==true){
        // il cerchio è pieno perchè non ci sono più zero
        print_circle(circle);
        return;
        }

    }
    for (int j = 2; j < circle.size()+1; j++)
    {

        // verifico che l'elemento sia presente nel cerchio
        if (linear_search(circle, j) == -1)
        {

            // se l'elemento non è presente proseguo
            circle[i] = j;
            // verifico che sia in una posizione dispari per calcolare la somma della coppia
          
                int sum = 0;
                sum = circle[i] + circle[i - 1];
                // verifico che la somma sia prima
                if (is_safe_sum(circle, i, sum) == true)
                algorithm(circle, i + 1);
        }
    }
}
int main()
{
    int input;
    while (1)
    {
        cin >> input;
    vector<int> circle(input);
    circle[0] = 1;
    algorithm(circle, 1);
    }
    
    
}