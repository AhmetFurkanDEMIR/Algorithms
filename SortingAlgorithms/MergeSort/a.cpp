#include <stdio.h>
#include <stdlib.h>

void Merge(int array[], int l, int m, int r){

    int i, j, k;

    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1];
    int R[n2];

    for(i=0; i<n1;i++){
        L[i] = array[l+i];
    }

    for(j=0; j<n2; j++){
        R[j] = array[m+1+j];
    }

    i=0;
    j=0;
    k=l;

    while(i < n1 && j < n2){

        if(L[i] <= R[j]){
            array[k] = L[i];
            i++;
        }

        else{
            array[k] = R[j];
            j++;
        }

        k++;

    }

    while(i < n1){
        array[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        array[k] = R[j];
        j++;
        k++;
    }


}

void MergeSort(int array[], int l, int r){

    if(l<r){

        int m = (l+r)/2;
        MergeSort(array, l, m);
        MergeSort(array, m+1, r);

        Merge(array, l, m, r);

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

    MergeSort(array, 0, size-1);
    print(array, size);

    return 0;
}