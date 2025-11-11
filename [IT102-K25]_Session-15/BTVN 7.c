#include <stdio.h>

void bubbleSort(int N, int Array[]);
void binarySearch(int N, int Search, int Array[]);


void bubbleSort(int N, int Array[]){
	int i, j, temp;
	for(i = 0; i < N - 1; i++){
		for(j = 0; j < N- 1-i; j++){
			if(Array[j] > Array[j+1]){
				temp = Array[j];
				Array[j] = Array[j+1];
				Array[j+1] = temp;
			}
		}
	}
	printf("Vay mang sau khi sap xep la: \n");
	for(i=0; i< N; i++){
		printf("\t%5d", Array[i]);
	}
}
void binarySearch(int N, int searchValue, int Array[]){
	int left = 0,mid,right = N - 1;
	int found = 0;
	while(left <= right){
		mid = left + (right -left)/2;
		if(Array[mid] == searchValue){
			found = 1;
			break;
		}else if (Array[mid] > searchValue){
			right = mid - 1;
		}else if (Array[mid] < searchValue){
			left = mid + 1;
		}
	}
	if(found){
		printf("Vay tim thay gia tri %d o chi so %d", searchValue, mid);
	}else{
		printf("Vay tim thay gia tri %d o chi so %d", searchValue, -1);
	}
}

int main(){
	
	int i, n,value;
	printf("Nhap kich co cua mang: ");
do{
	scanf("%d", &n);
	if(n <= 0){
		printf("Loi ! Vui long nhap lai: ");
		fflush(stdin);
	}
}while(n <= 0);
	int maTran[n];
	printf("Nhap phan tu trong mang: \n");
	for(i =0; i < n; i++){
		printf("Array[%d] = ", i);
		scanf("%d", &maTran[i]);
	}
bubbleSort(n,maTran);
printf("\nNhap gia tri can tim vao: ");
scanf("%d",&value);
binarySearch(n, value, maTran);
	
	
}

