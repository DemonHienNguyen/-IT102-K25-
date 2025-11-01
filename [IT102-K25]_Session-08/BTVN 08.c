#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int tinh_Do_Rong_Cot(int R, int C, int arr[R][C]){
	int max_abs = 0;
	int i, j;
	
	for(i = 0; i < R; i++){
		for(j = 0; j < C;j++){
			int val_abs = abs(arr[i][j]);
			if (val_abs > max_abs){
				max_abs = val_abs;
			}
		}
	}
	int width = 1;
	if(max_abs > 0){
		width = (int)log10(max_abs)+1;
	}
	return width + 3;
}

void nhapVaInMaTran(){
	int r,c;
	int i,j;
	
	printf("******NHAP VA IN MA TRAN***** \n");

printf("\n");
do{
	printf("nhap so hang cua ban: ");
	if(scanf("%d", &r) != 1 || r <=0 ){
		printf("so nhap phai la so nguyen duong ! \n");
		while(getchar() != '\n');
	}
}while(r <= 0);
	
do{
	printf("nhap so cot cua ban: ");
	if(scanf("%d", &c) != 1 || c <=0){
		printf("so nhap phai la so nguyen duong !\n");
		while(getchar() != '\n');

}
}while(c <= 0);

int mangHaiChieu [r][c];

printf("\n----NHAP CAC PHAN TU CUA MANG--- \n");


for(i =0; i < r; i++){
	for(j =0; j < c; j++){
		printf("nhap phan tu o vi tri [%d][%d]: ", i, j);
		while(scanf("%d", &mangHaiChieu[i][j]) !=  1){
			printf("gia tri khong hop le ! vui long nhap lai: ");
			while(getchar() != '\n');
		}
	}
}

int do_rong_Cot = tinh_Do_Rong_Cot(r,c,mangHaiChieu);

	printf("\nvay ma tran co dang: \n");
	for(i =0; i < r; i++){
		for(j =0; j < c; j++){	
			printf("%*d", do_rong_Cot , mangHaiChieu[i][j]);
	
		}
	printf("\n");
	}
}


int main(){
	nhapVaInMaTran();
	return 0;
}
