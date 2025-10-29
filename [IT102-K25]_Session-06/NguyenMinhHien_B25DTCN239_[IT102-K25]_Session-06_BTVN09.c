#include <stdio.h>
#include <math.h>

int main (){
	
	printf("---MAY TINH--- \n\n");
	
	int Choice;
	int Tong, Max, Min, A, B, C;
	float Trung_Binh;
	
do{	
	printf("\n---DEMON---\n");
	printf("\n1 .Nhap 3 so \n");
	printf("2 .Tong 3 so  \n");
	printf("3 .Trung binh Cong 3 so \n");
	printf("4 .So nho nhat \n");
	printf("5 .So lon nhat \n");
	printf("6 .Thoat \n");
	printf("Lua chon cua ban: ");
	scanf("%d", &Choice);
	
	switch (Choice){
		case 1:
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
			do{
				printf("---NHAP SO THU BA CUA BAN : ");
				if(scanf("%d", &C) != 1){
					printf("khong the nhap ky tu vao day vui long nhap lai : \n");
					C=0;
			}
			}while (getchar() != '\n');
			break;
		break;
		case 2:
			if(A != 0 && B != 0 && C != 0){
			printf("\nTong cua 3 So la: %d \n", Tong = A + B + C);
			}else{
				printf("\nloi: Vui long nhap 3 so truoc ! \n");
			}
			break;	
		case 3:
			if(A != 0 && B != 0 && C != 0){
			printf("\nTrung Binh cua 3 So la: %.2f \n", Trung_Binh = (float) (A + B + C)/3.0 );
			}else{
				printf("\nloi: Vui long nhap 3 so truoc ! \n");
			}
			break;
		case 4:
			if(A != 0 && B != 0 && C != 0){
			Min = A;
			if(B < Min && B < C){
				Min = B;
			}else if (C < Min && C < B){
				Min = C;
			}if(A < B && A < C){
				Min = A;
			}
			printf("\nGia tri nho nhat la: %d \n ", Min);
			}else{
				printf("\nloi: Vui long nhap 3 so truoc ! \n");
			}
			break;
		case 5:
			if(A != 0 && B != 0 && C != 0){
			Max = A;
			if(B > Max && B > C){
				Max = B;
			}else if (C > Max && C > B){
				Max = C;
			}if(A > B && A > C){
				Max = A;
			}
			printf("\nGia tri lon nhat la: %d \n ", Max);	
			}else{
				printf("\nloi: Vui long nhap 3 so truoc ! \n");
			}
			break;			
		case 6:
			printf("\n\n\n---DEMON_IS_NOT_FUN :) ---\n\n\n");
			return 0;
		default:
			printf(" Loi vui long nhap lai \n");
			break;
	}
}while(Choice >= 0);
return 0; 
}
