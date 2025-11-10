#include <stdio.h>
#include <stdbool.h>
int isPrime(int N);

int isPrime(int N){
	int i;
	if(N < 2){
		return  0;
	}else{
		for(i = 2; i*i <= N;i++){
			if(N % i == 0){
				return 0;
			}
		}
	}
	return 1;
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
	
if(isPrime(Number)){
	printf("%d la so nguyen to", Number);
}else{
	printf("%d KHONG la so nguyen to", Number);
}
	
	
	
	
}


