#include <stdio.h>


int findMax(int *arrPtr, int n);

int findMax(int *arrPtr, int n){
	int i;
	int max = *(arrPtr);
	for(i=0;i < n; i++){
		if(max < *(arrPtr + i)){
			max = *(arrPtr + i);
		}
	}
	printf("Vay gia tri lon nhat trong mang la: %d", max);
	return max;
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
	int result = findMax(list, size);
	return 0;
}
