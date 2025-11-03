#include <stdio.h>
#include <stdlib.h>

int i, j;

void inMaTran(int N, int array[N][N]){
	
int doRongMaTran =0;
int temp, maxArray;

maxArray = N*N;
temp = maxArray;
	
	while(temp != 0){
		temp /= 10;
		doRongMaTran++;
	}
	
	for(i = 0; i <N; i++){
		for(j =0; j <N; j++){
			printf("\t%*d", doRongMaTran, array[i][j]);
		}
	printf("\n");
	}
}

int main(){
	
int n;
int giaTriMaTran = 1;

	printf("nhap so nguyen n: ");

do{
	if(scanf("%d", &n) != 1 || n <= 0){
		printf("loi ! Vui long nhap lai:");
	}
}while(n <= 0);

int maTran[n][n] ;

	for(i=0; i <n; i++){
		for(j =0; j< n;j++){
			maTran[i][j] = giaTriMaTran;
			giaTriMaTran++;
		}
	}

inMaTran(n, maTran);

return 0;

}
