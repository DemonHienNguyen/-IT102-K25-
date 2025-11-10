#include <stdio.h>

int maxArray(int N, int Array[N]);


int maxArray(int N, int Array[N]){
	int i;
	int max = Array[0]; 
	for(i = 0; i < N; i++){
		if(max < Array[i]){
			max = Array[i];
		}
	}
	printf("Vay gia tri lon nhat la: %d", max);
	return max;
}

int main(){
	
	int i, size;
	printf("Nhap kich co cua mang: ");
do{
	if(scanf("%d", &size) != 1){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar() != '\n');
		continue;
	}
	while(getchar() != '\n');
	if(size <=0){
		printf("Loi ! Vui long nhap lai: ");
	}
}while(size <=0);

int list[size];
	
	printf("Nhap phan tu trong mang: \n");
	for(i=0;i<size; i++){
		printf("Array[%d] = ", i);
		scanf("%d", &list[i]);
	}

maxArray(size, list);
	return 0;
}


