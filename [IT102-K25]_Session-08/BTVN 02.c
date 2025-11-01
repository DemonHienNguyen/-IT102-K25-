#include <stdio.h>

int main(){
	
	int array[5], n, i;
	
	printf("nhap phan tu cua ban: ");
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		printf(" phan tu thu %d: ", i);
		scanf("%d", &array[i]);
	}
	
	for(i = 0; i < sizeof(array)/sizeof(int); i++){
		printf("%d ", array[i]);
	}
	return 0; 
}
