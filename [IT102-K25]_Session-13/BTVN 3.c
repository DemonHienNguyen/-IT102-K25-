#include <stdio.h>


int sum(int A, int B){
	int sum;
	sum = A + B;
	printf("Vay tong hai so %d va %d la: %d", A, B , sum);
}

int main(){
	
	int number1, number2;
	
	printf("Nhap so thu nhat: ");
do{
	if(scanf("%d",&number1) != 1){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar() !='\n');
		continue;
	}
	while(getchar() != '\n');
	if(number1 <= 0){
		printf("So phai la so duong: ");
	}
}while(number1 <= 0);
	
	printf("Nhap so thu hai: ");
do{
	if(scanf("%d",&number2) != 1){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar() !='\n');
		continue;
	}
	while(getchar() != '\n');
	if(number2 <= 0){
		printf("So phai la so duong: ");
	}
}while(number2 <= 0);
sum(number1, number2);
}


