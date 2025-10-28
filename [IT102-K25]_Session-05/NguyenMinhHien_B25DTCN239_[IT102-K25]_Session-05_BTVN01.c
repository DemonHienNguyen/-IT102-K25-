#include <stdio.h>

int main(){
	
	int A, B;
	
	printf(" nhap so thu nhat: ");
	scanf("%d", &A);
	
	printf(" nhap so thu hai: ");
	scanf("%d", &B);
	
	if(A > B){
		printf(" so lon hon la: %d", A);
		return 0;
	}
	if(B > A){
		printf(" so lon hon la: %d", B);
		return 0;
	}
	if( A == B){
		printf(" hai so bang nhau ");
		return 0;
	}
	return 0;
}
