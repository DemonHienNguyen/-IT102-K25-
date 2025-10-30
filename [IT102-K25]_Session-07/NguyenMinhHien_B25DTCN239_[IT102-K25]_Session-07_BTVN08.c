#include <stdio.h>
int So=0 ,X , i;
long long Number1, Number2;
void Kiemtrasuxuathien(){

	
do{
	printf("nhap So nguyen N: ");
	if(scanf("%lld", &Number1) != 1){
		printf(" So nhap khong hop le !\n");
		while(getchar() != '\n');
		continue;
	}
	while(getchar() != '\n');
	if(Number1 <= 0){
		printf(" so nhap phai la so duong ! \n");
	}
}while(Number1 <= 0);
do{
	printf("nhap So can tim (0-9): ");
	if(scanf("%d", &X) != 1){
		printf(" So nhap khong hop le !\n");
		while(getchar() != '\n');
		continue;
	}
	while(getchar() != '\n');
	if(X <= 0){
		printf(" so nhap phai la so duong ! \n");
	}
}while(X <= 0);

Number2 = Number1;

while(Number1 > 0){
	i = Number1 % 10;
	if(i == X){
		So++;
		Number1 /= 10;
	}else{
		Number1 /= 10;
	}
}
printf("Vay chu So %d co trong %lld la: %d", X, Number2, So);
}

int main(){
	
	printf("---XUAT HIEN CHU SO X TRONG N--- \n");
	Kiemtrasuxuathien();
	return 0;
	
}
