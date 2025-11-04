#include <stdio.h>

int main(){
	
	int i,j;
	int index, temp;
	
	printf("\t---SAP XEP NOI BOT---\n");
	printf("nhap so phan tu torng mang: ");
do{
	scanf("%d", &index);
	if(index <=0){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar () != '\n');
	}
}while(index<=0);

int numbers[index];

printf("\tnhap phan tu trong mang: \n");
for(i =0; i < index; i++){
	printf("Array[%d] = ", i);
	scanf("%d", &numbers[i]);
}

int size = sizeof(numbers)/sizeof(numbers[0]);

printf("\t--- VAY MANG BAN DAU LA---\n");
for(i =0; i < size; i++){
	printf("\t%5d", numbers[i]);
}
printf("\n");

int change = 0;
for(i = 0; i < size - 1; i++){
	for(j = 0; j < size - 1 -i; j++){
		if(numbers[j] > numbers[j+1]){
			temp = numbers[j+1];
			numbers[j+1] = numbers[j];
			numbers[j] = temp;
			change = 1;
		}
	}
	
	if(!change){
		printf("\tMANG DA DUOC SAP XEP !\n");
		break;
	}
}
if(change){
	printf("\t---VAY MANG SAU KHI SAP XEP LA---\n");
	for(i=0;i < size; i++){
		printf("\t%5d", numbers[i]);
	}
}



}
