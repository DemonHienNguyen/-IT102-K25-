#include <stdio.h>

int i, j;


void linearSearch(int N, int X, int Array[]){
	
int count;
	
	printf("\t----THUAT TOAN TIM TUAN TU----\n");
	printf("Enter your Phan tu: ");
do{
	scanf("%d", &N);
	if(N <= 0){
		printf("Loi ! Vui long nhap lai di ma: ");
		while(getchar() != '\n');
	}
}while(N <=0);
	
	

printf("\tnhap phan tu trong mang \n");
for(i =0; i< N; i++){
	printf("Array[%d] = ", i);
	scanf("%d", &Array[i]);
}

	
	printf("Enter your Gia tri can tim: ");
do{
	scanf("%d", &X);
	if(X <= 0){
		printf("Loi ! Vui long nhap lai di ma: ");
		while(getchar() != '\n');
	}
}while(X <=0);	

	count =0;
	for(i =0; i< N; i++){
		if(Array[i] == X){
			count++;
		}
	}

	printf("Vay Gia Tri %d can tim xuat hien: %d ", X, count);	
}

int main(){
	int n, x;
	int maTran[n];
	
linearSearch(n, x, maTran);
}

