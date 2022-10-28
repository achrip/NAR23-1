#include <stdio.h>
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b; 
    *b = tmp; 
}

void printArray(int n, int arr[]){
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    puts(" ");
}
void bubbleSort(int arr[], int n){
    // int n = sizeof(arr)/sizeof(int); 
/*
    the same thing (finding the array size) can also be done within a function, but we forgot how to.
    hence we need to pass n from the main function to make this work
*/    

    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-1-i;j++){    
            if (arr[j] > arr[j+1]){ // n-1 is to make sure we don't overextend the sort beyond the array. 
                swap(&arr[j], &arr[j+1]);
            }
        }                               // the -i is to make sure we don't end up sorting the already sorted index
    }

}

void linearSearch(int *arr, int n, int target){
    for (int i=0; i<n; i++){
        if (arr[i]==target){
            printf("%d was found in the array.\n", target);
            return; 
        }
    }
    printf("%d was not found in the array.\n", target);
}

void binarySearch(int n, int *arr, int target){
    int low = 0; 
    int high = n-1; 

    while (high >= 1){
        // int mid = (high + low)/2;       //this is less safe
        int mid = low + (high - low)/2; // this is safer option to declare mid

        if (arr[mid] < target){
            low = mid + 1; 
        } else if (arr[mid] == target){
            printf("%d was found in the array.\n", target);
            return;
        } else {
            high = mid - 1;
        }

    }
}
int main(){
/*
    Bubble Sort
    is the easiest yet has the longest time type of array sorting. this is caused 
    because we traverse the array for every index to find the biggest value or 
    the value we want. 
*/
    int arr[] = {4, 1, 7, 3, 5, 8, 2, 6};

    // create a variable to find/check the array size. 
    // sizeof(arr) is the cumulative size of used bytes in the array,
    int n = sizeof(arr)/sizeof(int);

    // this is the array pre-sorting
    printArray(n, arr); 
    // pass the array (pass by reference) to the bubbleSort function
    bubbleSort(arr, n); 
    //this is the array post-sorting
    printArray(n, arr); 


/*
    Linear Search
    we traverse the array to search for the value that we need.
    time complexity: O(n)

*/
    int target = 7; 
    linearSearch(arr, n, target);

/*
    Binary Search 
    we search the array by dividing it into two. and it will keep doing so until we found the value we are looking for.
    while dividing it into two, we still use the search target as reference. 
*/

    binarySearch(n, arr, target);
    return 0; 
}

