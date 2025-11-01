#include <stdio.h>

int main(){
	
	int n, i;
do{	
	printf(" nhap phan tu cua ban :");
	if(scanf("%d", &n) != 1){
		printf("----so ban nhap khong phai so ! \n");
		while(getchar() != '\n');
		continue;
	}	
	while(getchar() != '\n');
	if( n <=0 ){
		printf("----so phan tu ban nhap khong hop le ! \n");
	}
}while(n <=0);

	int array[n];
	
	for( i = 0; i < sizeof(array)/sizeof(int); i++){
		printf("----phan tu thu %d: ", i);
		scanf("%d", &array[i]);
	}
	printf("vay phan tu cua ban co: \n");
	
	for(i =0; i <  sizeof(array)/sizeof(int); i++){
		printf("%d ", array[i]);
	}
return 0;
}
