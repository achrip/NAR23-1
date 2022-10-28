#include <stdio.h>

int main(){
	int map_length, map_width, city_count; 
	char forerunner; 
	int i, j; 
	
	scanf("%d %d", &map_length, &map_width); 
	getchar();
	
	
	scanf("%d", &city_count); 
	getchar(); 
	
	scanf("%c", &forerunner); 
	getchar();
	
	char map[map_length][map_width], cities[map_length][map_width]; 
	for (i=0; i<map_length; i++){
		for (j=0; j<map_length; j++){
			scanf("%c", map[i][j]);
			getchar(); 
			
			if (map[i][j]>='A' && map[i][j]<='U') cities[i][j] = map[i][j]; 
		}
	}
	
	aftermath = viruSpread(map, cities, forerunner);
	return 0; 
}

int viruSpread(char *map, char cities, char forerunner){
	/*
	find coordinate of forerunner, then determine if the surrounding is . or #
	if . then change to * (meaning that they are contaminated), if # then ignore
	*/
	
	if (/*forerunner coord*/)
	
}
