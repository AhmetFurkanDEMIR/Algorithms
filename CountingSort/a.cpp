#include <stdio.h>

void CountingSort(int array[], int size){


	int temp[size]={0};

	for(int i=0; i<size; i++){

		temp[array[i]] += 1;

	}


	int j, index=0;

	for(int i=0; i<size; i++){


		j=0;

		while(j<temp[i]){

			array[index]=i;
			index+=1;

			j+=1;
		}

	}

}

void PrintArray(int array[], int size){


	for(int i=0; i<size; i++){

		printf("%d ", array[i]);

	}


}


int main(){


	int array[] = {1,2,3,5,5,4,1,8,9,7,7,0,9,5,2,3,1,3,6,5,8,8,7,9,5,0,0};
	int size = sizeof(array)/sizeof(array[0]);

	CountingSort(array, size);

	PrintArray(array, size);



	return 0;
}