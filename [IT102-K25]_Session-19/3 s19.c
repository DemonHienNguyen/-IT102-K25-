#include <stdio.h>

float averageArray(int *arr, int n);

float averageArray(int *arr, int n){
	float average;
	int i;
	for(i = 0; i < n; i++){
		average += *(arr + i);
	}
	return average/n ;
}


int main(){
	
	int size, i;
	
	printf("Nhap kich co cua mang: ");
	scanf("%d", &size);
	
	int list[size];
	
	printf("Nhap cac phan tu trong mang: \n");
	for(i= 0; i < size; i++){
		printf("Arrar[%d] = ", i);
		scanf("%d", &list[i]);
	}
	float result = averageArray(list, size);
	printf("Vay trung binh cua mang la: %.1f", result);
	return 0;
}
