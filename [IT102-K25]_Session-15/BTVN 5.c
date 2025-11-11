#include <stdio.h>

void most_Frequently_Appearing_Number(int N, int Array[]);

void most_Frequently_Appearing_Number(int N, int Array[]){
	int count, i, j, maxCount = 1, frequentlyNum = 0;
	int value;
	for(i = 0; i < N; i++){
		value = Array[i];
		count = 0;
		for(j = 0; j < N; j++){
			if(value == Array[j]){
				count++;
			}
		}
		if(count > maxCount){
			frequentlyNum = value;
			maxCount = count;
		}
	}
	printf("\nVay so xuat hien nhieu nhat la: %d", frequentlyNum);
	printf("\nVoi tan so xuat hien la: %d",maxCount);
}


int main(){
	
	int size, i;
	printf("Nhap kich thuoc cua mang: ");
	scanf("%d", &size);
	
	int arr[size];
	printf("Nhap so phan tu trong mang: \n");
	for(i = 0; i < size; i++){
		printf("Array[%d] = ",  i);
		scanf("%d", &arr[i]);
	}
	printf("Vay mang la: \n");
	for(i = 0; i < size; i++){
		printf("\t%5d", arr[i]);
	}
	
	most_Frequently_Appearing_Number(size, arr);
	
	return 0;
}

