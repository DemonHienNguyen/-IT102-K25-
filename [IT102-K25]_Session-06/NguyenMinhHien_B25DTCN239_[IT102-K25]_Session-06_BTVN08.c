#include <stdio.h>
#include <math.h>

int main (){

	printf("--TIM BOI CHUNG NHO NHAT---\n");
	
	int A, B;
	int i;
	int BCNN, BCLN;
Buoc1 :
do{	
	printf("---NHAP SO THU NHAT CUA BAN :");
	if(scanf("%d", &A) != 1){
		printf("khong the nhap ky tu vao day vui long nhap lai : \n");
		A=0;
	}
	}while (getchar() != '\n');
do{
	printf("---NHAP SO THU HAI CUA BAN : ");
	if(scanf("%d", &B) != 1){
		printf("khong the nhap ky tu vao day vui long nhap lai : \n");
		B=0;
	}
	}while (getchar() != '\n');
	
	if( A < 0 || B <0){
		
		printf("so bi loi ( phai nhap so nguyen duong) :\n");
		goto Buoc1;
	}
	int Goc_A = A;
	int Goc_B = B;
	
	while(B !=0){
	
	i = A % B;
	A = B;
	B= i;
	}
	BCLN = A;
	printf("Boi Chung Nho Nhat cua %d va %d la: %d",Goc_A, Goc_B, BCNN = (Goc_A * Goc_B) / BCLN );
	return 0;
}
