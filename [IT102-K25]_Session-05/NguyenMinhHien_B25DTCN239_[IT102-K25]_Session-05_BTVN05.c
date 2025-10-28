#include <stdio.h>
#include <math.h>

int main (){
	
	printf("---TINH SO TIEN VE XE--- 1\n");
	const int Gia_ve = 20000;
	int Age, Money;
	printf(" nhap tuoi cua ban: ");
	scanf(" %d", &Age);
	
	if(Age > 0 && Age <100){
		if (Age <= 6){
			Money = Gia_ve * 0;
			printf("So tien ve: %d VND", Money);
		}else if(Age > 6 && Age <= 18){
			Money = Gia_ve * (50.0/ 100);
			printf("So tien ve: %d VND", Money);
		}else if ( Age >=19 && Age <= 60){
			Money = Gia_ve *(100.0/100);
			printf("So tien ve: %d VND", Money);
		}else if ( Age > 60 ){
			Money = Gia_ve *(70.0/100);
			printf("So tien ve: %d VND", Money);
		return 0;
		}
		
	}else{
		printf("tuoi khong hop le ! ");
		
	}
	return 0;
}
