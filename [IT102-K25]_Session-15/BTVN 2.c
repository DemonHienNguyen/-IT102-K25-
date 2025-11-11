#include <stdio.h>

void sumOfNumber(int N);


void sumOfNumber(int N){
	int temp;
	int sum = 0;
	int originalNum = N;
	while(N > 0){
		temp = N % 10;
		sum += temp;
		N /= 10;
	}
	printf("Vay tong cac chu so trong so nguyen %d la: %d",originalNum, sum);
}


int main (){
	
	int n;
	printf(" Nhap so nguyen N: ");
	scanf("%d", &n);
	sumOfNumber(n);
	return 0;
}
