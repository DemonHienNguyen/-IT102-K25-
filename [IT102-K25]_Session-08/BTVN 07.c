#include <stdio.h>
int n, i;

void mangTinh(){
do{
	printf("nhap so phan tu cua ban: ");
	if(scanf("%d", &n) != 1){
		printf("so phan tu nhap khong hop le ! \n");
		while(getchar() != '\n');
		continue;
	}
	while(getchar() !='\n');
	if(n <=0){
		printf("so nhap khong hop le: \n");
	}
}while( n <=0);
int array[n];
for(i = 0; i < sizeof(array)/sizeof(int);i++){
	printf("array[%d] = ", i);
	scanf("%d", &array[i]);
}
printf("vay phan tu co mang la: \n");
for(i =0; i < sizeof(array)/sizeof(int);i++){
	printf("%d \t", array[i]);
}
printf("\n \n");
for(i = 0; i < sizeof(array)/sizeof(int);i++){
	while(array[i] %2 ==0){
		printf(" \nvui long nhap so le tai phan tu thu %d: \n", i);
		scanf("%d", &array[i]);
	}
}
printf("vay phan tu co mang la: \n");
for(i =0; i < sizeof(array)/sizeof(int);i++){
	printf("%d \t", array[i]);
}
}

int main(){
	mangTinh();
	return 0;
}
