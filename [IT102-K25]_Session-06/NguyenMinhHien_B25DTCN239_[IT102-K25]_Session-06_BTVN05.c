#include <stdio.h>

int main (){

	int N;
	int i;
	printf("--BANG CUU CHUONG SO--- \n");
	
	for (N = 1; N <=9;N++){
		printf("BANG CUU CHUONG %d \n", N); 
		for (i = 1; i <= 10; i++){
			printf(" %2d x %2d = %3d \n", N, i, N*i);
		}
			
	}
	
	
return 0;
}
