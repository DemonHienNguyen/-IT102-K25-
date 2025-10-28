#include <stdio.h>

int main(){
	
	long long Nuoc, Gia;
	
	printf("---TINH TIEN NUOC TIEU THU---\n");
	
	printf(" nhap so nuoc ma ban da tieu thu: ");
	scanf("%lld", &Nuoc);
	
	if(Nuoc >0 && Nuoc <= 10){
		Gia = Nuoc * 6000;
		printf("Gia tien nuoc thang nay: %lld", Gia);
	}else if(Nuoc >=11 && Nuoc <=20){
		Gia = 10*6000+ (Nuoc-10)*7000;
		printf("Gia tien nuoc thang nay: %lld", Gia);
	}else if(Nuoc >=21 && Nuoc <=30){
		Gia = 10*6000 + 10*7000 + (Nuoc- 20)*8500;
		printf("Gia tien nuoc thang nay: %lld", Gia);
	}else if(Nuoc > 30){
		Gia = 10*6000+ 10*7000 + 10*8500 + (Nuoc-30)*10000;
		printf("Gia tien nuoc thang nay: %lld", Gia);
	}
	return 0;
}
