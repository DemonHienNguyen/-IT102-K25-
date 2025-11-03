#include <stdio.h>



int i, j;

void inMaTranCheo(int N, int array[N][N]){

int sum =0;

	printf("\t----------VAY CAO SO CHEO LA----------\n");
	for(i = 0; i < N;i++){
		for(j =0; j < N; j++){
			if(i==j){
				printf("          %5d",array[i][j]);
				sum += array[i][j];
			}else{
				printf("       ");
			}
		}
	printf("\n");
	}
printf("\t----------TONG CAC SO CHEO LA: %d", sum);
}



int main(){

int n;

printf("\tnhap so nguyen (n >0):  ");
do{
	if(scanf("%d", &n) != 1 || n <=0){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar() != '\n');
	}
}while(n<=0);

int maTran[n][n];

printf("\tnhap phan tu o vi tri: \n");
	for(i=0; i<n;i++){
		for(j=0;j<n;j++){
			printf("array[%d][%d]: ", i, j);
			scanf("%d", &maTran[i][j]);
		}
	}
printf("\n");
	
printf("\t----------VAY MANG LA----------\n");
	for(i=0; i<n;i++){
		for(j=0;j<n;j++){
			printf("\t%5d", maTran[i][j]);
		}
	printf("\n");
	}
inMaTranCheo(n, maTran);
return 0;
}
