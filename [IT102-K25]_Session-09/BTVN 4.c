#include <stdio.h>
int i, j;

void maxArray(int R, int C, int array[R][C]){
int max;
int vi_Tri_Hang, vi_Tri_Cot;	
max = array[0][0];
int count =0;
	for(i= 0; i < R; i++){
		for(j =0;j< C;j++){
			if(array[i][j] > max){
				max = array[i][j];
			}
		}
	}
	for(i=0;i< R; i++){
		for(j=0;j <C;j++){
			if(max == array[i][j]){
				count++;
				printf("\n\tphan tu lon nhat trong mang la : %d o vi tri [%d][%d]", max, i, j);
			}
		}
	}
	printf("\n\tso %d xuat hien trong mang la: %d", max, count);
	
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
maxArray(r, c, maTran);
return 0;
}
