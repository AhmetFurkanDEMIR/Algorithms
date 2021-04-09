#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int array[], int size){

	int index;
	int flag=1;

	while(flag){

		flag=0;

		for(int i=0; i<size-1; i++){


			if(array[i]>array[i+1]){

				flag=1;

				int temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;

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

	BubbleSort(array, size);
	print(array, size);

	return 0;
}