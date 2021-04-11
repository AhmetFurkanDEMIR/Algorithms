#include <stdio.h>
#include <stdlib.h>

void QuickSort(int array[], int l, int r){

    int k = l, j = r, sayac, mid, desk;

    mid=array[(l+r)/2];

    do{

        while(mid>array[k] && k < r){
            k++;
        }

        while(mid<array[j] && j>l){
            j--;
        }

        if(k<=j){
            desk=array[k];
            array[k]=array[j];
            array[j]=desk;
            k++;
            j--;
        }

    }while(k<=j);

    if(l<j){
        QuickSort(array,l ,j);
    }

    if(k<r){
        QuickSort(array, k, r);
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

    QuickSort(array, 0, size);
    print(array, size);

    return 0;
}

