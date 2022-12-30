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

void MergeSortedIntervals(vector<int>& v, int s, int m, int e) {
	
    // temp is used to temporary store the vector obtained by merging
    // elements from [s to m] and [m+1 to e] in v
	vector<int> temp;

	int i, j;
	i = s;
	j = m + 1;

	while (i <= m && j <= e) {

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

	while (j <= e) {
		temp.push_back(v[j]);
		++j;
	}

	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];

}

// the MergeSort function
// Sorts the array in the range [s to e] in v using
// merge sort algorithm
void MergeSort(vector<int>& v, int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		MergeSort(v, s, m);
		MergeSort(v, m + 1, e);
		MergeSortedIntervals(v, s, m, e);
	}
}

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

void testcase3()
{
    int cash = 259;
    vector<int> books{
        145, 453, 356, 65 ,78 ,45 , 234, 657,87 ,45,34,5 ,56,78,89,809,8,45,43,5,234, 56,8,679,98,0,798,675,56,4,34,3,34,56,6,68,67,2,25,90'25,9,23,203,59,832, 21, 10, 14, 30, 28, 6, 15, 34, 19};
    algorithm(books, cash);
}

int main()
{
    cout << "AVVIO IL TESTCASE 1" << endl;
    testcase();
    cout << "AVVIO IL TESTCASE 2" << endl;
    testcase2();
    cout << "AVVIO IL TESTCASE 3" << endl;
    testcase3();

    return 0;
}