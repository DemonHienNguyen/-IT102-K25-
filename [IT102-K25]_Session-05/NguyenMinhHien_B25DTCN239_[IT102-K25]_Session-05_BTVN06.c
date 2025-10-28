#include <stdio.h>
#include <math.h>
int main (){
	
	float A, B, Ans; 
	
	
	char toantu;
	
	printf(" nhap so thu nhat: ");
	scanf(" %f",&A);
	
	printf("nhap so thu hai: ");
	scanf(" %f", &B);
	
	printf(" nhap toan tu can phai tinh: (+ , -, *, /) ");
	scanf(" %c", &toantu);
	
	
	switch (toantu){
		case '+':
			Ans = A + B;
			break;
		case '-':
			Ans = A -B;
			break;
		case '*':
			Ans = A * B;
			break;
		case '/':
			if(B ==0){
				printf(" Loi khong the chia cho 0 \n");
				return 0;
			}else{
				Ans = A/B;
			}
			break;
		default:
			printf("toan tu khong hop le !");
			break;
	}
	printf(" Ket qua: %.2f %c %.2f = %.2f  ", A, toantu, B, Ans);
	return 0;
}
