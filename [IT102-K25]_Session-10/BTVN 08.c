#include <stdio.h>

void binarySearch(int N, int X, int Array[]){
	
	int left = 0;
	int right = N -1;
	int find = 0;
	int mid;
while(left <= right){
	mid = left + (right -left)/2;
	if(Array[mid] == X){
		find = 1;
		break;
	}else if(Array[mid] > X){
		right = mid -1;
	}else if(Array[mid] < X){
		left = mid + 1;
	}
}
	if(find){
		printf("Chi so phan tu can tim o: %d", mid);
	}else{
		printf("khong co gia tri tim o trong !");
	}
}

void bubbleSort(int N, int Array[N]){
	int i, j;
	int temp;
	for(i = 0; i <N-1;i++){
		for(j = 0; j<N-1-i; j++){
			if(Array[j] > Array[j+1]){
				temp = Array[j];
				Array[j] = Array[j+1];
				Array[j+1] =temp;
			}
		}
	}
printf("\n\tVay mang sau khi sap xep la: \n");
for(i=0; i < N; i++){
	printf("\t%5d", Array[i]);
}
	
}


void nhapVaInMang(int N, int Array[]){
	int i;
printf("nhap phan tu trong mang: \n");
for(i= 0; i < N; i++){
	printf("Array[%d] = ", i);
	scanf("%d",&Array[i]);
}	

	for(i= 0; i<N; i++){
		printf("\t%5d", Array[i]);
	}
}


int main(){
	
	int i, index, searchValue;
	printf("nhap kich co cua mang: ");
do{
	scanf("%d", &index);
	if(index<=0){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar() != '\n');
	}
}while(index <=0);

int list[index];

nhapVaInMang(index, list);
bubbleSort(index, list);
	
	printf("\nnhap so can tim trong mang: ");
do{
	scanf("%d", &searchValue);
	if(searchValue<=0){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar() != '\n');
	}
}while(searchValue <=0);

binarySearch(index,searchValue,list);
	
}
