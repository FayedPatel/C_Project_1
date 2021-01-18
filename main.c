#include <stdio.h>
#include <stdlib.h>

void arrayCopy (int fromArray[], int toArray[], int size) {
    // copies fromArray to toArray
    int i;
    for( i = 0; i < size; i++) {
        toArray[i] = fromArray[i];
    }

}

void favoriteSort (int arr[], int size) {

    arr[size];
    int pHolder, i, j;

    for (j= 0; j <size -1; j++) {
        for (i = 0; i < size - j - 1; i++){
            for(i=0;i<size;++i)
                if (arr[i] > arr[i +1]) {
                    pHolder = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = pHolder;
                }
        }
    }
}

int linSearch (int arr[], int size, int target, int* numComparisons) {
    int i = 0;
    for (i = 0; i < size; i++){
        (*numComparisons)++;
        if (arr[i] == target){
            return i;
        }
    }
    return -1;
}

int binarySearch (int arr[], int size, int target, int* numComparisons){

    int middleIndex, minIndex, maxIndex;
    maxIndex = size -1;
    minIndex = 0;

    while(minIndex <= maxIndex){
        (*numComparisons)++;
        middleIndex = (minIndex + maxIndex) /2;
        if (target > arr[middleIndex]) {
            minIndex = middleIndex + 1;
        }
        if (target < arr[middleIndex]){
            maxIndex = middleIndex -1;
        }
        if (target == arr[middleIndex]){
            return middleIndex;
        }
    }
    return -1;
}

int main (){

    int count =0;
    int val = 0;
    int linComparison = 0;
    int binComparison = 0;
    printf ("Enter in a list of numbers followed by the terminal value of -999\n");



    // This code is a modified version of the lab1.c file that will be used in this project

    int *arr1;
    int size = 100;
    int i = 0;

    arr1 = (int *) malloc (size * sizeof(int));
    scanf ("%d", &val);
    while (val != -999) {
        if (count > size){
            int *temp;
            temp = (int *) malloc ( size * 2 * sizeof(int) );
            int i;
            for ( i = 0 ; i < size ; i++)
                temp[i] = arr1[i];
            free (arr1);
            arr1 = temp;
            size = size * 2;
        }
        arr1[count++] = val;
        scanf ("%d", &val);
    }
    // This code is a modified version of the lab1.c file that will be used in this project

    printf("%d\n", count);

    int arr2[size];

    arrayCopy(arr1, arr2, size);

    favoriteSort(arr1, count -1);

    printf("Enter values to be searched into the  followed by -999");
    int searchVal = 0;

    while (searchVal != -999){
        linComparison = 0;
        binComparison = 0;
        scanf("%d", &searchVal);
        if (searchVal == -999){
            break;
        }
        int linSearchSort = linSearch(arr2, count , searchVal, &linComparison);
        int binarySearchSort = binarySearch(arr1, count  , searchVal, &binComparison);

        printf("Searching for the number %d\n", searchVal);
        if (linSearchSort != -1){
            printf("The number %d is in linear search and it took  %d comparisons to find\n", searchVal, linComparison);
        }
        else{
            printf("The number %d was not found in linear search\n", searchVal);
        }
        if(binarySearchSort != -1){
            printf("The number %d is in binary search and it took  %d comparisons to find\n", searchVal, binComparison);
        }
        else{
            printf("The number %d was not found in binary search\n", searchVal);
        }
    }

    return 0;
}