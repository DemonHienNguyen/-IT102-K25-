#include <stdio.h>

int main(){
	
	int n,i;
	
do{
	printf("nhap so phan tu cua ban: ");
	if(scanf("%d", &n) != 1){
		printf("so phan tu cua ban khong hop le ! \n");
		while(getchar() != '\n');
		continue;
	}
	while(getchar() != '\n');
	if(n <=0 ){
		printf("gia tri khong hop le ! \n");
	}
}while(n <=0);

if(n > 5){
	printf(" so phan tu khong duoc > 5 \n");
	printf(" so phan tu se mac dinh = 5 \n");
	n =5;
}
int array[n];
	for(i = 0; i < sizeof(array)/sizeof(int); i++){
		printf("array[%d] = ", i);
		scanf("%d", &array[i]);
	}
	for(i = 0; i < sizeof(array)/sizeof(int); i++){
		printf("%d \t", array[i]);
	}
	printf("\n \n");
	for(i = 0; i < sizeof(array)/sizeof(int); i++){
		if(array[i] % 2==0){
			array[i] += 3;
		}else{
			array[i] += 2;
		}
	}
	for(i = 0; i < sizeof(array)/sizeof(int); i++){
	printf("%d \t", array[i]);
}
return 0;
	
	
}
