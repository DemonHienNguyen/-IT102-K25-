#include <stdio.h>
#include <limits.h>

int main(){
	
	int i;
	int index;
	
printf("Nhap kich thuoc cua mang: ");
do{
	scanf("%d", &index);
	if(index < 2){
		printf("Loi ! vui long nhap lai kich thuoc:  ");
	}
}while(index<2);

int arr[index];

printf("Nhap so phan tu trong mang: \n");
for(i=0; i<index;i++){
	printf(" thang thu %d: ", i+1);
	scanf("%d", &arr[i]);
}
printf("Vay mang gia tri co phieu cua cac thang la: \n");
for(i= 0;i < index;i++){
	printf("\t%d", arr[i]);
}

	int buyPrice = arr[0];
	int minLoss = INT_MIN;
	int sellMonth = -1;
	int hasLoss = 0;
	
for(i= 1; i < index; i++){
	int diff = arr[i] - buyPrice;
	if(diff<0){
		hasLoss = 1;
		if(diff > minLoss){
			minLoss = diff;
			sellMonth = i+1;
		}
	}else if(diff > 0){
		
	}
}
printf("\n\n---KET QUA GIAO DICH---\n");
if(hasLoss){
	printf("ban se lo it nhat %d neu ban ban vao thang : %d",-minLoss,sellMonth );
}else{
	printf("ban co the co lai !");
}
return 0;
	
}
