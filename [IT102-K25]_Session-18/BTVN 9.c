#include <stdio.h>

void addValue(int *arrPtr, int *lengthPtr, int *IndedxPtr, int *NumberPtr);
void printfArray(int *arrPtr, int length);

void addValue(int *arrPtr, int *lengthPtr, int *IndedxPtr, int *NumberPtr){
	int i; 
	int length = *lengthPtr;
	int index = *IndedxPtr;
	int number = *NumberPtr;
	for(i = length; i >= index; i--){
		*(arrPtr + i + 1) = *(arrPtr + i);
	}
	*(arrPtr + index) = number;
	(*lengthPtr)++;
	printfArray(arrPtr, *lengthPtr);
}

void printfArray(int *arrPtr, int length){
	int i;
	printf("Vay mang la: \n");
	for(i= 0; i < length; i++){
		printf("  %d", *(arrPtr + i));
	}
}
int main(){
	int size;
	int i;
	int addIndedx, valueToAdd;
	printf("Enter your size: ");
	scanf("%d", &size);
	
	int arr[size];
	for(i =0; i < size; i++){
		printf("Array[%d] = ", i);
		scanf("%d", arr + i);
	}
	
	printf("Nhap chi so can them (0 -> %d): ", size -1);
	do{
		scanf("%d", &addIndedx);
		if(addIndedx < 0 || addIndedx > size){
			printf("Loi ! Vui long nhap lai: ");
		}
	}while(addIndedx < 0 || addIndedx > size);
	printf("Nhap gia tri ma ban muon them: ");
	scanf("%d", &valueToAdd);
	addValue(arr, &size, &addIndedx, &valueToAdd);
	
	
	
	return 0;
}
