#include <stdio.h>

int main(){
	
	printf("---TINH TIEN DIEN CUA HO GIA DINH---\n");
	int Sodien, Dongia;
	int ho, Money;
	float tienphu, Sum;
	printf("nhap so dien:");
	scanf("%d", &Sodien);
	if (Sodien >=0 && Sodien <=50){
		Money = Sodien*1500;
	}else if(Sodien >= 51 && Sodien <= 100 ){
		Money = 50*1500 + (Sodien -50)*2000;
	}else if(Sodien >= 101 && Sodien <= 200){
		Money = 50*1500  +50*2000  +(Sodien - 100)*2500;
		
	}else if(Sodien >200){
		Money = 50*1500 + 50 *2000 + 50*2500 + (Sodien -200)*3000;
	}
	
	printf("---CHON HO--- \n 1. Ho Gia Dinh \n 2. Ho Kinh Doanh \n 3. Ho san Xuat \n ");
	scanf("%d",&ho);
	switch (ho){
		case 1:
			tienphu = Money*(5.0/100);
			Sum = Money +tienphu;
			break;
		case 2: 
			tienphu = Money*(10.0/100);
			Sum = Money +tienphu;
			break;
		case 3:
			tienphu = Money*(8.0/100);
			Sum = Money +tienphu;
			break;
		default:
			printf("---HO GIA DINH KHONG HOP LE !---");
			break;
	}
	printf("Vay tien dien thang nay la: %.2f VND", Sum);
	return 0;
}
