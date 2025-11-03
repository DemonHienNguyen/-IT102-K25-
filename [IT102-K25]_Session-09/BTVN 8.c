#include <stdio.h>

int i, j;

void xuatVaTongCheoPhu(int N, int array[N][N]){

int k;
int sum =0;


printf("\t-----CAC PHAN TU CHEO TRONG MANG LA-----\n   ");
	for(i = 0; i < N; i++){
		k = N -1- i;
		if(k >= 0){
			printf("\t %5d", array[i][k]);
			sum += array[i][k];
		}else{
			break;
		}
	}
printf("\n");
printf("\t-----TONG CAC PHAN TU CHEO TRONG MANG LA-----\n");
printf("\t\t\t %5d", sum);
}


int main(){
	
	int n;
	
	printf("\tnhap so nguyen N: ");
do{
	if(scanf("%d", &n) != 1 || n <=0){
		printf("loi ! Vui long nhap lai: ");
	}
}while(n <= 0);

int maTran[n][n];

printf("\t-----NHAP PHAN TU TRONG MANG-----\n");
	for(i = 0; i < n; i++){
		for(j = 0; j <n; j++){
			printf("Array[%d][%d]: ", i, j);
			scanf("%d", &maTran[i][j]);
		}
	}
printf("\t-----VAY MANG LA-----\n ");
	for(i =0; i< n; i++){
		for(j = 0; j < n; j++){
			printf("\t %5d", maTran[i][j]);
		}
	printf("\n");
	}
xuatVaTongCheoPhu(n, maTran);
return 0;
}
