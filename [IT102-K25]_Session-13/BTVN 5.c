#include <stdio.h>

int factorialNumbers(int N);


int factorialNumbers(int N){
	int i;
	int factorial = 1;
	for(i = 1; i <= N; i++){
		factorial *= i;
	}
	printf("Vay Giai thua cua %d la: %d", N, factorial);
	return factorial;
}


int main(){
	int Number;
	printf("Nhap so can nhap: ");
	do{
		scanf("%d", &Number);
		if(Number < 0){
		printf("Loi ! Vui long nhap lai: \n");
		while(getchar() != '\n');
	}
}while(Number < 0);
	
factorialNumbers(Number);
}

int main(){
	int Number;
	printf("Nhap so can nhap: ");
	do{
	if(scanf("%d", &Number) != 1){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar() != '\n');
		continue;
	}
	while(getchar() != '\n');
	if(Number <=0){
		printf("Loi ! Vui long nhap lai: ");
	}
}while(Number <=0);
	
isPrime(Number);
	
	
	
	
}
