#include <stdio.h>
#include <ctype.h>
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
	int space_Appare = 0;
	for(i = 0; i < size; i++){
		if(list[i] == ' '){
			space_Appare = 0;
		}else if(!space_Appare){
			space_Appare = 1;
			list[i]= toupper(list[i]);
		}else{
			list[i] = tolower(list[i]);
		}
	}
	printf("Vay chuoi sau khi chinh la: %s", list);
	
	return 0;
}

