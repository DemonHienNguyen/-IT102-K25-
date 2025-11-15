#include <stdio.h>

void updateValue(int *arr2Ptr, int *indexUpdate, int *newValue);
void printArray(int *arrPtr, int length);


void printArray(int *arrPtr, int length){
	int i;
	printf("Vay mang la: \n");
	for(i= 0; i < length; i++){
		printf("\t%5d", *(arrPtr+i));
	}
	
}
void updateValue(int *arr2Ptr, int *indexUpdate, int *newValue){
	*(arr2Ptr + *indexUpdate) = *newValue;
}


int main(){
	int i, size;
	int updateIndex, value;
	
	printf("Nhap kich co cua mang: ");
	scanf("%d", &size);
	int arr[size];
	printf("Nhap cac phan tu trong mang: \n");
	for(i= 0; i <size; i++){
		printf("Array[%d] = ",  i);
		scanf("%d", arr + i);
	}
	printArray(arr,size);
	printf("\nNhap chi so ma ban muon cap nhap (0 - > %d): ", size -1);
	do{
		scanf("%d", &updateIndex);
		if(updateIndex >= size || updateIndex < 0){
			printf("Loi ! Vui long nhap lai ho cai: ");
		}
	}while(updateIndex >= size || updateIndex < 0);
	printf("Nhap Gia tri ma ban muon nhap: ");
	scanf("%d", &value);
	updateValue(arr, &updateIndex, &value);
	printArray(arr,size);
	
	
	
	return 0;
}
