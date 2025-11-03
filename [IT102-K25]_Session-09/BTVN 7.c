#include <stdio.h>



int i, j;

void reversed(int N, int array[N]){

int temp;

	printf("\t----------SO DAO NGUOC----------\n");
	for(i = 0; i < N /2;i++){
		temp = array[i];
		array[i] = array[N - i - 1];
		array[N -i - 1] = temp;
		}
	printf("\n");
printf("\t----------SO DAO NGUOC LA:\n");
	for(i=0; i<N;i++){
			printf("\t%5d", array[i]);
		}
	printf("\n");
}



int main(){

int n;

printf("\tnhap so nguyen (n >0):  ");
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

reversed(n, maTran);
return 0;
}
