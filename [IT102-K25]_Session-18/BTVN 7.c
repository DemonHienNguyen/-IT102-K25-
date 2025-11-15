#include <stdio.h>

void sortArray(int *arrPtr, int lenght);
void printfArray(int *arrPtr, int length);
void swapnum(int *a, int *b);

void swapNum(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void sortArray(int *arrPtr, int length){
	int i, j;
	for(i= 0 ; i < length -1;i++){
		for(j = 0; j < length - i - 1; j++){
			if(*(arrPtr + j) > *(arrPtr + j +1)){
				swapNum(&*(arrPtr + j), &*(arrPtr + j +1));
			}
		}
	}
	printf("\n");
	printfArray(arrPtr, length);
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
	printf("Enter your size: ");
	scanf("%d", &size);
	int arr[size];
	for(i= 0 ; i < size;i++){
		printf("Array[%d] = ", i);
		scanf("%d", arr + i);
	}
	
	sortArray(arr, size);

	
	return 0;
}
