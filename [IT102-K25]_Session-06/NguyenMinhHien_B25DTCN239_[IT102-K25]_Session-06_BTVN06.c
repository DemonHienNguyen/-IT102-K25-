#include <stdio.h>
#include <math.h>

int main (){
	
	printf("---MAY TINH CAM TAY--- \n\n");
	
	int Choice;
	float Tong, Hieu, Tich, Thuong, A, B;
	
do{	
	printf("---NHAP SO THU NHAT CUA BAN :");
	if(scanf("%f", &A) != 1){
		printf("khong the nhap ky tu vao day vui long nhap lai : \n");
		A=0;
	}
	}while (getchar() != '\n');
do{
	printf("---NHAP SO THU HAI CUA BAN : ");
	if(scanf("%f", &B) != 1){
		printf("khong the nhap ky tu vao day vui long nhap lai : \n");
		B=0;
	}
	}while (getchar() != '\n');
do{	
	printf("---MENU---\n");
	printf("1 .Tong 2 so \n");
	printf("2 .Hieu 2 so \n");
	printf("3 .Tich 2 so \n");
	printf("4 .Thuong 2 so \n");
	printf("5 .Thoat \n");
	printf("Lua chon cua ban: ");
	scanf("%d", &Choice);
	
	switch (Choice){
		case 1:
			printf("Tong cua 2 So la: %.2f \n", Tong = A + B);
			break;
		case 2:
			printf("Hieu cua 2 So la: %.2f \n", Hieu = A -
			 B);
			break;	
		case 3:
			printf("Tich cua 2 So la: %.2f \n", Tich = A * B);
			break;
		case 4:
			if( A  != 0 && B == 0){
				
				printf("Loi phep chia \n");
				break;
			}else if(  B != 0 ){
				printf("Thuong cua 2 So la: %.2f \n", Thuong = A / B);
				break;
			}
			
		case 5:
			printf("---SIKIBIDI---");
			return 0;
			
		default:
			printf(" Loi vui long nhap lai \n");
			break;
	}
}while(Choice >= 0);
	

return 0; 
}
