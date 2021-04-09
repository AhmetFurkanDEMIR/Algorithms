#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int array[], int size){

	int index;

	for(int i=1; i<size; i++){

		index=i;

		while(index>0 && array[index]<array[index-1]){

			int temp = array[index];
			array[index] = array[index-1];
			array[index-1] = temp;

			index-=1;

		}

	}

}

void print(int array[], int size){

	for(int i=0; i<size;i++){
		printf("%d ", array[i]);
	}

}

int main(){

	int array[] = {5,6,9,4,1,-9,-8,6,50};
	int size = sizeof(array)/sizeof(array[0]);

	InsertionSort(array, size);
	print(array, size);

	return 0;
}