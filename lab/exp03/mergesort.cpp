#include <iostream>
using namespace std;
#define MAXN 100000
long long int aux[MAXN];
long long int data[MAXN];
void mergeSort(long long int arr[], int low, int mid, int high) {
	int i = low, j = mid + 1;
	for (int k = low; k <= high; k++) {
	    aux[k] = arr[k];
	}
	for (int k = low; k <= high; k++) {
		if (i > mid) arr[k] = aux[j++];
		else if (j > high) arr[k] = aux[i++];
		else if (aux[i] < aux[j]) arr[k] = aux[i++];
		else arr[k] = aux[j++];
	}
}
void Sort(long long int arr[], int low, int high ) {
	if (low >= high) {
		return ;
	}
	int mid = low + (high -low) / 2;
	Sort(arr, low, mid);
	Sort(arr, mid + 1, high) ;
	mergeSort(arr, low, mid, high);	
}
int main() {
	int n;
	cin >> n;
	for (int k = 0; k < n; k++) {
		cin >> data[k];
	}
	Sort(data, 0, n - 1);
	for (int k = 0; k < n; k++) {
		cout << data[k] << " ";
	}
	return 0;
}
