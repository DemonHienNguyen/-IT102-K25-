#include <stdio.h>

void binarySearch(int N, int X, int Array[]){
	
	int left = 0;
	int right = N -1;
	int find = 0;
	int mid;
while(left <= right){
	mid = left + (right -left)/2;
	if(mid == X){
		find = 1;
		break;
	}else if(mid > X){
		right = mid -1;
	}else if(mid < X){
		left = mid + 1;
	}
}
	if(find){
		printf("Gia cua san pham voi ma ID %d: %d",X , Array[mid-1]);
	}else{
		printf("khong co phan tu tim o trong !");
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
printf("\n\tVay Gia cua san pham sau khi sap xep la: \n");
for(i=0; i < N; i++){
	printf("\t%5d", Array[i]);
}
	
}


int main(){
	int n, iD;
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
printf("nhap ID can tim cua ban: ");
do{
	scanf("%d", &iD);
	if(iD <=0){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar () != '\n');
	}
}while(iD<=0);
binarySearch(n,iD, list);
bubbleSort(n, list);


	
}
