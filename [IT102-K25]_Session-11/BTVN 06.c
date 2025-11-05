#include <stdio.h>

int main(){
	
	int index, temp;
	int i, j;
	
printf("Nhap kich thuoc mang: ");
do{
	scanf("%d", &index);
	if(index <2){
		printf("Loi ! Vui long nhap lai(so phan tu > 2): ");
	}
}while(index <2 );
	
int arr[index];

	printf("Nhap phan tu trong mang: \n");
for(i=0; i <index; i++){
	printf("Array[%d] = ", i);
	scanf("%d", &arr[i]);
}
printf("\tVAY MANG BAN DAU LA\n");
for(i=0;i<index;i++){
	printf("\t%5d", arr[i]);
}
	int min_Index;
	int maxValue1, maxValue2;
for(i = 0; i < index-1;i++){
	min_Index = i;
	for(j = i+1;j < index; j++){
		if(arr[j] < arr[min_Index]){
			min_Index  = j;
		}
	}
	temp = arr[min_Index];
	arr[min_Index] = arr[i];
	arr[i] = temp;
}

printf("\nVay gia tri lon nhat la: %d", arr[index-1]);
maxValue2 = arr[index-1];
for(i = index -2; i>=0; i--){
	if(arr[i] < maxValue2){
		maxValue2 = arr[i];
		break;
	}
}

if(maxValue2 != arr[index-1]){
	printf("\nVay gia tri lon thu hai la: %d", maxValue2);
}else{
	printf("khong co gia tri thu 2 thoa man !");
}


	return 0; 
}
