#include <stdio.h>

int main(){
	
	printf("---IN SO DAO NGUOC--- \n");
	
	
	int Number,Reversed_Num = 0, i;
	
do{
	printf("nhap so nguyen: ");
	
	if(scanf("%d",&Number) !=  1){
		printf("so khong chinh xac !\n");
		while(getchar() != '\n');
		continue;
	}
	while(getchar() != '\n');
	if(Number <=0){
		printf("so nhap khong hop le !\n");
	}
}while(Number <= 0);
while(Number >0){
	i = Number % 10;
	Reversed_Num = Reversed_Num*10 + i;
	Number /= 10;
}
printf("Vay so dao nguoc la: %d", Reversed_Num);
return 0;
}
