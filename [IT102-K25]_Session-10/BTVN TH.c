#include <stdio.h>
#include <stdlib.h>

#define MAXPHANTU 100
int array[MAXPHANTU], n;
int i, j, choice;

void addArray();
void deleteArray();
void updateArray();
void findArray();
void printArray();
void bubbleSort();
void getArray();



void getArray(){
printf("\tnhap so phan tu trong mang: ");
do{
	scanf("%d",&n);
	if(n <=0){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar() != '\n');
	}
}while(n <=0);
	printf("\tnhap phan tu trong mang: \n");
for(i=0; i<n;i++){
	printf("Array[%d] = ", i);
	scanf("%d",&array[i]);
}
}
void printArray(){
printf("\n");
	for(i = 0; i < n; i++){
		printf("\t%5d", array[i]);
	}
}
void addArray(){
	int addNumber;
	int addIndex;
printf("\nnhap chi so can them vao mang (0 -> %d): ", n);
do{
	scanf("%d",&addIndex);
	if(addIndex <0 || addIndex > n){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar() != '\n');
	}
}while(addIndex <0 || addIndex > n);


printf("\nnhap gia tri can them vao mang: ");
do{
	scanf("%d",&addNumber);
	if(addNumber <=0){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar() != '\n');
	}
}while(addNumber <=0);

	for(i=n -1; i>=addIndex; i--){
		array[i+1] = array[i];
	}
	array[addIndex] = addNumber;
	++n;
printf("\n");
printArray();
printf("\n");
}
void deleteArray(){
	int deleteIndex;
printf("\nchon chi so can xoa (0 -> %d): ", n);
do{
	scanf("%d", &deleteIndex);
	if(deleteIndex <0 || deleteIndex >n){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar() != '\n');
	}
}while(deleteIndex <0 || deleteIndex >n );

	for(i = deleteIndex; i<n; i++){
		array[i] = array[i+1];
	}
	--n;
printArray();
printf("\n");
}
void updateArray(){
	int updateIndex;
	int updateNumber;
	
printf("\nnhap chi so can cap nhap (0 -> %d): ", n-1);
do{
	scanf("%d", &updateIndex);
	if(updateIndex <0 || updateIndex >n){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar() != '\n');
	}
}while(updateIndex <0 || updateIndex >n);
	printf("\nnhap Gia Tri cap nhap: ");
do{
	scanf("%d", &updateNumber);
	if(updateNumber <0){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar() != '\n');
	}
}while(updateNumber <0);
	array[updateIndex] = updateNumber;
printf("\n");
printArray();
printf("\n");
}
void findArray(){
	int searchValue;
printf("\nnhap gia tri can tim: ");
do{
	scanf("%d", &searchValue);
	if(searchValue <0 ){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar() != '\n');
	}
}while(searchValue <0);
	int count = 0;
	for(i = 0;i < n; i++){
		if(array[i] == searchValue){
			count++;
		}
	}
	printf("\nVay so %d co o trong mang xuat hien : %d lan\n",searchValue ,count);
printf("\n");
}
void bubbleSort(){
	int choice;
	int temp;
	printf("\t-------SAP XEP NOI BOT-------\n");
	printf("\t1. SAP XEP TANG DAN\n");
	printf("\t2. SAP XEP GIAM DAN\n");
	printf("\t3. THOAT---\n");
	printf("LUA CHON CUA BAN: ");
do{
	scanf("%d", &choice);
	if(choice < 1 || choice > 3){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar() != '\n');
	}
}while(choice<1 || choice > 3);
	switch (choice){
		case 1:
			for(i= 0; i < n-1; i++){
				for(j =0;j<n-1-i;j++){
					if(array[j] > array[j+1]){
						temp = array[j];
						array[j] = array[j+1];
						array[j+1] = temp; 
					}
					
				}
			}
			printf("\n");
			printArray();
			break;
		case 2:
			for(i= 0; i < n-1; i++){
				for(j =0;j<n-1-i;j++){
					if(array[j] < array[j+1]){
						temp = array[j];
						array[j] = array[j+1];
						array[j+1] = temp; 
					}
					
				}
			}
			printf("\n");
			printArray();
			break;
		case 3: 
			return;
		default:
			printf("Loi ! \n");
	}
printf("\n");
}



int main(){
	getArray();
do{
	printf("\n\t--------------Quan ly danh sach so nguyen -------------\n");
	printf("\n\t1. Them phan tu vao vi tri bat ky \n");
	printf("\t2. xoa phan tu o vi tri bat ky \n");
	printf("\t3. cap nhap gia tri vi tri bat ky \n");
	printf("\t4. tim kiem phan tu trong mang \n");
	printf("\t5. hien thi mang \n");
	printf("\t6. sap xep mang (Bubble Sort) \n");
	printf("\t7. Thoat chuong trinh \n");
	printf("\n\tchon lua chon cua ban: ");
	scanf("%d", &choice);
	printf("\n");
	
	switch(choice){
		case 1:
			addArray();
			break;
		case 2:
			deleteArray();
			break;
		case 3 :
			updateArray();
			break;
		case 4:
			findArray();
			break;
		case 5:
			printArray();
			break;
		case 6:
			bubbleSort();
			break;
		case 7:
			printf("\n\n\n------------------Demon :)------------------ \n\n\n");
			exit(0);
		default:
			printf(" Loi ! \n\n");
			
	}

}while(choice != 7);

	return 0;
}	
