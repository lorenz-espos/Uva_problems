#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void print_vector(vector <int> A){
    for(int i=0;i<A.size();i++)
    cout<<A[i]<<" ";
    cout<<endl;
}
////merge sort sui vector di interi
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

void algorithm(vector<int> A){
MergeSort(A,0,A.size()-1);
print_vector(A);

}
int main(){
    int a;
while(1){
    cin>>a;
vector <int> A(a);
for(int i=0;i<a;i++){
    cin>>A[i];
}
algorithm(A);

 }

    return 0;
}