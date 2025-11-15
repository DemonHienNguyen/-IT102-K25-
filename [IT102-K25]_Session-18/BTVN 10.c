#include <stdio.h>

void printArray(int *arrPtr, int *lengthPtr);
void deleteValue(int *arrPtr, int *lengthPtr, int *indexPtr);

void printArray(int *arrPtr, int *lengthPtr){
	int i; 
	int length = *lengthPtr;
	printf("Vay mang la: \n");
	for(i= 0; i < length; i++){
		printf("   %d", *(arrPtr + i));
	}
}
void deleteValue(int *arrPtr, int *lengthPtr, int *indexPtr){
	int length = *lengthPtr;
	int index = *indexPtr;
	int i;
	for(i=index;i<length; i++){
		*(arrPtr + i) = *(arrPtr + i +1);
	}
	(*lengthPtr)--;
	printArray(arrPtr, lengthPtr);
}



int main(){
	int size;
	int i;
	int deleteIndedx;
	printf("Enter your size: ");
	scanf("%d", &size);
	
	int arr[size];
	for(i =0; i < size; i++){
		printf("Array[%d] = ", i);
		scanf("%d", arr + i);
	}
	
	printf("Nhap chi so can xoa (0 -> %d): ", size -1);
	do{
		scanf("%d", &deleteIndedx);
		if(deleteIndedx < 0 || deleteIndedx >= size){
			printf("Loi ! Vui long nhap lai: ");
		}
	}while(deleteIndedx < 0 || deleteIndedx >= size);
	deleteValue(arr, &size,&deleteIndedx);
	
	
	return 0;
}

