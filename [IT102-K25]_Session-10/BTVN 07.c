# include <stdio.h>

int main(){
	
	printf("\t---BINARY SORT---\n");
	
	int i, find;
	int left, right, mid;
	int searchValue;
	int index;
	
	printf("\tnhap kich co cua mang: ");
do{
	scanf("%d", &index);
	if(index <=0){
		printf("Loi ! Vui long  nhap lai: ");
		while(getchar() != '\n');
	}
}while(index <= 0); 
	
int list[index];	
	
	printf("\tnhap phan tu vao trong mang: \n");
	for(i= 0; i < index; i++){
		printf(" Array[%d] = ", i);
		scanf("%d", &list[i]);
}
	printf("\tnhap gia tri can tim ");
do{
	scanf("%d", &searchValue);
	if(searchValue<=0){
		printf("Loi ! Vui long  nhap lai: ");
		while(getchar() != '\n');
	}
}while(searchValue<= 0);
 	
 	find = 0;
	left = 0, right = index -1;
while(left <= right){
	mid = left + (right - left)/2;
	if(list[mid] == searchValue){
		find = 1;
		break;
	}else if(list[mid] > searchValue){
		right = mid -1;
	}else if(list[mid] < searchValue){
		left = mid + 1;
	}
}
if(!find){
	printf("khong co gia tri can tim kiem trong nay !");
}else{
	printf("gia tri can tim co trong mang o vi tri: %d", mid);
}
	return 0;
}
