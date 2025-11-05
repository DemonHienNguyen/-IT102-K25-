#include <stdio.h>


int main(){
	
	int i, j;
	int index, temp;
	
printf("\tnhap phan tu cua mang: ");

do{
	scanf("%d", &index);
	if(index<=0){
		fflush(stdin);
		printf("Loi ! Vui long nhap lai: ");
	}
}while(index <=0);
	
int list[index];
	
printf("nhap phan tu trong mang: \n");
	for(i=0; i < index;i++){
		printf("Array[%d] = ", i);
		scanf("%d", &list[i]);
	}
for(i= 0; i < index - 1;i++){
	for(j = 0; j < index - 1- i; j++){
		if(list[j] > list[j+1]){
			temp = list[j];
			list[j] = list[j+1];
			list[j+1] = temp;
		}
	}
}
for( i = 0; i < index; i++){
	printf("\t%5d", list[i]);
}
	
}
