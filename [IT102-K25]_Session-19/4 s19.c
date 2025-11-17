#include <stdio.h>

int countValue(int *arr, int n, int x);


int countValue(int *arr, int n, int x){
	int i;
	int count = 0;
	for(i= 0 ; i < n; i++){
		if(*(arr+i) == x){
			count++;
		}
	}
	return count;
}



int main(){
	
	int size, i;
	int search;
	printf("Nhap kich co cua mang: ");
	scanf("%d", &size);
	
	int list[size];
	
	printf("Nhap cac phan tu trong mang: \n");
	for(i= 0; i < size; i++){
		printf("Arrar[%d] = ", i);
		scanf("%d", &list[i]);
	}
	printf("Nhap Gia tri can tim: ");
	scanf("%d", &search);
	int result = countValue(list, size, search);
	printf("Vay so lan %d xuat hien trong mang la: %d", search, result);
	return 0;
}
