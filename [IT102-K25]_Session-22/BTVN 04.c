#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
	int day;
	int month;
	int year;
}Date;
typedef struct{
	char guestName[50];
	char idGuest[10];
	Date some;	
	float totalAmount;
	char Status[20];
}Person;

void removeBuffer(){
	 int c;
	 while((c = getchar()) != '\n' && c != EOF);
}
void removeNewLine(char *a){
	 size_t len = strlen(a);
	 a[len -1] = '\0';
}

// khai bao ham 
void printMenu();
void enterOrderInformation(Person **perPtr, int *length);
void displayOrderInformation(Person *perPtr, int *length);
void updateOrderStatus(Person *perPtr, int *length);
void deleteOrder(Person **perPtr, int *length);
void sortOrder(Person *perPtr, int *length, int choice);
void findOrder(Person *perPtr, int *length);
// khai bao ham
void enterOrderInformation(Person **perPtr, int *length){
	int index;
	int currentIndex = *length;
	char fisrtStatus[20] = "Khong co";
	printf("Nhap so luong hang ma ban can them: ");
	scanf("%d", &index);
	removeBuffer();
	Person *temp = (Person*)realloc((*perPtr), ((*length) + index) * sizeof (Person));
	(*perPtr) = temp;
	for(int i = 0 ; i < index; i++){
		printf("----------------------------------------------\n");
		printf(">>>> Thong tin cua don hang thu %d <<<< \n", currentIndex + i + 1);
		printf("-------------------------------------------\n");
		printf("Vui long nhap ma hang cua don hang: ");
		fgets((*perPtr)[currentIndex + i].idGuest, 100, stdin);
		removeNewLine((*perPtr)[currentIndex + i].idGuest);
		printf("Vui long nhap ten don hang: ");
		fgets((*perPtr)[currentIndex + i].guestName, 100, stdin);
		removeNewLine((*perPtr)[currentIndex + i].guestName);
		printf("Vui long nhap ngay/thang/nam dat hang: ");
		scanf("%d/%d/%d", &(*perPtr)[currentIndex + i].some.day, &(*perPtr)[currentIndex + i].some.month, &(*perPtr)[currentIndex + i].some.year);
		removeBuffer();
		printf("Vui long nhap Tong tien: ");
		scanf("%f", &(*perPtr)[currentIndex + i].totalAmount);
		removeBuffer();
		strcpy((*perPtr)[currentIndex + i].Status, fisrtStatus);
	}
	(*length) += index;
	
}
void displayOrderInformation(Person *perPtr, int *length){
	if((*length) == 0){
		printf("---------------------------------------\n");
		printf(">>>>>>>>>>>> Danh Sach Trong <<<<<<<<<<\n");
		printf("---------------------------------------\n");
	}else{
		printf("-------------------------------------------\n");
		printf(">>>>>>>>>>>> Danh Sach don hang <<<<<<<<<<\n");
		printf("-------------------------------------------\n");
		for(int i = 0 ;i < (*length); i++){
			printf("------------------------------------------------------------------------------------------------------------------\n");
			printf("|Ma SP: %s  |Ten: %-24s  |Date: %02d/%02d/%4d  |Tong tien: %.1f  |Status: %-15s  |\n"
			,perPtr[i].idGuest, 
			perPtr[i].guestName, 
			perPtr[i].some.day,perPtr[i].some.month, perPtr[i].some.year, 
			perPtr[i].totalAmount, 
			perPtr[i].Status);
			printf("------------------------------------------------------------------------------------------------------------------\n");
		}
	}
	
}
void updateOrderStatus(Person *perPtr, int *length){
	char findID[30];
	int find;
	int sure;
	int updatechoice;
	printf("Nhap Ma sinh vien ma ban muon tim: ");
	fgets(findID, 30, stdin);
	removeNewLine(findID);
	find = -1;
	for(int i = 0; i < *length; i++){
		if(strcmpi(perPtr[i].idGuest, findID) == 0){
			find = i;
			break;
		}
	}
	if(find != -1){
		printf("Da Tim thay ! \n");
		printf("------------------------------------------------------------------------------------------------------------------\n");
		printf("|Ma ID: %s  |Ten: %-24s  |Date: %02d/%02d/%4d  |Tong tien: %.1f|Status: %-15s  |\n"
		, perPtr[find].idGuest, 
		perPtr[find].guestName, 
		perPtr[find].some.day,perPtr[find].some.month, perPtr[find].some.year, 
		perPtr[find].totalAmount, 
		perPtr[find].Status);
		printf("------------------------------------------------------------------------------------------------------------------\n");
		printf("Vui long chon trang thai can duoc capp nhap: \n");
		printf("1. Dang xu ly \n");
		printf("2. Da giao \n");
		printf("3. Huy \n");
		printf("----- Lua chon cua ban: ");
		scanf("%d", &updatechoice);
		removeBuffer();
		switch (updatechoice){
			case 1 :{
				strcpy(perPtr[find].Status,"Dang xu ly");
				break;
			}
			case 2 :{
				strcpy(perPtr[find].Status,"Da giao");
				break;
			}
			case 3 :{
				strcpy(perPtr[find].Status,"Huy");
				break;
			}
		}
		printf("Ban co muon Cap nhap khong (1: Yes | 0: No): ");
		scanf("%d",&sure);
		removeBuffer();
		if(sure == 1){
			printf("Cap nhap thanh cong ! \n");
		}else{
			strcpy(perPtr[find].Status,"Khong co");
			printf("CAm on Vi DA DEN ! \n");
		}
	}else if(find == -1){
		printf("Khong tim thay Ma %d trong danh sach ! \n", findID);
	}
	
	
	
}
void deleteOrder(Person **perPtr, int *length){
	char findID[30];
	int find;
	int sure;
	printf("Nhap Ma sinh vien ma ban muon tim: ");
	fgets(findID, 30, stdin);
	removeNewLine(findID);
	find = -1;
	for(int i = 0; i < *length; i++){
		if(stricmp((*perPtr)[i].idGuest, findID) == 0){
			find = i;
			break;
		}
	}
	if(find != -1){
		printf("Da Tim thay ! \n");
		printf("------------------------------------------------------------------------------------------------------------------\n");
		printf("|Ma ID: %s  |Ten: %-24s  |Date: %02d/%02d/%4d  |Tong tien: %.1f|Status: %-15s  |\n"
		, (*perPtr)[find].idGuest, 
		(*perPtr)[find].guestName, 
		(*perPtr)[find].some.day,(*perPtr)[find].some.month, (*perPtr)[find].some.year, 
		(*perPtr)[find].totalAmount, 
		(*perPtr)[find].Status);
		printf("------------------------------------------------------------------------------------------------------------------\n");
		printf("Ban co muon Xoa khong (1: Yes | 0: No): ");
		scanf("%d",&sure);
		removeBuffer();
		if(sure == 1){
			for(int j = find; j < (*length) - 1; j++){
				(*perPtr)[j] = (*perPtr)[j+1];
			}
			(*length)--;
			printf("Xoa thanh cong ! \n");
			if((*length) > 0){
				Person *temp = (Person*)realloc((*perPtr), ((*length)) * sizeof(Person));
				if(temp == NULL){
					printf("Cap phat bo nho that bai ! \n");
				}else{
					(*perPtr) = temp;
				}
			}else{
				free((*perPtr));
				*perPtr = NULL;
			}
		}else{
			printf("CAm on Vi DA DEN ! \n");
		}
	}else if(find == -1){
		printf("Khong tim thay Ma %s trong danh sach ! \n", findID);
	}
	
}
void sortOrder(Person *perPtr, int *length, int choice){
	Person value;
	int j;
	for(int i = 1; i < (*length); i++){
		value = perPtr[i];
		j = i -1 ;
		if(choice == 1){
			while(j >= 0 && value.totalAmount > perPtr[j].totalAmount){
				perPtr[j+1] = perPtr[j]; 
				j--;
			}
		}else if (choice == 2){
			while(j >= 0 && value.totalAmount < perPtr[j].totalAmount){
				perPtr[j+1] = perPtr[j]; 
				j--;
			}
		}
		perPtr[j+1] = value;
	}
	printf("Sap xep xong ! \n");
}
void findOrder(Person *perPtr, int *length){
	char findID[30];
	int find;
	int sure;
	int updatechoice;
	printf("Nhap Ma sinh vien ma ban muon tim: ");
	fgets(findID, 30, stdin);
	removeNewLine(findID);
	find = -1;
	for(int i = 0; i < *length; i++){
		if(strcmpi(perPtr[i].idGuest, findID) == 0){
			find = i;
			break;
		}
	}
		if(find != -1){
			printf("Da Tim thay ! \n");
			printf("------------------------------------------------------------------------------------------------------------------\n");
			printf("|Ma ID: %s  |Ten: %-24s  |Date: %02d/%02d/%4d  |Tong tien: %.1f|Status: %-15s  |\n"
			, perPtr[find].idGuest, 
			perPtr[find].guestName, 
			perPtr[find].some.day,perPtr[find].some.month, perPtr[find].some.year, 
			perPtr[find].totalAmount, 
			perPtr[find].Status);
			printf("------------------------------------------------------------------------------------------------------------------\n");
	}
}


