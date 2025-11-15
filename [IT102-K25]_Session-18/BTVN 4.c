#include <stdio.h>

void printArray(int *arrPtr, int length);

void printArray(int *arrPtr, int length){
	int i;
	printf("Vay mang la: \n");
	for(i= 0; i < length; i++){
		printf("\t%5d", *(arrPtr+i));
	}
	
}

int main(){
	int i, size;
	printf("Nhap kich co cua mang: ");
	scanf("%d", &size);
	int arr[size];
	printf("Nhap cac phan tu trong mang: \n");
	for(i= 0; i <size; i++){
		printf("Array[%d] = ",  i);
		scanf("%d", arr + i);
	}
	printArray(arr, size);
	
	return 0;
	
}
