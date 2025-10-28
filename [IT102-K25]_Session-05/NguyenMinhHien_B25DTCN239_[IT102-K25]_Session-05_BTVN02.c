#include <stdio.h>
#include <math.h>

int main(){
	
	int A, B;
	float X;
	
	printf("---GIAI PHUONG TRINH BAC NHAT AX + B = 0 \n ");
	
	printf(" nhap he so A: ");
	scanf("%d", &A);
	
	printf(" nhap he so B: ");
	scanf("%d", &B);
	
	if(A ==0 && B == 0){
		printf(" phuong trinh co vo so nghiem !");
		return 0;
	}
	if(A ==  0 && B != 0){
		printf("phuong trinh vo nghiem !" );
		return 0;
	}
	if(A !=0 ){
		X =(float) -B / A;
		printf(" phuong trinh co nghiem la: %.2f", X);
		return 0;
	}
	return 0;
}
