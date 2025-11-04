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
		printf("phan tu %d co chi so %d trong mang sap xep", X, mid);
	}else{
		printf("khong co phan tu tim o trong !");
	}
}



void minArray(int N, int Array[N]){
	
	int minArray;
	int i, j;
	minArray =Array[0];
	for(i = 1; i < N; i++){
		if(Array[i] < minArray){
			minArray = Array[i];
		}
	}
	printf("So nguyen nho nhat trongg mang la:%d", minArray);
}



int main(){
	
	int n;
	int i;
	
printf("\tnhap kich thuoc mang cua ban: ");
do{
	scanf("%d", &n);
	if(n <=0){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar () != '\n');
	}
}while(n<=0);

int list[n];

printf("\tnhap phan tu o trong mang\n");
for(i =0; i < n;i++){
	printf("Array[%d] = ", i);
	scanf("%d", &list[i]);
}
printf("\tVay mang ban dau la: \n");
for(i=0;i<n;i++){
	printf("\t%5d", list[i]);
}
printf("\n");
minArray(n, list);

	int j;
	int minIndex;
	int temp;
	
	for(i = 0; i < n; i++){
		minIndex = i;
		for(j = i+1;j<n;j++){
			if(list[j] < list[minIndex]){
				minIndex = j;
			}
		}
		if(minIndex != i){
			temp = list[minIndex];
			list[minIndex] = list[i];
			list[i] = temp; 
		}
		
	}
printf("\nVay mang sau khi sap xep la: \n");
for(i=0; i < n; i++){
	printf("\t%5d", list[i]);
}
	int searchValue;
printf("\n\tnhap gia tri can tim: ");
do{
	scanf("%d", &searchValue);
	if(searchValue <=0){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar () != '\n');
	}
}while(searchValue<=0);

binarySearch(n,searchValue,list);
	
}
