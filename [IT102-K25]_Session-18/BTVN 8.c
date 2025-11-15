#include <stdio.h>
#include <string.h>

void reverseChar(char *str, int length, char*str2);
void swapChar(char *a, char *b);

void swapChar(char *a, char *b){
	char temp = *a;
	*a = *b;
	*b = temp;
}

void reverseChar(char *str, int length, char*str2){
	int i = 0 , j = length -1;
	while(i < j){
		swapChar(str + i, str + j);
		i++;
		j--;
	}
	strcpy(str2, str);
	
}

int main(){
	char inputString[100], reverseString[100];
	printf("Enter your string: ");
	fgets(inputString, 100, stdin);
	inputString[strcspn(inputString, "\n")] = '\0';
	int size = (int)strlen(inputString);
	
	printf("chuoi truoc khi dao nguoc la: \"%s\"", inputString);
	reverseChar(inputString, size, reverseString);
	printf("\nVay mang sau khi dao nguoc la: \"%s\"", reverseString);
	return 0;
}
