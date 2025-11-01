#include <stdio.h>

int main(){
	// khai bao mang 
	int i, n;
	int array[100], sizeOfArray;
	//nang cao bang khai bao phan tu n trong array
	
	printf("nhap so phan tu trong mang: ");
	scanf("%d", &n);
	
	sizeOfArray = sizeof(array)/sizeof(int);
	for (i = 0; i < n; i++){
		printf("array[%d] = ", i);
		scanf("%d", &array[i]);
	}
	printf("vay do dai cua mang co gia tri la : %d \n",sizeOfArray );
	printf("vay mang co gia tri la: ");
	for(i=0 ; i < n; i++){
		printf("%d ", array[i]);
	}
	return 0;
}
