#include <stdio.h>

void deleteValue(int N, int Array[]);


void deleteValue(int N, int Array[]){
	int i, j, k, value, count, maxCount = 1;
		for (i = 0; i < N; i ++){
			value = Array[i];
			for(j = i+1; j < N; j++){
				if(value == Array[j]){
					for(k = j; k < N -1; k++){
						Array[k] = Array[k+1];
					}
					N--;
					j--;
				}
			}
		}
	printf("Vay cac phan tu sau khi xoa la: \n");
	for(i = 0; i < N; i++){
		printf("\t%5d", Array[i]);
	}
}


int main(){
	int size, i;
	printf("Nhap kich thuoc cua ban: ");
	scanf("%d", &size);
	int list[size];
	printf("Nhap phan tu trong mang: \n");
	for(i =0; i< size; i++){
		printf("Array[%d] = ", i);
		scanf("%d", &list[i]);
	}
	deleteValue(size, list);
	
}
