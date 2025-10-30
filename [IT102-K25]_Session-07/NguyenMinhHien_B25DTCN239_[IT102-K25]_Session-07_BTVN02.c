#include <stdio.h>

int main(){
	printf("---TINH GAI THUA--- \n");
	int N, i, Giai_thua = 1;
	
do{
	printf("nhap so nguyen (tu 1 - 1000): ");
	
	if(scanf("%d", &N) != 1){
		
		printf("So nhap khong hop le vui long nhap lai: \n ");
		N =0;
	}
	}while (getchar() != '\n');
	
	for ( i =1; i <= N; i++){
		Giai_thua *= i; 
	}
	
	printf(" \n Giai thua cua N la: %d \n", Giai_thua);
	return 0;
}
