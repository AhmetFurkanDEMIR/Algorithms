#include <stdio.h>
#include <stdlib.h>

void ShellSort(int array[], int size){

	int Increase=size/2;
	int i,j, temp;

	while(Increase!=0){

		for(i=Increase; i<size; i++){

			temp = array[i];
			j=i-Increase;

			while(j>=0 && temp<array[j]){

				array[j+Increase] = array[j];
				array[j] = temp;
				j-=Increase;

			}
		}

		Increase=Increase/2;

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

	ShellSort(array, size);
	print(array, size);

	return 0;
}