#include <stdio.h>


int main(){
	
	int n, i;
	int searchValue;
	
	printf("\tnhap so phan tu cua ban: ");
do{
	if(scanf("%d",  &n) != 1 || n <=0){
		printf("Lo! vuilong nhap lai: ");
		while(getchar() != '\n');
	}
}while(n <= 0);

int maTran[n];
		
int size  = sizeof(maTran)/sizeof(int);
	printf("\tnhap cac phan tu: \n");
	for(i = 0; i < size; i++){
		printf("Array[%d] = ", i);
		scanf("%d", &maTran[i]);
	}
printf("\n\tvay mang: \n");
	for(i= 0; i < size; i++){
		printf("\t%d", maTran[i]);
	}

printf("\n\tnhap Gia Tri tim kiem: ");
do{
	scanf("%d", &searchValue);
	if(searchValue<0){
		printf("Lo! vuilong nhap lai: ");
		while(getchar() != '\n');
	}
}while(searchValue <= 0);
	
	
	int find = 0;
	for(i = 0; i< n;i++){
		if(maTran[i] == searchValue){
			printf("Vay so %d co xuat hien o chi so %d",searchValue ,i);
			find = 1;
			break;
		}
	}
	if(!find){
		printf("\tKhong tim thay !");
	}
	return 0; 
}
