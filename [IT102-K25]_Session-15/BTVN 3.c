#include <stdio.h>

void reverseNumber(int N);


void reverseNumber(int N){
	int reverse = 0, i;
	while(N >0){
		i = N % 10;
		reverse = reverse*10 + i;
		N /= 10;
	}
	printf("Vay so dao nguoc la: %d",reverse);
}

int main(){
	int n;
	printf("Nhap so nguyen n: ");
	scanf("%d", &n);
	reverseNumber(n);
	
}


