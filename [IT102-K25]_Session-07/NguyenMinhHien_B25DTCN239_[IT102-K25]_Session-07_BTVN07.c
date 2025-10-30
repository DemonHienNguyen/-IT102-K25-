#include <stdio.h>
#include <math.h>



int A, B, i, C, n;

	
void Kiemtrasonguyento(){
do{
	printf("\nNhap so thu nhat: ");
	if(scanf("%d", &A) != 1){
		printf("Khong phai so !\n");
		while(getchar() != '\n');
		continue;
	}
	while (getchar() != '\n');
	if(A <= 0){
		printf("so khong phai la so nguyen! \n");
	}
}while(A<=0);
do{
	printf("\nNhap so thu hai: ");
	if(scanf("%d", &B) != 1){
		printf("Khong phai so !\n");
		while(getchar() != '\n');
		continue;
	}
	while (getchar() != '\n');
	if(B <= 0){
		printf("so khong phai la so nguyen! \n");
	}
}while(B<=0);
	if(A > B){
		C = A;
		A = B; 
		B = C;
	}
	printf(" [%d - %d] \n", A, B);
	int j;
	int prime(n){
		for(j = 2 ; j*j <= n; j++){
			if(n % j == 0){
				return 0;
			}
		}return 1;
	}
	for(i = A; i <= B;i++ ){
		if(i < 2){
			continue;
		}
		if(prime(i) == 1){
			printf(" %d \t", i);
		}
	}
}





int main(){
	
	printf("---SO NGUYEN TO---");
 	Kiemtrasonguyento();
	return 0; 	
}
