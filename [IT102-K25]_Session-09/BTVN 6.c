#include <stdio.h>

int i;

void averageNum(int N, int array[N]){
	
float average = 0;

	for(i = 0; i < N; i++){
		average += array[i];
	} 
printf("\tTrung binh cong cua mang la: %.2f", average/N);
}

int main(){
	
int n;

	printf("\t----------TINH TRUNG BINH CONG----------\n");
	printf("\tnhap so phan tu trong mang: ");
do{
	if (scanf("%d",&n) != 1 || n <=0){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar() != '\n');
	}
}while(n <=0);

int maTran[n];

printf("\tNhap phan tu vao mang: \n");
	for(i=0; i< n; i++){
		printf("array[%d]: ", i);
		scanf("%d", &maTran[i]);
	}
	printf("\t------VAY MANG LA------\n");
	for(i= 0; i <n; i++){
		printf("\t%d", maTran[i]);
		
	}
averageNum(n, maTran);
}

