#include <stdio.h>

void perfectNumber(int N);

void perfectNumber(int N){
	
	int i, sum = 0;
	for(i= 1; i < N; i++){
		if(N % i == 0){
			sum += i;
		}
	}
	if(sum == N){
		printf("So %d la so hoan hao !", N);
	}else{
		printf("So %d khong phai la so hoan hao !", N);
	}
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
	
perfectNumber(Number);
return 0;	

}

