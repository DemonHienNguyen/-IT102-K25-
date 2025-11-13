#include <stdio.h>
#include <string.h>


int main(){
	char listOne[100], listTwo[100];
	printf("Enter your first string: ");
	fgets(listOne, 100, stdin);
	listOne[strcspn(listOne, "\n")] = '\0'; 
	int sizeOne = (int)strlen(listOne);
	
	printf("Enter your second string: ");
	fgets(listTwo, 100, stdin);
	listTwo[strcspn(listTwo,"\n")] = '\0';
	int sizeTwo = (int)strlen(listTwo);
	
	strcat(listOne, listTwo);
	
	printf("%s", listOne);
	
	return 0;
}

