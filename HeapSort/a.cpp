#include <stdio.h>

void swap(int &a, int &b) {
   int t = a;
   a = b;
   b = t;
}

void heapify(int array[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;


	if (l < n && array[l] > array[largest])
		largest = l;

	if (r < n && array[r] > array[largest])
		largest = r;


	if (largest != i) {
		swap(array[i], array[largest]);

		heapify(array, n, largest);
	}
}


void HeapSort(int array[], int n)
{

	for (int i = n / 2 - 1; i >= 0; i--){

		heapify(array, n, i);

	}


	for (int i = n - 1; i > 0; i--) {

		swap(array[0], array[i]);
		heapify(array, i, 0);
	}
}


void printArray(int array[], int n)
{
	for (int i = 0; i < n; ++i){

		printf("%d ", array[i]);

	}
}

int main()
{
	int array[] = {5 ,8 ,9 ,45, 87, 52, 65656, 41, 2, 0, 0, 8, 9, 7, 0};
	int n = sizeof(array) / sizeof(array[0]);

	HeapSort(array, n);
	printArray(array, n);
}
