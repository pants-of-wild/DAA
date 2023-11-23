#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAXN 100000
void Swap(int arr[], int p1, int p2) {
	int temp = arr[p1];
	arr[p1] = arr[p2];
	arr[p2] = temp;
}
void Random(int a[], int low, int high)
{   
    int pivot = rand()%(high - low) + low;
    Swap(a, pivot, low);
}
int  partition(int arr[], int low, int high) {
	Random(arr, low, high);
	int i = low, j = high + 1;
	int pivot = arr[low];
	while(true) {
		while (arr[++i] < pivot) if (i == high) break;
		while (arr[--j] > pivot) if (j == low) break;
		if (i >= j) break;
		Swap(arr, i, j);
	}
	Swap(arr, low, j);
	return j;
}
void quickSort(int arr[], int low, int high) {
	if(low >= high) return;
	int k = partition(arr, low, high);
	quickSort(arr, low, k - 1);
	quickSort(arr, k + 1, high);
	
}

int main() {
	int n;
	cin >> n;
	int data[MAXN];
	for (int k = 0; k < n; k++) {
		cin >> data[k];
	}
	quickSort(data, 0, n - 1);
	for (int k = 0; k < n; k++) {
		cout << data[k] << " ";
	}
	return 0;
}
