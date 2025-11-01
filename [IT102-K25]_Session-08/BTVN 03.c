#include <stdio.h>

int main(){
	
	// khai bao bien 
	int n, i;
	int array[5];
	// thong bao nhap bien 
do{
	printf("nhap so phan tu cua ban: ");
	if(scanf("%d", &n) != 1){
		printf("so nhap khong phai la so ! \n");
		while(getchar() != '\n');
		continue;
	}
	while(getchar() != '\n');
	if(n <= 0){
		printf("so vua nhap la so am ! \n ");
	}
}while(n <=0);

	if(n > sizeof(array)/sizeof(int) ){
		printf("so phan tu se co dinh la 5 ! \n");
		n = 5;
	}
	// gan phan tu vao trong mang array 
	
	for(i = 0; i < n; i++){
		printf("array[%d] = ", i);
		scanf("%d", &array[i]);
	}
	for(i =0; i < sizeof(array)/sizeof(int); i++){
		if(array[i] % 2 == 0){
			printf("%d ",array[i]);
		}else{
			printf(" * ");
		}
	}
	return 0;   
	
}
