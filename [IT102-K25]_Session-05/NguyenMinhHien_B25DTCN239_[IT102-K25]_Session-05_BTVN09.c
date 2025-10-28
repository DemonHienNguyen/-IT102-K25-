#include <stdio.h>

int main (){
	
	float Hesoluong;
	int Songaycong;
	int Chuc_vu;
	float Luong;
	int Phucap, Thuong;
	
	printf("---THONG TIN CHUC VU--- \n");
	
	printf("nhap He so luong cua ban: ");
	scanf("%f", &Hesoluong);
	
	printf("nhap So ngay cong: ");
	scanf(" %d", &Songaycong);
	if (Songaycong > 26){
		Thuong = 200000;
	}else{
		Thuong = 0;
	}
	if(Songaycong >= 0 && Songaycong <= 31){
		printf("---ngay hop le !--- \n");
	}else{
		printf("---ngay khong hop le !---");
		return 0;
	}
	
	printf("---nhap chuc vu cua ban--- \n 1.  Nhan vien \n 2.  To truong \n 3.  Quan ly \n");
	scanf("%d", &Chuc_vu);
	
	switch (Chuc_vu){
		case 1 :
			Phucap = 500000;
			Luong = Songaycong * 160000 * Hesoluong + Phucap +Thuong;
			printf("luong cua ban la: %.3f", Luong);
			break;
		case 2 :
			Phucap = 1000000;
			Luong = Songaycong * 160000 * Hesoluong + Phucap +Thuong;
			printf("luong cua ban la: %.3f", Luong);
			break;
		case 3 :
			Phucap = 2000000;
			Luong = Songaycong * 160000 * Hesoluong + Phucap +Thuong;
			printf("luong cua ban la: %.3f", Luong);
			break;
		default:
			printf("khong co chuc vu thi COOK !");
			break;
	}
	return 0;
}

