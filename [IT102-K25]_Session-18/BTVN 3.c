#include <stdio.h>

void sumNumber(int *a, int *b, int *result);

void sumNumber(int *a, int *b, int *result){
	*result = *a + *b;
}

int main(){
	int number1, number2, sum = 0;
	printf("Enter your first number: ");
	scanf("%d", &number1);
	printf("Enter your second number: ");
	scanf("%d", &number2);
	sumNumber(&number1, &number2, &sum);
	printf("Vay tong cua hai so %d va %d la: %d", number1, number2, sum);
	return 0;
}
