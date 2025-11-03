#include <stdio.h>
#include <math.h>

int i, j;


void sumArayBorder(int R, int C, int array[R][C]){
	
int sum =0;

printf("\t----------TINH TONG THEO DUONG BIEN----------\n");
	if(R == 1){
		for(j = 0; j < C; j++){
			sum += array[0][j];
		}
	}else if(C == 1){
		for(i =0; i < R; i++){
			sum += array[i][0];
		}
	}else if(R >1 && C >1){
		// vi du 3  x 3
		for(j = 0; j < C; j++){
			sum += array[0][j];
		}
		for(i = 1; i < R; i++){
			sum += array[i][C-1];
		}
		for(j = C -2;j >= 0; j--){
			sum += array[R-1][j];
		}
		for(i = R-2; i > 0; i--){
			sum += array[i][0]; 
		}
	}
printf("\n");
printf("\tVay tong cac chu so o ngoai bien la: %d", sum);
}


int main(){
	int r, c;
printf("\tnhap so hang (r >0):  ");
do{
	if(scanf("%d", &r) != 1 || r <=0){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar() != '\n');
	}
}while(r<=0);
printf("\tnhap so cot (c >0):  ");
do{
	if(scanf("%d", &c) != 1 || c <=0){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar() != '\n');
	}
}while(c<=0);

int maTran[r][c];

printf("\tnhap phan tu o vi tri: \n");
	for(i=0; i<r;i++){
		for(j=0;j<c;j++){
			printf("array[%d][%d]: ", i, j);
			scanf("%d", &maTran[i][j]);
		}
	}
printf("\n");
	
printf("\t----------VAY MANG LA----------\n");
	for(i=0; i<r;i++){
		for(j=0;j<c;j++){
			printf("\t%5d", maTran[i][j]);
		}
	printf("\n");
	}
	
sumArayBorder(r, c, maTran);
}
