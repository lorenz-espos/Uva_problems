#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// funzione che inizializza la matrice
void init(vector<vector<int>> p)
{
    for (int i = 0; i < p.size(); i++)
    {
        for (int j = 0; j < p.size(); j++)
        {
            p[i][j] = 0;
        }
    }
}

int algorithm(string A, int i, int j, vector<vector<int>> p)
{
    // caso base 1: se la stringa è vuota
    if (i > j)
    {
        return 0;
    }
    // caso base 2: se la stringa ha un solo carattere
    if (i == j)
    {
        return 1;
    }
    // caso in cui la soluzione è già in memoria
    if (p[i][j] != 0)
    {
        return p[i][j];
    }
    // caso nel cui il primo e l'ultimo carattere della stringa sono uguali e la soluzione non è in memoria
    if (A[i] == A[j])
    {
        // caso in cui due lettere sono già uguali
        p[i][j] = algorithm(A, i + 1, j - 1, p) + 2;
        // aggiungo i due caratteri uguali e richiamo la funzione ricorsiva
    }
    else
    {
        // caso in cui due lettere sono diverse
        p[i][j] = max(algorithm(A, i, j - 1, p), algorithm(A, i + 1, j, p));
        // calcolo il massimo tra la soluzione senza il primo carattere e quella senza l'ultimo carattere
    }

    return p[i][j];
}

void testcase1()
{
    string S = "ADAM";
    int n = S.length();
    vector<vector<int>> p(S.length(), vector<int>(S.length(), 0));
    init(p);
    cout << "La lunghezza della sottosequenza palindroma più lunga è "
         << algorithm(S, 0, n - 1, p);
}
void testcase2()
{
    string S = "MADAM";
    int n = S.length();
    vector<vector<int>> p(S.length(), vector<int>(S.length(), 0));
    init(p);
    cout << "La lunghezza della sottosequenza palindroma più lunga è "
         << algorithm(S, 0, n - 1, p);
}
void testcase3()
{
    string S = "MA";
    int n = S.length();
    vector<vector<int>> p(S.length(), vector<int>(S.length(), 0));
    init(p);
    cout << "La lunghezza della sottosequenza palindroma più lunga è "
         << algorithm(S, 0, n - 1, p);
}
int main()
{
    cout << "Testcase 1" << endl;
    // output previsto 3
    testcase1();
    cout << endl
         << "Testcase 2" << endl;
    // output previsto 5
    testcase2();
    cout << endl
         << "Testcase 3" << endl;
    // output previsto 1
    testcase3();

    return 0;
}