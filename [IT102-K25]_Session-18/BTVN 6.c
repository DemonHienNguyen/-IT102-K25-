#include <stdio.h>

void printArray(int *arrPtr, int length);
int findValue(int *arrPtr, int length ,int *fValue);



void printArray(int *arrPtr, int length){
	int i;
	printf("Vay mang la: \n");
	for(i = 0; i < length;i++){
		printf("  %5d", *(arrPtr+i));
	}
	printf("\n");
}
int findValue(int *arrPtr, int length ,int *fValue){
	int i;
	for(i = 0;i < length;i++){
		if(*(arrPtr + i) ==  *fValue){
			return i;
		}
	}
	return 0;
}



int main(){
	
	int i, size;
	int value;
	
	printf("Nhap kich co cua mang: ");
	scanf("%d", &size);
	int arr[size];
	printf("Nhap cac phan tu trong mang: \n");
	for(i= 0; i <size; i++){
		printf("Array[%d] = ",  i);
		scanf("%d", arr + i);
	}
	printArray(arr, size);
	printf("Nhap gia tri can tim: ");
	scanf("%d", &value);
	int relust = findValue(arr, size ,&value);
		printf("\t%d", relust);
	return 0;
}
