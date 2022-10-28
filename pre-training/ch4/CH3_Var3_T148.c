#include <stdio.h

int minMax(); 

int main(){
	int rep; 
	
	scanf("%d", &rep); 
	getchar(); 
	
	int arr[rep], i;
	for (i=0; i<rep; i++){
		scanf("%d", &arr[i]); 
		getchar(); 
	}
	
	result = minMax(); 
	
	printf("%d\n", result);
	
	return 0; 
}

int minMax(int *arr, int n){

	if (n%2==0){
		if (arr[n] > arr[n+1]) {
			min = arr[n+1];
			newArr[n] = min; 
		}
	
	}else{
	 	if (arr[n] > arr [n+1]){
	 		max = arr[n+1];
			newArr[n] = max; 
		 }
		
	}
		

	return minMax(arr, n+2); 
}
