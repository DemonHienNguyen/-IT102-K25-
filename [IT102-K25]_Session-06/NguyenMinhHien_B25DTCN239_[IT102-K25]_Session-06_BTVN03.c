#include <stdio.h>
#include <math.h>
int main(){
	
	printf("---TINH TONG CAC SO NGUYEN--- \n");
	int N;
	int i = 0;
	int j = 0;
	
	printf("nhap so tu nhien N: ");
	scanf("%d", &N);
	
	while(i < N){
		i+=1;
		j+=i;
	}
	printf("tong cua day so N la: %d", j);
	return 0;
	
	
}
