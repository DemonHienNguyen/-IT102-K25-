#include <stdio.h>

void printArray(int N, int Array[N]);


void printArray(int N, int Array[N]){
	int i;
	printf("\tVay mang la: \n");
	for(i = 0; i < N; i++){
		printf("\t%5d", Array[i]);
	}
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

printArray(size, list);

return 0; 
}
