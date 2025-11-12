#include <stdio.h>
#include <string.h>

int main(){
	char list[100];
	int i;
	printf("Enter your string: ");
	fgets(list, 100, stdin);
	
	int size = (int)strlen(list); 
	
	if(size > 0 && list[size -1] == '\n'){
		list[size -1] = '\0';
		size--;
	}
	
	int count = 0;
	int appare = 0;
	for(i= 0; i < size; i++){
		if(list[i] == ' '){
			appare = 0;
		}else if(!appare){
			appare = 1;
			count++;
		}
	}
	printf("Vay trong \"%s\" xuat hien %d tu !", list, count);
	
}
