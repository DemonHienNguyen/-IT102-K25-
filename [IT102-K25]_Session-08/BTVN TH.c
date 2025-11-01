#include <stdio.h>
#include <stdlib.h>

#define MAXARRAY 100

int i, j, k, n, d,x, update; //khai bao gia tri;
int array[MAXARRAY];// co dinh so phan tu la 100 
int count = 0; 
int choice;
int temp;


// khai bao cac nguyen mau ham 
void nhapMang();
void inMang();
void xaoPhanTu();
void themPhanTu();
void capNhapGiaTri();
void sapXepMang();
void timKiemMang();





void nhapMang(){
	printf("\t--------------NHAP MANG--------------\n");
	printf("\tnhap so luong phan tu (0 -> %d): ",MAXARRAY);
	do{
		scanf("%d", &n);
		if(n < 0 || n > MAXARRAY){
			printf("loi ! vui long nhap lai: ");
			while(getchar() != '\n');
		}
	}while(n  <=0 || n > MAXARRAY);
	

	printf("\tnhap cac phan tu cua mang: \n");
	for(i = 0; i < n; i++){
		printf("array[%d] : ", i);
		scanf("%d", &array[i]);
	}
}

void inMang(){
	printf("\n\t--------------VAY MANG LA--------------\n\n");
	for(i = 0; i < n; i++){
		printf("\t%d", array[i]);
	}
	printf("\n");
}

void xaoPhanTu(){
	printf("\n\t--------------XOA PHAN TU TAI VI TRI TRONG MANG--------------\n");
	if (n==0){
		printf("\tmang rong, khong co gi de xoa !\n");
		return;// thoat ra chuong trinh khong thuc hien lenh o duoi
	}
printf("\tnhap **chi dich** (vi tri) can xoa (tu 0 -> %d): ", n-1);
do{
	if(scanf("%d", &k) != 1 || k <0 || k >=n){
		printf("\tchi muc khong hop le ! Vui long nhap lai: ");
		while(getchar() != '\n');
	}
}while(k < 0 || k >=n);
// dich chuyen cac phan tu sau k len truoc
	for(i = k; i < n-1; i++){
		array[i] = array[i+1];
	}
// giam kich thuoc mang 
	--n;
	printf("\tMANG SAU KHI XAO PHAN TU TAI CHI MUC %d: \n",k);
	inMang();
}


void themPhanTu(){
	printf("\t--------------THEM PHAN TU VAO VI CHI BAT KY--------------\n");
	if(n == 0){ 
		printf("\tmang khong co gi de them ! \n");
		return;// thoat ra chuong trinh khong thuc hien lenh o duoi
	}
printf("\tnhap **chi dich** (vi tri) can them (tu 0 -> %d): ", n-1);
do{
	if(scanf("%d", &d) != 1 || d >= n || d<0){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar() != '\n');
	}
}while(d < 0 || d >=n);
printf("\tnhap gia tri vao vi tri %d: ", d);
scanf("%d", &x);

	for(i = n-1; i >=d; i--){
		array[i+1] = array[i];
	}
	array[d] = x;
	++n;
printf("\tMANG SAU KHI THEM PHAN TU TAI CHI MUC %d: \n",d);
inMang();
}

void capNhapGiaTri(){
	printf("\t--------------CAP NHAP GIA TRI BAT KY-------------- \n");
	if(n == 0){
		printf("khong co gia tri nao de cap nhap !");
		return;// thoat ra chuong trinh khong thuc hien lenh o duoi
	}
printf("\tnhap **chi dich** (vi tri) can cap nhap (tu 0 -> %d): ", n-1);
do{
	if(scanf("%d", &update) != 1 || update >= n || update<0){
		printf("\tLoi ! Vui long nhap lai: ");
		while(getchar() != '\n');
	}
}while(update < 0 || update >=n);
printf("\tnhap gia tri can cap nhap tai vi tri %d: ", update);
scanf("%d", &x);
	array[update] = x;
	inMang();
}

void timKiemMang(){
	printf("\t--------------TIM GIA TRI CUA BIEN TRONG MANG--------------\n");
if(n == 0){
	printf("\tkhong co gia tri nao thoa man de tim !");
	return;
}	
printf("\tnhap gia tri can tim trong mang: ");

do{
	if(scanf("%d", &x) != 1 || x < 0 ){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar() != '\n');
	}
}while(x < 0);
	for(i = 0; i < n; i++){
		if(array[i] == x){
			count++;
		}else{
			continue;
		}
		printf("\n\tgia tri %d xuat hien trong mang o vi tri [%d] \n\n", x , i);
	}
}

void sapXepMang(){
if(n==0){
	printf("khong co gia tri trong mang !");
	return;// thoat ra chuong trinh khong thuc hien lenh o duoi
}

	printf("\n\t--------------SAP XEP TRONG MANG--------------\n");
	printf("\n\t1. SAP XEP THEO TANG DAN \n");
	printf("\t2. SAP XEP THEO GIAM DAN \n");
	printf("\t3. Thoat\n");
	printf("\n\tchon lua chon cua ban: ");
	scanf("%d", &choice);
	
switch(choice){
	case 1:
		for(i = 0; i < n-1; i++){
			for(j= 0; j < n-1;j++){
				if(array[j] > array[j+1]){
					temp = array[j];
					array[j] = array[j+1];
					array[j +1] = temp;
				}
			}
		}
		inMang();
		break;
	case 2:
		for(i = 0; i < n-1; i++){
			for(j= 0; j < n-1;j++){
				if(array[j] < array[j+1]){
					temp = array[j +1];
					array[j+1] = array[j];
					array[j] = temp;
				}
			}
		}
		inMang();
		break;
	case 3:
		return;
	default:
		printf("Loi ! \n ");
}
}



int main(){
	nhapMang();
do{
	printf("\n\t--------------Quan ly danh sach so nguyen -------------\n");
	printf("\n\t1. Them phan tu vao vi tri bat ky \n");
	printf("\t2. xoa phan tu o vi tri bat ky \n");
	printf("\t3. cap nhap gia tri vi tri bat ky \n");
	printf("\t4. tim kiem phan tu trong mang \n");
	printf("\t5. hien thi mang \n");
	printf("\t6. sap xep mang (Bubble Sort) \n");
	printf("\t7. Thoat chuong trinh \n");
	printf("\n\tchon lua chon cua ban: ");
	scanf("%d", &choice);
	printf("\n");
	
	switch(choice){
		case 1:
			themPhanTu();
			break;
		case 2:
			xaoPhanTu();
			break;
		case 3 :
			capNhapGiaTri();
			break;
		case 4:
			timKiemMang();
			break;
		case 5:
			inMang();
			break;
		case 6:
			sapXepMang();
			break;
		case 7:
			exit(0);
		default:
			printf(" Loi ! \n\n");
			
	}

}while(choice != 0);

	return 0;
}	

