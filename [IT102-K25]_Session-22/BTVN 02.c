#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
	char name[50];
	char phoneNumber[15];
	char email[50];
}Contact;

void removeBuffer(){
	 int c;
	 while((c = getchar()) != '\n' && c != EOF);
}
void removeNewLine(char *a){
	 size_t len = strlen(a); 
	 a[len -1] = '\0';
}

//
void printMenu();
void printfContactor(Contact *Ct, int *length);
void insertContact(Contact **Ct, int *length);
void findContactor(Contact *Ct, int *length);
//

//

void insertContact(Contact **Ct, int *length){
	int index;
	int currentIndex = *length;
	printf("Nhap so luong can them lien he: ");
	scanf("%d", &index);
	removeBuffer();
	Contact *temp = (Contact*)realloc((*Ct), ((*length) + index) * sizeof(Contact));
	(*Ct) = temp;
	for(int i = 0;i < index; i++){
		printf(">>> Nhap thong tin lien he thu %d <<< \n", currentIndex + i +1);
		printf("Nhap ten cua nguoi lien he: ");
		fgets((*Ct)[currentIndex + i].name, 100, stdin);
		removeNewLine((*Ct)[currentIndex + i].name);
		printf("Nhap so dien thoai cua nguoi lien he: ");
		fgets((*Ct)[currentIndex + i].phoneNumber, 15, stdin);
		removeNewLine((*Ct)[currentIndex + i].phoneNumber);
		printf("Nhap email: ");
		fgets((*Ct)[currentIndex + i].email, 30, stdin);
		removeNewLine((*Ct)[currentIndex + i].email);
	}
	(*length) += index;
	printf("Them thanh cong !");
}
void printfContactor(Contact *Ct, int *length){
	if ( (*length) == 0){
		printf("-----------------------------------\n");
		printf(">>>> Danh sach Trong <<<< \n");
		printf("-----------------------------------\n");
	}else{
		printf("-----------------------------------\n");
		printf(">>>> Danh sach nguoi lien he <<<< \n");
		printf("-----------------------------------\n");
		for(int i = 0;i < *length; i++){
			printf("-----------------------------------\n");
			printf("|Ten: %s | SDT: %s | Email: %s | \n", Ct[i].name, Ct[i].phoneNumber, Ct[i].email);
			printf("-----------------------------------\n");
		}
	}
}
void findContactor(Contact *Ct, int *length){
	char findName[30];
	int find;
	
	printf("Nhap ten can tim kiem: ");
	fgets(findName, sizeof(findName), stdin);
	removeNewLine(findName);
	find = -1;
	for(int i = 0; i < *length; i++){
		if(strcmpi(Ct[i].name, findName) == 0){
			find = i;
			break;
		}
	}
	if(find != -1){
		printf("Tim thay %s o vi tri %d", findName, find + 1);
	}else{
		printf("Khong tim thay %s", findName);
	}
}
void deleteContactor(Contact **Ct, int *length){
	char findName[30];
	int find;
	printf("Nhap ten can muon xoa: ");
	fgets(findName, sizeof(findName), stdin);
	removeNewLine(findName);
	find = -1;
	for(int i = 0; i < *length; i++){
		if(strcmpi((*Ct)[i].name, findName) == 0){
			find = i;
			break;
		}
	}
	if(find != -1){
		Contact *temp = (Contact*)realloc((*Ct), ((*length) -1) * sizeof(Contact));
		(*Ct) = temp;
		for(int j = find; j < *length; j++){
			(*Ct)[j] = (*Ct)[j+1];
		}
		printf("Xoa thanh cong !");
		(*length)--;
	}else{
		printf("Khong tim thay %s", findName);
	}
}
void printMenu(){
		printf("\n\t\t\t++====================MENU====================++\n");
		printf("\t\t\t||%-44s||\n", "1. Them lien he moi");
		printf("\t\t\t||%-44s||\n", "2. Hien thi tat ca lien he");
		printf("\t\t\t||%-44s||\n", "3. Tim kiem theo ten");
		printf("\t\t\t||%-44s||\n", "4. Xoa lien he theo ten");
		printf("\t\t\t||%-44s||\n", "5. Thoat");
		printf("\t\t\t++============================================++\n");
		printf("-------- Lua chon cua ban: ");
}


int main(){
	int choice;
	int size = 0;
	Contact *menuCt = (Contact*)malloc(size *sizeof(Contact));
	if(menuCt == NULL){
		printf("Cap phat that bai roi em\n");
	}else{
		printf("Cap phat thanh cong my man \n");
	}
	do{
		printMenu();
		scanf("%d", &choice);
		removeBuffer();
		switch (choice){
			case 1 :{
				insertContact(&menuCt,&size);
				break;
			}
			case 2 :{
				printfContactor(menuCt, &size);
				break;
			}
			case 3 :{
				findContactor(menuCt, &size);
				break;
			}
			case 4 : {
				deleteContactor(&menuCt, &size);
				break;
			}
			case 5 :
				free(menuCt);
				exit(0);
		}
	}while(1);
	return 0;
}

