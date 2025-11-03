#include <stdio.h>

int i, j;

void inPhanTuXuatHienNhieuNhat(int N, int array[N]){
	
int maxCount =0;
int elementCount;
int most_Frequent_Element  = array[0];

	for(i = 0; i <N; i++){
		elementCount = array[i];
		int count = 0;
		for(j = 0; j < N; j++){
			if(elementCount == array[j]){
				count++;
			}
		}
		if(count > maxCount){
			maxCount = count;
			most_Frequent_Element = elementCount;
		}
	}

printf("\tvay phan tu xuat hien nhieu nhat trong mang la: %d", most_Frequent_Element);
printf("\n\tVoi tan so xuat hien la: %d ", maxCount);
}

int main(){

int n;

printf("\tnhap so phan tu (n >0):  ");
do{
	if(scanf("%d", &n) != 1 || n <=0){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar() != '\n');
	}
}while(n<=0);

int maTran[n];

printf("\tnhap phan tu o vi tri: \n");
	for(i=0; i<n;i++){
			printf("array[%d]: ", i);
			scanf("%d", &maTran[i]);
		}
printf("\n");
	
printf("\t----------VAY MANG LA----------\n");
	for(i=0; i<n;i++){
			printf("\t%5d", maTran[i]);
		}
printf("\n");

inPhanTuXuatHienNhieuNhat(n, maTran);
}

