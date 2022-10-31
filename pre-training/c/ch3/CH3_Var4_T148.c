#include <stdio.h>

int botMove(); 

int main(){
	int row, col, bot_col, bot_row=0, orenji=0; 
	
	scanf("%d %d %d", &row, &col, &bot_col); 
	getchar(); 
	
	int area[row][col], i, j; 
	for (i=0; i<row; i++){
		for (j=0; j<col; j++){
			scanf("%d", &area[i][j]);
			getchar(); 
		}
	}
	
	int orangeSum = botMove(area, row, col, bot_col, bot_row, orenji); 
	printf("%d\n", orangeSum); 
	
	return 0;  
}

int botMove(int *area, int row, int col, int bot_col, int bot_row, int orenji; ){
//		int bot_pos[row][col]; 
		int current_column=bot_col; 
		int current_row=bot_row; 
		int farm_col=col; 
		int farm_row=row; 
		int orenji=orenji;
				
	if (current_column==0 && current_row != farm_row-1){
//		column is on the furthest left. bot can only move right

		orenji += area[current_column][current_row];
		return botMove(area, row, col, bot_col++, bot_row--)
		
	} else if (current_column == farm_col-1 && current_row != farm_row-1){
//		column is on the furthest right. bot can only move left

		orenji += area[current_column][current_row];
		return botMove(area, row, col, bot_col--, bot_row++)
		
	} else return orenji;
}
