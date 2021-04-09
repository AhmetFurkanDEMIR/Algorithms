#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int array[], int size){

	for(int i=0; i<size-1; i++){

		for(int j=i+1; j<size; j++){

			if(array[i]>array[j]){

				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;

			}

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

	SelectionSort(array, size);
	print(array, size);

	return 0;
}