#include <stdio.h>


void bubbleSort(int N, int Array[]);



void bubbleSort(int N, int Array[]){
	int i, j, temp;
	for(i = 0; i < N - 1; i++){
		for(j = 0; j < N- 1-i; j++){
			if(Array[j] > Array[j+1]){
				temp = Array[j];
				Array[j] = Array[j+1];
				Array[j+1] = temp;
			}
		}
	}
	printf("Vay mang sau khi sap xep la: \n");
	for(i=0; i< N; i++){
		printf("\t%5d", Array[i]);
	}
}

int main (){
	
	int i, n;
	printf("Nhap kich co cua mang: ");
do{
	scanf("%d", &n);
	if(n <= 0){
		printf("Loi ! Vui long nhap lai: ");
		fflush(stdin);
	}
}while(n <= 0);
	int maTran[n];
	printf("Nhap phan tu trong mang: \n");
	for(i =0; i < n; i++){
		printf("Array[%d] = ", i);
		scanf("%d", &maTran[i]);
	}
bubbleSort(n,maTran);
	
}
	



