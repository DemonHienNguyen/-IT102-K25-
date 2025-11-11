#include <stdio.h>
#include <math.h>

float a, b;


void minusNumber(float A, float B);
void multiNumber(float A, float B);

void minusNumber(float A, float B){
	float minus;
	minus = fabs(A - B);
	printf("Vay so %.1f cach so %.1f mot khoang la: %.1f",A ,  B,  minus);
	printf("\n");
}
void multiNumber(float A, float B){
	float multi;
	multi = A * B;
	printf("Tich cua %.1f va %.1f la : %.2f", A, B, multi);
}


int main (){
	
	printf("Nhap so dau tien: ");
	scanf("%f", &a);
	printf("Nhap so thu hai: ");
	scanf("%f", &b);
	minusNumber(a, b);
	multiNumber(a, b);

return 0;
}
