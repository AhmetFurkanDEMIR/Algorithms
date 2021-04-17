#include <stdio.h>

void RadixSort(int array[], int size){


	int d=-9,temp, d_temp;

	for(int i=0; i<size; i++){


		temp = array[i];
		d_temp=0;

		while(temp>0){

	        temp=temp/10;

	        d_temp++;

	    }

	    if(d<=d_temp){

	    	d=d_temp;

	    }

	}

	int bs = 1;

	for(int i=0; i<d; i+=1){

		int output[size];
    	int j, count[10] = { 0 };
 
    	for (j = 0; j < size; j++){
        	count[(array[j] / bs) % 10]++;
    	}
 
	  
    	for (j = 1; j < 10; j++){
        	count[j] += count[j - 1];
    	}
 

    	for (j = size - 1; j >= 0; j--) {
        	output[count[(array[j] / bs) % 10] - 1] = array[j];
        	count[(array[j] / bs) % 10]--;
   		}
 
    	for (j = 0; j < size; j++){
        	array[j] = output[j];
    	}

    	bs*=10;
	} 
	

}

void PrintArray(int array[], int size){


	for(int i=0; i<size; i++){

		printf("%d ", array[i]);

	}

}


int main(){


	int array[] = {10,2,3,5,5,40,10,89,9,7,7,0,9,5987542,26,3,1,3,6,55,8,8,7,945,5586,0,0};
	int size = sizeof(array)/sizeof(array[0]);

	RadixSort(array, size);

	PrintArray(array, size);

	return 0;
}