#include <stdio.h>

int i, j, k;

void inPhanTuXuatHienNhieuNhat(int N, int array[N]){
	
int maxCount =0;
int elementCount;
// nang cao: goi mang phu de gan gia tri xuat hien nhieu nhat vao mang do
const MAXPHANTU = 100; //nhap so phan tu toi da
int most_Frequent_Element[MAXPHANTU]; // khai bao mang phu va gan so phan tu co dinh
int countElement; // bien dem so phan tu trong mang do


	for(i = 0; i <N; i++){
		
		elementCount = array[i]; // gan gia tri luc dau de co the gan vao mang neu la so xuat hien nhieu nhat
		int currentCount = 0; // tao bien dem cho gia tri luc dau = 0
		
		for(j = 0; j < N; j++){
			if(elementCount == array[j]){  // xet dieu kien neu gia tri cua mang nay voi mang kia bang nhau khong
				
				currentCount++;  // neu co thi tang bien dem len 1 con khong thi thuc hien lenh duoi
			}
		}
		if(currentCount > maxCount){ // so sanh bien dem voi so max 
			
			maxCount = currentCount; // neu dung thi gan lai max cho bien dem 
			countElement = 0; // gan phan tu mang phu = 0 
			most_Frequent_Element[countElement] = elementCount; // them gia tri xuat hien nhieu nhat vao mang phu
			countElement++; // tang phan tu cua mang phu them 1 don vi de them gia tri phan tu neu co so xuat hien nhieu hon
			
			
		}else if(currentCount == maxCount){ // kiem tra neu so dem co bang voi max hay khong
			
			int tonTai = 0; // dat giua tri tonTai de xac dinh so do co trong mang phu vua them hay khong
			for(k =0; k < countElement; k++){ //xet trong mang phu 
				if(most_Frequent_Element[k] == elementCount){ // xet dieu kien neu gia tri trong phan tu do co bang gia tri minh gan vao mang truoc do hay khong
					tonTai = 1; // neu co thi gan lai gia tri ton tai la 1 va thoat khoi vong lap
					break;
				}
			}
			if(!tonTai && countElement < MAXPHANTU ){  // neu khong co gia tri nao = gia tri tan suat nhieu thu 2
				most_Frequent_Element[countElement] = elementCount; // gan gia tri do vao mang phu 
				countElement++; // tang phan tu len 1 don vi
			}
		}
		
	}

printf("\tvay phan tu xuat hien nhieu nhat trong mang la \n" );
for(i = 0; i < countElement; i++ ){
	printf("\t%5d", most_Frequent_Element[i]);
	if(i < countElement -1){
		printf(", ");
	}
}

printf("\n\tVoi tan so xuat hien la: %d ", maxCount);
}

int main(){

int n;

printf("\tnhap so phan tu (n >0):  ");
do{
	if(scanf("%d", &n) != 1 || n <=0){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar() != '\n');
	}
}while(n<=0);

int maTran[n];

printf("\tnhap phan tu o vi tri: \n");
	for(i=0; i<n;i++){
			printf("array[%d]: ", i);
			scanf("%d", &maTran[i]);
		}
printf("\n");
	
printf("\t----------VAY MANG LA----------\n");
	for(i=0; i<n;i++){
			printf("\t%5d", maTran[i]);
		}
printf("\n");

inPhanTuXuatHienNhieuNhat(n, maTran);
}

