#include <stdio.h>

int main(){
	
	int n, i;
do{
	printf("nhap so phan tu cua ban: ");
	if(scanf("%d", &n) !=1){
		printf("----so ban nhap khong hop le ! \n");
		while(getchar() !=  '\n');
		continue;
	}
	while(getchar() != '\n');
	if(n <=0 ){
		printf("so ban nhap khong hop le ! \n");
	}
}while(n <=0);
	int array[n];
	for(i = 0; i < sizeof(array)/sizeof(int); i++){
		printf("array[%d] = ", i);
		scanf("%d", &array[i]);
	}
	int min = array[0];	
	for(i = 0;i < n; i++){
		if(array[i] < min){
			min = array[i];
		}
	}
	int max = array[0];
	for(i =0; i<n; i++){
		if(array[i] > max){
			max = array[i];
		}
	}
	printf("so nho nhat: %d \n", min);
	printf("so lon nhat :%d \n", max);
	return 0;	
	}

