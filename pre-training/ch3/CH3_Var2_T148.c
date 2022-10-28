#include <stdio.h>

int p1();
int p2(); 

int main(){
	int rep; 
	
	scanf("%d", &rep); 
	getchar(); 
	
	int i; 
	long long int score[rep];
	for (i=0; i<rep; i++){
		scanf("%d", &score[i]); 
		getchar();
	}
	
	long long int resultP1 = p1(score, rep);
	long long int resultP2 = p2(score, rep-1);
	
	if (resultP1 > resultP2) printf("TRUE\n"); 
	else printf("FALSE\n"); 
	
	
	return 0; 
}

int p1(long long int *score, int rep){
	if (rep <= 0) return 0; 
	
	return score[rep]+p1(score, rep-2); 
}

/*
int p1Reverse(int *score, int i){
	if (rep <= 0) return 1; 
	
	return score[rep]+chance(score, i+2); 
}*/


int p2(int *score, int rep){
	if (rep <= 0) return 0; 
	
	return score[rep]+p2(score, rep-2); 
}

/*
int p2(int *score, rep){
	if (rep <= 0) return 1; 
	
	return score[rep]+chance(score, rep-2); 
}*/



