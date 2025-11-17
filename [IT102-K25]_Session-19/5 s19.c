#include <stdio.h>

int compareArrays(int *a, int *b, int n);

int compareArrays(int *a, int *b, int n){
	int i;
	int isTheSame = 1;
	for(i= 0; i < n; i++){
		if(*(a + i) != *(b +i)){
			isTheSame = 0;
			break;
		}
	}
	return isTheSame;
}

int main(){
	
	int size, i;
	printf("Nhap kich co cua mang: ");
	scanf("%d", &size);
	
	int list[size];
	
	printf("Nhap cac phan tu trong mang thu nhat: \n");
	for(i= 0; i < size; i++){
		printf("Arrar[%d] = ", i);
		scanf("%d", &list[i]);
	}
	
	int list2[size];
	
	printf("Nhap cac phan tu trong mang thu hai: \n");
	for(i= 0; i < size; i++){
		printf("Arrar2[%d] = ", i);
		scanf("%d", &list2[i]);
	}
	int result = compareArrays(list, list2, size);
	
	if(result){
		printf("Giong nhau vcl");
	}else{
		printf("Dell giong nhau");
	}
	return 0;
}
