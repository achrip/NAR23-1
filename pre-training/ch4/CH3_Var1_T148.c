#include <stdio.h>

int gcd(); 

int main(){
	long long int rep;
	int i; 
	
	
	scanf("%lld", &rep);
	getchar(); 
	
	int given[rep];
	for (i=0; i<rep; i++){
		scanf("%d", &given); 
		getchar(); 
	}
	
	int result = gcd(given, rep); 
	
	printf("%d\n", result); 	
	
	
	return 0; 
}

int gcd(int given[], long long int rep){
//	int tmp = given[rep]; 

	if (rep<=0){
		return 1;
	}
	
	return given[rep]/gcd(given, rep-1);
}
