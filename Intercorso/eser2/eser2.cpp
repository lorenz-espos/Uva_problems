#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// funzione che controlla se il numero è primo
bool isPrime(int n)
{
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
// funzione di backtracking
void find_sum_backtracking(int prime, int target, int curr, int count, vector<int> &curr_solution, vector<vector<int>> &solution)
{

    if (curr == target && count == 0)
    {
        // mi salvo la soluzione trovata
        solution.push_back(curr_solution);
        return;
    }

    if (curr > target)
        return;

    for (int i = prime + 1; i <= target; i++)
    {
        // verifico se il numero che ottengo dal ciclo è primo
        if (isPrime(i))
        {
            curr_solution.push_back(i);
            find_sum_backtracking(i, target, curr + i, count - 1, curr_solution, solution);
            curr_solution.pop_back();
        }
    }
    
}
vector<vector<int>> find_sum(int prime, int target_sum, int count)
{
    vector<vector<int>> solution;
    vector<int> curr_solution;
    find_sum_backtracking(prime, target_sum, 0, count, curr_solution, solution);
    return solution;
}

int main()
{
    int n;
    cin >> n;
    int i = 1;
    while (n--)
    {
        int a;
        int b;
        int c;
        cin >> a;
        cin >> b;
        cin >> c;
        //i parametri di input sono: primo, somma, numero di numeri
        vector<vector<int>> solution = find_sum(c, a, b);
        cout << "CASO DI TEST " << i << endl;
        // stampo la soluzione dalla matrice delle soluzioni
        for (int i = 0; i < solution.size(); i++)
        {
            for (int j = 0; j < solution[i].size(); j++)
            {
                cout << solution[i][j] << " ";
            }
            cout << endl;
        }
        ++i;
    }
    return 0;
}
