#include <stdio.h>

int i, j;

void sumPrime(int N, int array[N]){

int isPrime;
int sum =0;
	for( i = 0; i < N; i++ ){
		isPrime = 1;
		if(array[i] <= 1){
			continue;
		}
		for(j =2; j*j<= array[i]; j++ ){
			if(array[i] % j==0){
				isPrime = 0;
				break;
			}
		}
	if (isPrime == 1){
		sum += array[i];
		printf("\ncac so nguyen to trong mang la :");
		printf("%d \n", array[i]);
	}
}
	printf("tong cac so nguyen to la = ");
	printf("%d ", sum );


}


int main(){
	
	int n;
	
	printf("\tnhap so nguyen N: ");
do{
	if(scanf("%d", &n) != 1 || n <=0){
		printf("loi ! Vui long nhap lai: ");
	}
}while(n <= 0);

int maTran[n];

printf("\t-----NHAP PHAN TU TRONG MANG-----\n");
	for(i = 0; i < n; i++){
			printf("Array[%d]: ", i);
			scanf("%d", &maTran[i]);
		}
printf("\t-----VAY MANG LA-----\n ");
	for(i =0; i< n; i++){
			printf("\t %5d", maTran[i]);
		}    
sumPrime(n, maTran);
return 0;
}
