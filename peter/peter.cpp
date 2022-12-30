 #include <iostream>
#include <vector>
using namespace std;


void print_vector(vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << endl;
    }
}
// la funzione di MergeSortVector serve a dividere il vettore per effettuare il mergesort
void MergeSortVector(vector<int>& v, int low, int m, int high) {
	
	vector<int> temp;

	int i, j;
	i = low;
	j = m + 1;

	while (i <= m && j <= high) {

		if (v[i] <= v[j]) {
			temp.push_back(v[i]);
			++i;
		}
		else {
			temp.push_back(v[j]);
			++j;
		}

	}

	while (i <= m) {
		temp.push_back(v[i]);
		++i;
	}

	while (j <= high) {
		temp.push_back(v[j]);
		++j;
	}

	for (int i = low; i <= high; ++i)
		v[i] = temp[i - low];

}

// funzione per l'ordinamento del vettore in O(nlogn)
void MergeSort(vector<int>& v, int low, int high) {
	if (low < high) {
		int m = (low + high) / 2;
        // divido a metà l'array e chiamo merge sort sulla prima metà
		MergeSort(v, low, m);
        // chiamo merge sort sulla seconda metà
		MergeSort(v, m + 1, high);
		MergeSortVector(v, low, m, high);
	}
}
//complessità log(n)
int binarySearch(vector<int> array, int elem, int low, int high)
{
    // ripete finchè low e high non si toccano
    while (low <= high)
    {
        // mid è il mio pivot
        int mid = low + (high - low) / 2;

        if (array[mid] == elem)
            return mid;

        if (array[mid] < elem)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}
void algorithm(vector<int> &books, int cash)
{
    MergeSort(books, 0, books.size() -1);
    print_vector(books);
    int pos = 0;
    int best_solution = INT_MAX;
    int solution = INT_MAX;
    int i = 0;
    int primo, secondo;

    for (int i = 0; i < books.size(); i++)
    {
        if (best_solution == 1)
        {
            break;
        }

        pos = binarySearch(books, cash - books[i], 0, books.size() - 1);
        if (pos == i)
        {
            pos = -1;
        }
        if (pos != -1)
        {
            solution = abs(pos - i);
            if (solution < best_solution)
            {
                best_solution = solution;
                primo = i;
                secondo = pos;
            }
        }
    }
    cout << "i è " << books[primo] << " la j è " << books[secondo] << endl;
}
void testcase()
{
    int cash = 10;
    vector<int> books{
        10, 3, 6, 5, 7, 8, 4};
        print_vector(books);
        cout<<endl;
    algorithm(books, cash);
}
void testcase2()
{
    int cash = 40;
    vector<int> books{
        2, 21, 10, 14, 30, 28, 6, 15, 34, 19};
    algorithm(books, cash);
}
int main()
{
    cout << "AVVIO IL TeSTCASe 1" << endl;
    testcase();
    cout << "AVVIO IL TeSTCASe 2" << endl;

    testcase2();

    return 0;
}