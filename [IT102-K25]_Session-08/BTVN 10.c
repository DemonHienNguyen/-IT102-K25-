#include  <stdio.h>
#include  <math.h>

int i, j, k;  

int prime(int n){
	if (n <= 1){
		return 0;
	}else if(n == 2){
		return 1;
	}
	if( n % 2 == 0){
		return 0;
	}
	for(k = 3; k*k <= n; k += 2){
		if(n % k ==0)
			return 0;
	return 1;
	}
}


void tim_Ra_So_Nguyen_to(int R, int C, int array[R][C]){
	
	int dem_Snt = 0;
	
	printf("----CAC PHAN TU SO NGUYEN TO TRONG MA TRAN LA----\n");
	
	printf("\n");
	
	for(i = 0; i < R; i++){
		for(j = 0;j < C;j++){
			int l = array[i][j];
			if(prime(l)){
				printf("%d tai [%d][%d] \n", l, i, j);
				dem_Snt++;
			}
		}
	}
	if(dem_Snt ==0 ){
		printf("khong co so nguyen to ! \n ");
	}else{
		printf("\n tong cong co %d so nguyen to \n", dem_Snt);
	}
}



void nhap_Va_In_Ma_Tran(){
	
	int r,c; 
do{
	printf("nhap so hang cua ban: ");
	if(scanf("%d", &r) != 1 || r <=0){
		printf("so khong hop le ! \n");
		while(getchar() != '\n');
	}
}while(r <= 0);

do{
	printf("nhap so cot cua ban: ");
	if(scanf("%d", &c) != 1 || c <=0){
		printf("so khong hop le ! \n");
		while(getchar() != '\n');
	}
}while(c <= 0);

int maTran[r][c];

printf("---NHAP PHAN TU VAO MANG--- \n");
	for(i = 0; i < r;i++){
		for(j = 0; j < c;j++){
			printf("Gia tri o vi tri [%d][%d]: ", i, j);
			while(scanf("%d", &maTran[i][j]) != 1){
				printf("loi ! vui long nhap lai du lieu: ");
				while(getchar() != '\n');
			}
		}
	}
printf("vay ma tran co dang: \n");
for(i = 0; i < r;i++){
		for(j = 0; j < c;j++){
			printf("%5d", maTran[i][j]);
		}
		printf("\n");
}
tim_Ra_So_Nguyen_to(r, c, maTran);
}

int main(){
	
	nhap_Va_In_Ma_Tran();
	
	return 0;
}
