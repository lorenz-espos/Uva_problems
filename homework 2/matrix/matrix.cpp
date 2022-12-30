#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int Solution(vector<int> &histo)
{
    stack<int> st;
    // uso uno stack di appoggio per memorizzare l'area dei rettagoli più grandi
    int maxA = 0;
    int n = histo.size();
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i]))
        {
            int height = histo[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            // il massimo è il massimo tra il massimo attuale e l'area del rettagolo
            maxA = max(maxA, width * height);
        }
        st.push(i);
    }

    return maxA;
}

int algorithm(vector<vector<int>> &mat, int m, int n)
{

    int maxArea = 0;

    vector<int> height(n, 0);

    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < n; j++)
        {

            if (mat[i][j] == 0)
                // se trovo uno zero aumento l'altezza
                height[j]++;
            else
                // se non trovo uno zero l'altezza viene resettata a zero
                height[j] = 0;
        }
        // calcolo l'area ottenendo il massimo tra il massimo attuale e l'area appena calcolata
        int area = Solution(height);

        maxArea = max(area, maxArea);
    }

    return maxArea;
    // ritorno l'area della sottomatrice più grande contenente tutti zeri
}

void testcase1()
{
    vector<vector<int>> matrix = {{0, 1, 0, 1},
                                  {0, 1, 0, 0},
                                  {0, 1, 1, 1},
                                  {1, 0, 1, 1},
                                  {0, 1, 1, 1}};

    int max = algorithm(matrix, matrix.size(), matrix[0].size());

    cout << max << endl;
}
void testcase2()
{
    vector<vector<int>> matrix = {{0, 0, 1, 1, 0},
                                  {0, 0, 1, 1, 0},
                                  {1, 0, 0, 0, 1},
                                  {1, 0, 0, 0, 1},
                                  {1, 0, 1, 0, 0},
                                  {1, 0, 0, 0, 1}};

    int max = algorithm(matrix, matrix.size(), matrix[0].size());

    cout << max << endl;
}
void testcase3()
{
    vector<vector<int>> matrix = {{1, 1, 1, 1, 0},
                                  {1, 0, 1, 1, 0},
                                  {0, 0, 0, 0, 1},
                                  {0, 0, 0, 0, 1},
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 1}};

    int max = algorithm(matrix, matrix.size(), matrix[0].size());

    cout << max << endl;
}
int main()
{
    cout << "AVVIO TESTCASE 1" << endl;
    testcase1();
    // output atteso 3
    cout << "AVVIO TESTCASE 2" << endl;
    testcase2();
    // output atteso 6
    cout << "AVVIO TESTCASE 3" << endl;
    testcase3();
    // output atteso 16

    return 0;
}
