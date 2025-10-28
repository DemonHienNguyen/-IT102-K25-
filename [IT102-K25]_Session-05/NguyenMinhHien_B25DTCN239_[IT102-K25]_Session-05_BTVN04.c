#include <stdio.h>
#include <math.h>

int main (){
	
	int thunhap;
	float thue;
	
	
	printf("---TINH THUE THU NHAP PHAI DONG--- \n");
	
	printf(" nhap thu nhap cua ban: ");
	scanf("%d", &thunhap);
	
	if(thunhap <= 5){
		thue = thunhap *(5.0/100);
		printf("thue thu nhap phai dong: %.2f", thue);
	}else if( thunhap > 5 && thunhap <= 10){
		thue = thunhap *(10.0/100); 
		printf("thue thu nhap phai dong: %.2f", thue);
	}else if( thunhap > 10 ){
		thue = thunhap *(15.0/100); 
		printf("thue thu nhap phai dong: %.2f", thue);
	return 0;
	}
	return 0;
}
