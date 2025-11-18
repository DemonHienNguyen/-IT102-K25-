#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
	int id;
	char name[100];
	float price;
}Dish;

void removeBuffer();
void removeNewLine(char *a);
void printMenu(Dish ptr[],int *length);
void addNew(Dish ptr[], int *length);
void updateSomething(Dish ptr[], int *length);
void deleteSomething(Dish ptr[], int *length);
void sortSomething(Dish ptr[], int *length, int choice);
// khai bao bien





void removeBuffer(){
	int c;
	while( ( c= getchar()) != '\n' && c != EOF );
}
void removeNewLine(char *a){
	size_t len = strlen(a);
	a[len - 1] = '\0';
}
void printMenu(Dish ptr[],int *length){
	int i;
	printf("Menu Mon An: \n");
	for(i = 0; i < *length; i++){
		printf("----------------------------------------\n");
		printf("|Id: %-3d |Ten: %-10s|Price: %.1f \n", ptr[i].id, ptr[i].name, ptr[i].price);
		printf("----------------------------------------\n");
	}
}
void addNew(Dish ptr[], int *length){
	int i;
	int index1,index0;
	printf("Chon vi tri ma ban muon them (1 -> %d): ", *length);
	do{
		scanf("%d", &index1);
		if(index1 < 1 || index1 > *length){
			printf("Loi ! Vui long nhap lai: ");
		}
	}while(index1 < 1 || index1 > *length);
	removeBuffer();
	index0 = index1 - 1;
	for(i = (*length) - 1; i >= index0; i--){
		ptr[i + 1] = ptr[i];
	}
	printf("----Nhap Thong Tin Moi---- \n");
	printf("Nhap Id mon an: ");
	scanf("%d", &ptr[index0].id);
	removeBuffer();
	printf("Nhap ten mon an: ");
	fgets(ptr[index0].name, 100, stdin);
	removeNewLine(ptr[index0].name);
	printf("Nhap gia cua mon an: ");
	scanf("%f", &ptr[index0].price);
	removeBuffer();
	printf("Them thanh cong ! \n");
	(*length)++;
}
void updateSomething(Dish ptr[], int *length){
	int i;
	int index1,indexUpdate;
	char newName[50];
	printf("Nhap chi so ma ban muon cap nhap (1 -> %d): ",*length);
	do{
		scanf("%d", &index1);
		if(index1 < 1 || index1 > *length){
			printf("Loi ! Vui long nhap lai: ");
		}
	}while(index1 < 1 || index1 > *length);
	removeBuffer();
	indexUpdate = index1 - 1;
	printf("----Nhap Thong Tin Cap Nhap---- \n");
	printf("Nhap Id mon an: ");
	scanf("%d", &ptr[indexUpdate].id);
	removeBuffer();
	printf("Nhap ten mon an moi: ");
	fgets(newName, 100, stdin);
	removeNewLine(newName);
	strcpy(ptr[indexUpdate].name, newName);
	printf("Nhap gia cua mon an: ");
	scanf("%f", &ptr[indexUpdate].price);
	removeBuffer();
	printf("Cap nhap thanh cong ! \n");
}
void deleteSomething(Dish ptr[], int *length){
	int index1, indexDelete;
	int i;
	printf("Nhap chi so ma ban muon xoa (1 -> %d): ", *length);
	do{
		scanf("%d", &index1);
		if(index1 < 1 || index1 > *length){
			printf("Loi ! Vui long nhap lai: ");
		}
	}while(index1 < 1 || index1 > *length);
	removeBuffer();
	indexDelete = index1 -1;
	for(i = indexDelete; i < *length; i++){
		ptr[i] = ptr[i+1];
	}
	printf("Xoa Thanh Cong ! \n");
	(*length)--;
}
void sortSomething(Dish ptr[], int *length, int choice){
	int i, j;
	float temp;
	if(choice == 1){
		for(i = 0; i < (*length) -1; i ++){
			for(j = 0; j < (*length) - i - 1; j++){
				if(ptr[j].price < ptr[j + 1].price){
					temp = ptr[j].price;
					ptr[j].price = ptr[j+1].price;
					ptr[j+1].price = temp;
				}
			}
		}
		
	}else if(choice == 2){
		for(i = 0; i < (*length) -1; i ++){
			for(j = 0; j < (*length) - i - 1; j++){
				if(ptr[j].price > ptr[j + 1].price){
					temp = ptr[j].price;
					ptr[j].price = ptr[j+1].price;
					ptr[j+1].price = temp;
				}
			}
		}
	}else if(choice == 3){
		printf("Cam on Vi da Den :D \n");
		return;
	}
	printf("Sap xep thanh cong ! \n");
}
void findSomething(Dish ptr[], int *length, int choice, int*Sort){
	int i, j;
	int find = 0;
	char findName[50];
	printf("Nhap Mon An Ma ban Muon Tim: ");
	fgets(findName, sizeof(findName), stdin);
	removeNewLine(findName);
	if(choice == 1){
		printf("Nhap Mon An Ma ban Muon Tim: ");
		fgets(findName, sizeof(findName), stdin);
		removeNewLine(findName);
		for(i = 0; i< *length; i++){
			if(strcmp(ptr[i].name, findName) == 0){
				find = 1;
				break;
			}
		}
		if(find){
			printf("Da tim thay mon %s o vi tri thu %d \n", findName, i+1);
		}else{
			printf("Khong tim thay mon %s trong menu ! \n")
		}
	}else if(choice == 2 && *Sort = 1){
		int left = 0;
		int right = *length - 1;
		int mid;
		while(left <= right){
			mid = left + (right -left)/2
			if(strcmp(ptr[i].name, findName) == 0){
				
				
			}
		}
	}else if(choice == 3){
		printf("Cam on Vi da Den :D \n");
		return;
	}else{
		printf("Vui long chon tim kiem tuyen tinh khi chua sap xep hoac tim kiem nhi phan khi da sap xep roi ! \n");
	}
	printf("thanh cong ! \n");
	}


