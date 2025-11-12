#include <stdio.h>
#include <string.h>

int main(){
	
	char string[50];
	printf("Enter you string: ");
	fgets(string, 50, stdin);
	
	int size = (int)strlen(string);
	if(size > 0 && string[size - 1] == '\n' ){
		string[size - 1] = '\0' ;
		size--;
	}
	

	printf("Vay chuoi ban nhap la \n");
	int i;
	for(i = 0; i < size; i++){
		if(i == 0 ){
			printf("%c", string[i]);
		}else{
			printf(" %c", string[i]);
		}
	}
	return  0;	
}
