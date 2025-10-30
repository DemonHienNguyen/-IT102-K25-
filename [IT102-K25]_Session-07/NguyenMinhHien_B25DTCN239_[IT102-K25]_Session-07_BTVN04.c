#include <stdio.h>

int main(){
	
	int Chieu_dai, Chieu_rong, i, j;
	
	printf("---HINH CHU NHAT (RIU OR PHEC)---\n");
Demon:
do{
	printf("nhap chieu dai: ");
	if(scanf("%d", &Chieu_dai) != 1  ){
		printf("\nso nhap khong phai so nguyen\n");
	}
	printf("nhap chieu rong: ");
	if(scanf("%d", &Chieu_rong) != 1 ){
		printf("\nso nhap khong phai so nguyen\n");
	}
}while (getchar() != '\n');

if(Chieu_dai <0 || Chieu_rong < 0){
	printf("So nhap phai la so nguyen duong !\n");
	goto Demon;
}

printf("\n Hinh chu nhat dai %d rong %d :\n", Chieu_dai, Chieu_rong);

for ( i = 1; i <= Chieu_dai; i++) {
        for ( j = 1; j <= Chieu_rong; j++) {
            printf("*");
        }
        printf("\n");
	}
	return 0;
}
