#include <stdio.h>


copyArray(int *src, int *dest, int n);

copyArray(int *src, int *dest, int n){
	int i; 
	for(i= 0 ;i <n; i ++){
		*(dest + i) = *(src + i);
	}
	
	printf("Copy thanh cong ! \n");
}


int main(){
	int list2[100];
	int size, i;
	printf("Nhap kich co cua mang: ");
	scanf("%d", &size);
	
	int list[size];
	
	printf("Nhap cac phan tu trong mang thu nhat: \n");
	for(i= 0; i < size; i++){
		printf("Arrar[%d] = ", i);
		scanf("%d", &list[i]);
	}

	
	copyArray(list, list2, size);
	
	printf("Vay mang thu 2 sau khi copy tu mang thu nhat la: \n");
	for(i = 0; i < size; i++){
		printf("  %d", list2[i]);
	}
	return 0;
}
