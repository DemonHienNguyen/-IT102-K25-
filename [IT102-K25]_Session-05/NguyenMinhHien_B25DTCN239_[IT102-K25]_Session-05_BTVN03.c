#include <stdio.h>

int main (){
	
	
	printf("---KIEM TRA THONG TIN XEP HANG--- \n");
	float Xep_hang;
	
	printf("nhap Diem:");
	scanf("%f", &Xep_hang);
	
	if(Xep_hang >= 8 && Xep_hang <= 10){
		printf("Hoc luc gioi");
	}else if(Xep_hang >= 6.5 && Xep_hang < 8){
		printf("Hoc luc kha");
	}else if(Xep_hang >=5 && Xep_hang < 6.5){
		printf("Hoc luc Trung Binh");
	}else{
		printf("Hoc luc yeu");
	return 0;
	}
	return 0;
}
