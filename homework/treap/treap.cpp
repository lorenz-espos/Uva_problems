#include <iostream>
#include <cstdlib>
using namespace std;

// classe per la struttura dati treap
class TreapNode
{
public:
    TreapNode(int key)
    {
        this->key = key;
        // alla costruzione della struttura assegno una priorità a caso
        this->priority = rand() % 100;
        // inizializzo i puntatori di destra e di sinistra come null
        this->left = this->right = nullptr;
    }
    // funzione di rotazione a sinistra
    void rotateLeft(TreapNode *&root)
    {
        TreapNode *R = root->right;
        TreapNode *X = root->right->left;

        // ruota
        R->left = root;
        root->right = X;

        // imposta una nuova radice
        root = R;
    }
    // funzione di rotazione a destra
    void rotateRight(TreapNode *&root)
    {
        TreapNode *L = root->left;
        TreapNode *Y = root->left->right;

        // ruota
        L->right = root;
        root->left = Y;

        // imposta una nuova radice
        root = L;
    }

    // Funzione ricorsivo per inserire una key chiave con una priorità in treap
    // utilizzando un parametro di riferimento
    void insertNode(TreapNode *&root, int key)
    {
        if (root == nullptr)
        {
            root = new TreapNode(key);
            return;
        }

        // se key[v]<key[u] in cui v è il figlio sinistro di u
        if (key < root->key)
        {
            insertNode(root->left, key);
            // proprietà di heap: priority(v)>priority(u)
            //  ruota a destra se la proprietà heap viene violata
            if (root->left != nullptr && root->left->priority > root->priority)
            {
                rotateRight(root);
            }
        }
        // se key[v]>key[u] in cui v è il figlio destro di u
        if (key > root->key)
        {
            insertNode(root->right, key);
            // proprietà di heap: priority(v)>priority(u)
            // ruota a sinistra se la proprietà heap viene violata
            if (root->right != nullptr && root->right->priority > root->priority)
            {
                rotateLeft(root);
            }
        }
    }
    // funzione di stampa della struttura
    void printTreap(TreapNode *root, int space = 0, int height = 10)
    {
        if (root == nullptr)
        {
            return;
        }

        space += height;

        printTreap(root->right, space);
        cout << endl;

        for (int i = height; i < space; i++)
        {
            cout << ' ';
        }
        cout << root->key << "(" << root->priority << ")\n";

        cout << endl;
        printTreap(root->left, space);
    }

private:
    int key;
    int priority;
    TreapNode *left, *right;
};

int main()
{
    // Chiavi treap
    int n = 9;
    int keys[] = {4, 3, 2, 5, 10, 9, 11, 1, 23, 16};

    // Costruisci una treap
    TreapNode treap(0);
    TreapNode *root = nullptr;
    cout << "inserisco il primo set di key" << endl;
    for (int i = 0; i < n / 2; i++)
    {
        treap.insertNode(root, keys[i]);
    }
    treap.printTreap(root);
    cout << "inserisco il secondo set di key" << endl;

    for (int i = n / 2; i < n; i++)
    {
        treap.insertNode(root, keys[i]);
    }
    treap.printTreap(root);

    return 0;
}