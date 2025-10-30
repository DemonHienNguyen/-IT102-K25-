#include <stdio.h>

int main(){
	
	int Number, Reversed_Num =0, i;
	
	printf("---SO DOI XUNG (palindrome) \n");
	

Demon:
do{
	printf("nhap so nguyen (1-infinity): ");
	if(scanf("%d", &Number) != 1){
		printf("\nso nhap khong phai so nguyen\n");
	}
}while (getchar() != '\n');

if(Number <0 ){
		printf(" vui long nhap so nguyen !\n");
		Number = 0;
		goto Demon;
}
int Goc_Num = Number;

while (Number > 0){
	i = Number % 10;
	Reversed_Num = Reversed_Num*10 + i;
	Number /=10;
}
if(Goc_Num == Reversed_Num){
	printf("So ban Vua nhap la so Doi Xung !\n");
}else{
	printf("So ban vua nhap khong phai la Doi Xung !\n");
	goto Demon;
}
return 0;
}

