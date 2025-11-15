#include <stdio.h>

void swap(int *a, int *b);

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}



int main(){
	int number1, number2;
	printf("Enter your first number: ");
	scanf("%d", &number1);
	printf("Enter your second number: ");
	scanf("%d", &number2);
	printf("Hai so truoc khi doi: %d, %d \n", number1, number2);
	swap(&number1, &number2);
	printf("Hai so sau khi doi la: %d, %d \n", number1, number2);

	
	return 0;
}
