#include <stdio.h>
#include <math.h>
#include <stdlib.h> 

int main(){
	int n;
	long long a, b;
	
do{
	printf("nhap so n: ");
	if(scanf("%d", &n) != 1 || n <=0){
		printf("so khong hop le ! \n");
		while(getchar() != '\n');
	}
}while(n <=0);
	
	for(a = 0; a*a*a <= n; a++ ){
		for(b =0; b*b*b <=n; b++){
			if(a*a*a + b*b*b == n){
				printf("vay cap so a^3 + b^3 = n thoa man la : (%d -%d) \n", a, b);
			}
		}
	}
	
	return 0;
	
}
