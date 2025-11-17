#include <stdio.h>

void countEvenOdd(int *arr, int n, int *even, int *odd);
	
void countEvenOdd(int *arr, int n, int *even, int *odd){
	int i;
	*even = 0;
	*odd = 0;
	for ( i = 0 ;i < n ;i ++){
		if(*(arr+i) % 2 == 0){
			(*odd)++;
		}else{
			(*even)++;
		}
	}
	printf("Vay so chan trong mang la: %d \n", *odd);
	printf("Vay so le trong mang la: %d", *even);
}


int main(){
	int chan , le ;
	int size, i;
	printf("Nhap kich co cua mang: ");
	scanf("%d", &size);
	
	int list[size];
	
	printf("Nhap cac phan tu trong mang: \n");
	for(i= 0; i < size; i++){
		printf("Arrar[%d] = ", i);
		scanf("%d", &list[i]);
	}
	countEvenOdd(list, size, &le, &chan);
	return 0;
}
