#include <stdio.h>

void sumArray(int N, int Array[]){
	int i; 
	int sum = 0;
	for(i = 0; i < N; i++){
		sum += Array[i];
	}

printf("Vay tong cac so nguyen cua ham la: %d", sum);

}



int main (){
	
	int n, i;
	
	
	printf("Nhap kich co: ");
	scanf("%d", &n);
	
	int arr[n];
	
	for(i = 0; i < n; i++){
		printf("Array[%d] = ", i);
		scanf("%d", &arr[i]);
	}
	
	sumArray(n, arr);
	
}
