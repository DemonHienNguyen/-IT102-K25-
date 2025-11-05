#include <stdio.h>


int main(){
	
	int i, j, k;
	
	int index;
	
printf("\tnhap phan tu cua mang: ");
do{
	scanf("%d", &index);
	if(index<=0){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar()  != '\n');
	}
}while(index <=0);
	
int list[index];
	
printf("nhap phan tu trong mang: \n");
	for(i=0; i < index;i++){
		printf("Array[%d] = ", i);
		scanf("%d", &list[i]);
	}
for(i = 0; i < index; i ++){
	printf("\t%5d", list[i]);
}
	
	for(i = 0 ; i < index ; i++){
		for(j = i+1; j < index; j++){
			if(list[i] == list[j]){
				for(k = j; k <  index - 1;k++){
				list[k] = list[k+1];
				}
				--index;
				--j;
				}
			}
		}
printf("Vay mang sau khi xoa lap la \n");
for(i = 0; i < index; i ++){
	printf("\t%5d", list[i]);
}
	
	
}
