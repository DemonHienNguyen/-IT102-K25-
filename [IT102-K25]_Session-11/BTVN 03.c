#include <stdio.h>


int main(){
	
	int i, j;
	int index, temp;
	
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
// Binary sort
int searchValue;
printf("\n\tnhap Gia Tri can tim: ");

do{
	scanf("%d", &searchValue);
	if(searchValue<0){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar()  != '\n');
	}
}while(searchValue <0);


	int left= 0, right = index -1, mid;
	int find = 0;
	while(left <= right){
		mid = left + (right - left)/2;
		if(list[mid] == searchValue){
			find = 1;
			break;	
		}else if(list[mid] > searchValue){
			right = mid - 1;
		}else if(list[mid] < searchValue){
			left = mid + 1; 
		}
	}
if(find){
	printf("tim thay gia tri o chi so %d", mid);
}else{
	printf("Khong co gia tri can tim !");
}





	
	


}