int main(){
	
	int choice , sortChoice, findChoice;
	int isSort = 0;
	int size = 5;
	Dish menu[100] = {
		{101, "Pho Bo Dac Biet", 55000},
		{102, "Bun Cha Ha Noi", 45000},
		{103, "Banh Mi Thit", 20000},
		{104, "Goi Cuon Tom Thit", 35000},
		{105, "Com Ga Hai Nam", 60000}
	};
	
	do{
		printf("\t\t\t++====================MENU====================++\n");
		printf("\t\t\t||%-44s||\n", "1. In cac Phan Tu Ra Menu");
		printf("\t\t\t||%-44s||\n", "2. Them phan tu vao vi tri chi dinh");
		printf("\t\t\t||%-44s||\n", "3. Sua mot phan tu tai vi tri chi dinh");
		printf("\t\t\t||%-44s||\n", "4. Xoa phan tu tai vi tri chi dinh");
		printf("\t\t\t||%-44s||\n", "5. Sap xep phan tu");
		printf("\t\t\t||%-44s||\n", "6. Tim kiem phan tu theo ten mon");
		printf("\t\t\t||%-44s||\n", "7. Thoat");
		printf("\t\t\t++============================================++\n");
		printf("-------- Lua chon cua ban: ");
		scanf("%d", &choice);
		switch (choice){
			case 1 :{
				printMenu(menu, &size);
				break;
			}
			case 2 :{
				addNew(menu, &size);
				break;
			}
			case 3 :{
				updateSomething(menu, &size);
				break;
			}
			case 4 :{
				deleteSomething(menu, &size);
				break;
			}
			case 5 :{
				printf("\t\t\t++====================MENU SAP XEP====================++\n");
				printf("\t\t\t||%-52s||\n", "1. Giam dan theo price");
				printf("\t\t\t||%-52s||\n", "2. Tang dan theo price");
				printf("\t\t\t||%-52s||\n", "3. Thoat");
				printf("\t\t\t++====================================================++\n");
				printf("-------- Lua chon cua ban: ");
				scanf("%d", &sortChoice);
				sortSomething(menu, &size, sortChoice);
				isSort = 1;
				break;
			}
			case 6 :{
				printf("\t\t\t++====================MENU TIM KIEM====================++\n");
				printf("\t\t\t||%-53s||\n", "1. Tim kiem tuyen tinh");
				printf("\t\t\t||%-53s||\n", "2. Tim kiem nhi phan");
				printf("\t\t\t||%-53s||\n", "3. Thoat");
				printf("\t\t\t++====================================================++\n");
				printf("-------- Lua chon cua ban: ");
				scanf("%d", &findChoice);
				break;
			}
			case 7 :{
				exit(0);
			}
		}
	printf("\nNhan phim ENTER de tiep tuc...");
	removeBuffer();
	getchar();
	}while(1);

	return 0;
}

