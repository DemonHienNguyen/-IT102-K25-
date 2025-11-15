#include <stdio.h>

int main(){
	
	int number;
	printf("Enter your Number: ");
	scanf("%d", &number);
	printf("---Su dung bien thuong---\n");
	printf("Vay gia tri cua number la: %d \n", number);
	printf("Vay dia chi cua number la: %lu \n", (unsigned long*)&number);
	
	int *numPrt  = &number; 
	printf("---Su dung con tro---\n");
	printf("Vay gia tri cua nummber la: %d \n", *numPrt);
	printf("Vay dia chi cua number la: %lu \n", (unsigned long*)numPrt);
	return 0;
}
