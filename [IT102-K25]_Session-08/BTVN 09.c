#include <stdio.h>
#include <stdlib.h>
int i, j;

void sap_Xep_SoTheo_Duong_Bien(int R, int C, int array[R][C]){
	printf("\n****MA TRAN THEO DUONG BIEN*** \n");
	// neu chi co 1 hang	
	if(R == 1){
		for(j= 0; j < C;j++){
			printf("%d ", array[0][j]);
		}
	// neu chi co 1 cot
	}else if(C == 1){
		for(i =0; i< R; i++){
			printf("%d ", array[i][0]);
		}
	// vi du o 3 x 3
	// neu ca cot va hang nhieu hon 1
	}else if(R > 1 && C > 1){
		for(i = 0; i < R; i++){
			for(j = 0; j < C; j++){
				if(i ==0 || i == R-1 || j==0 || j== C-1){
					printf("%5d", array[i][j]);
				}else{
					printf("     ");
				}
			}
			printf("\n");
		}
	printf("\n");	
	}
}


void nhap_Va_In_Ma_Tran(){
	
	int r,c; 
do{
	printf("nhap so hang cua ban: ");
	if(scanf("%d", &r) != 1 || r <=0){
		printf("so khong hop le ! \n");
		while(getchar() != '\n');
	}
}while(r <= 0);

do{
	printf("nhap so cot cua ban: ");
	if(scanf("%d", &c) != 1 || c <=0){
		printf("so khong hop le ! \n");
		while(getchar() != '\n');
	}
}while(c <= 0);

int maTran[r][c];

printf("---NHAP PHAN TU VAO MANG--- \n");
	for(i = 0; i < r;i++){
		for(j = 0; j < c;j++){
			printf("Gia tri o vi tri [%d][%d]: ", i, j);
			while(scanf("%d", &maTran[i][j]) != 1){
				printf("loi ! vui long nhap lai du lieu: ");
				while(getchar() != '\n');
			}
		}
	}
printf("vay ma tran co dang: \n");
for(i = 0; i < r;i++){
		for(j = 0; j < c;j++){
			printf("%5d", maTran[i][j]);
		}
		printf("\n");
	}
sap_Xep_SoTheo_Duong_Bien(r,c,maTran);
}

int main(){
	
	nhap_Va_In_Ma_Tran();
	
	return 0;
	
}