// solo 
void printMenu(){
	printf("\n\t\t\t++====================MENU====================++\n");
	printf("\t\t\t||%-44s||\n", "1. Nhap thong tin don hang");
	printf("\t\t\t||%-44s||\n", "2. Hien thi thong tin don hang");
	printf("\t\t\t||%-44s||\n", "3. Cap nhap trang thai don hang");
	printf("\t\t\t||%-44s||\n", "4. Sap xep don hang theo tong tien");
	printf("\t\t\t||%-44s||\n", "5. Xoa don hang them ma don hang");
	printf("\t\t\t||%-44s||\n", "6. Tim kiem don hang theo ma don hang");
	printf("\t\t\t||%-44s||\n", "7. Thoat");
	printf("\t\t\t++============================================++\n");
	printf("-------- Lua chon cua ban: ");
}



// ket thuc 
int main(){
	int size = 0;
	int choice, sortChoice;
	Person *menuPer = (Person*)malloc(size * sizeof(Person));
	if(menuPer == NULL){
		printf("Cap phat that bai ! \n");
	}else{
		printf("Cap phat thanh cong ! \n");
	}
	do{
		printMenu();
		scanf("%d", &choice);
		removeBuffer();
		switch (choice){
			case 1 :{
				enterOrderInformation(&menuPer, &size);
				break;
			}
			case 2 :{
				displayOrderInformation(menuPer, &size);
				break;
			}
			case 3 : {
				updateOrderStatus(menuPer, &size);
				break;
			}
			case 4 :{
				printf("\t\t\t++====================MENU SAP XEP====================++\n");
				printf("\t\t\t||%-52s||\n", "1. Giam dan theo price");
				printf("\t\t\t||%-52s||\n", "2. Tang dan theo price");
				printf("\t\t\t||%-52s||\n", "3. Thoat");
				printf("\t\t\t++====================================================++\n");
				printf("-------- Lua chon cua ban: ");
				scanf("%d", &sortChoice);
				removeBuffer();
				sortOrder(menuPer, &size, sortChoice);
				break;
			}
			case 5 :{
				deleteOrder(&menuPer, &size);
				break;
			}
			case 6 :{
				findOrder(menuPer, &size);
				break;
			}
			case 7 :
				free(menuPer);
				exit(0);
				
		}
	}while(1);

	return 0;
}

