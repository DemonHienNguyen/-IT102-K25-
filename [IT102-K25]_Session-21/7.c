#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// cac bo sung phu 
typedef struct{
	int id;
	char name[50];
	char author[50];
	float price;
}Book;

void removeBuffer(){
	 int c;
	 while((c = getchar()) != '\n' && c != EOF);
}
void removeNewLine(char *a){
	 size_t len = strlen(a);
	 a[len -1] = '\0';
}
// bo sung phu 

// khai bao bien //
void printMenu();
void printALL(Book **Bk, int *length);
int insertBook(Book **Bk, int *length);
void deleteBook(Book **Bk, int *length);
void UpdateBook(Book **Bk, int *length);
void sortBookPrice(Book **Bk, int *length, int choice);
void findBook(Book *Bk, int *length);
void addBook(Book **Bk, int *length);
// khai bao bien //

// bat dau lam ham !
void printALL(Book **Bk, int *length){
	int i;
	if (*length == 0){
		printf("-----------------------------\n");
		printf(">>>>>>>Danh sach trong<<<<<<<\n");
		printf("-----------------------------\n");
	}else{
		printf("\t\t\t>>>>Danh sach cac quyen Sach<<< \n");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		for(i = 0 ; i  < *length; i++){
		printf("+----------------------------------------------------------------------------------------------------------------------+\n");
		printf("| %-8s: %-3d | %-8s: %-30s | %-7s: %-20s | %-8s: %.1f         |\n","Ma Sach",(*Bk)[i].id, "Ten Sach", (*Bk)[i].name,"Tac Gia", (*Bk)[i].author, "Gia Tien", (*Bk)[i].price);
		printf("+----------------------------------------------------------------------------------------------------------------------+\n");
	}
	}
}
int insertBook(Book **Bk, int *length){
	// giai thich tai sao co **:
	// thu nhat **Bk la mot con tro nhung tro den dia chi cua con tro *Bk
	// **Bk se luu gia tri vung du lieu cua Book
	// con *Bk se luu cac gia tri cua Menu chinh khi minh dat ham
	// thu hai tac dung de phat cap lai bo nho -> tang bo nho len va  khong bi  ngon du lieu !
	int i;
	int index;
	int currentIndex = *length;
	printf(">>>Nhap so luong sach ma ban muon them: ");
	scanf("%d", &index);
	removeBuffer();
	Book *temp = (Book*)realloc(*Bk, (*length  + index)* sizeof(Book));
	*Bk = temp;
	for(i = 0; i < index; i++){
		printf(">>> Thong tin cua cuon sach thu %d <<< \n",*length + i+1);
		(*Bk)[currentIndex + i].id = currentIndex + i + 1;
		printf("Nhap ten cua cuon sach: ");
		fgets((*Bk)[currentIndex+i].name, 50, stdin);
		removeNewLine((*Bk)[currentIndex + i].name);
		printf("Nhap tac gia cuon sach: ");
		fgets((*Bk)[currentIndex + i].author, 50, stdin);
		removeNewLine((*Bk)[currentIndex + i].author);
		printf("Nhap gia tien: ");
		scanf("%f", &(*Bk)[currentIndex+i].price);
		removeBuffer();
	}
	printf("Them thanh cong !");
	*length += index;
	return index;
}
void addBook(Book **Bk, int *length){
	int index1, addIndex0;
	int i;
	printf("Nhap vi tri ma ban muon them vao ( 1-> %d ): ", *length);
	scanf("%d", &index1);
	removeBuffer();
	addIndex0 = index1 - 1;
	Book *temp = (Book*)(realloc((*Bk), ((*length)+1) * sizeof(Book)));
	*Bk = temp;
	for (i = *length; i >= addIndex0; i--){
		(*Bk)[i + 1] = (*Bk)[i];
	}
	printf(">>> Thong tin cua cuon sach thu %d <<< \n",addIndex0);
		printf("Vui long nhap Ma Sach:");
		scanf("%d", &(*Bk)[addIndex0].id);
		removeBuffer();
		printf("Nhap ten cua cuon sach : ");
		fgets((*Bk)[addIndex0].name, 50, stdin);
		removeNewLine((*Bk)[addIndex0].name);
		printf("Nhap tac gia cuon sach: ");
		fgets((*Bk)[addIndex0].author, 50, stdin);
		removeNewLine((*Bk)[addIndex0].author);
		printf("Nhap gia tien: ");
		scanf("%f", &(*Bk)[addIndex0].price);
		removeBuffer();
	printf("Them thanh cong ! \n");
	(*length)++;
}
void deleteBook(Book **Bk, int *length){
	int deleteIndex0;
	int i;
	printf("Chon Ma Sach Ma ban can phai xoa: ");
	scanf("%d", &deleteIndex0);
	removeBuffer();
	for(i = 0; i < *length ; i++){
		if((*Bk)[i].id  == deleteIndex0){
			printf("Ten: %s | Tac Gia: %s | Gia Tien : %.1f \n", (*Bk)[i].name, (*Bk)[i].author, (*Bk)[i].price);
		}
	}
	Book *temp = (Book*)realloc((*Bk), ((*length) -1) * sizeof(Book));
	*Bk = temp;
	for(i = deleteIndex0; i < *length; i++){
		(*Bk)[i] = (*Bk)[i+1];
	}
	(*length)--;
	printf("Xoa thanh cong ! \n");
}
void UpdateBook(Book **Bk, int *length){
	int updateIndex;
	int i, find, findIndex = - 1;
	char newBook[50];
	char newAuthor[50];
	
	printf("Chon Ma Sach Ma ban can phai cap nhap: ");
	scanf("%d", &updateIndex);
	removeBuffer();
	find = 0;
	for(i = 0; i < *length ; i++){
		if((*Bk)[i].id  == updateIndex){
			find = 1;
			findIndex = i;
			break;
		}
	}
	if(find == i){
		printf("Ten: %s | Tac Gia: %s | Gia Tien : %.1f \n", (*Bk)[findIndex].name, (*Bk)[findIndex].author, (*Bk)[findIndex].price);
		printf(">>>Cap nhap thong tin moi cho ma sach %d \n", updateIndex);
		printf("Vui long Nhap Ma Sach Moi:");
		scanf("%d", &(*Bk)[findIndex].id);
		removeBuffer();
		printf("Nhap ten cua cuon sach Moi : ");
		fgets(newBook, 50, stdin);
		removeNewLine(newBook);
		strcpy((*Bk)[findIndex].name, newBook);
		printf("Nhap tac gia cuon sach Moi: ");
		fgets(newAuthor, 50, stdin);
		removeNewLine(newAuthor);
		strcpy((*Bk)[findIndex].author, newAuthor);
		printf("Nhap gia tien moi: ");
		scanf("%f", &(*Bk)[findIndex].price);
		removeBuffer();
		printf("Cap nhap thanh cong ! \n");
	}else{
		printf("Khong tim thay duoc ma sach ! \n");
	}
}
void sortBookPrice(Book **Bk, int *length, int choice){
	int i, j;
	Book temp;
	if(choice == 1){
		for(i = 0; i < (*length) -1 ;i ++){
			for(j = 0; j <(*length) - i - 1; j++){
				if((*Bk)[j].price > (*Bk)[j+1].price){
					temp = (*Bk)[j];
					(*Bk)[j] = (*Bk)[j +1];
					(*Bk)[j +1] = temp;
				}
			}
		}
		printf("Sap xep thanh cong !");
	}else if(choice == 2){
		for(i = 0; i < (*length) -1 ;i ++){
			for(j = 0; j <(*length) - i - 1; j++){
				if((*Bk)[j].price < (*Bk)[j+1].price){
					temp = (*Bk)[j];
					(*Bk)[j] = (*Bk)[j +1];
					(*Bk)[j +1] = temp;
				}
			}
		}
		printf("Sap xep thanh cong !");
	}else if(choice == 3){
		printf("Cam on Vi Da Den :D \n");
	}
	
	
}
void findBook(Book *Bk, int *length){
	int i;
	char findName[50];
	int findIndex;
	printf("Nhap ten ma ban muon tim: ");
	fgets(findName, 50, stdin);
	removeNewLine(findName);
	findIndex = -1;
	for(i = 0; i < *length; i++){
		if(strcmp(Bk[i].name, findName) == 0){
			findIndex = i;
			break;
		}
	}
	if(findIndex != -1){
		printf(">>> Da tim thay ! \n");
		printf("------------------------------------------------------------------------------------------------------\n");
		printf("|Ma Sach: %d | Ten: %s | Tac Gia: %s | Gia Tien : %.1f \n",Bk[findIndex].id ,Bk[findIndex].name, Bk[findIndex].author, Bk[findIndex].price);
		printf("------------------------------------------------------------------------------------------------------\n");
		printf("xuat hien o vi tri thu %d", findIndex + 1);
	}else{

		printf("Khong tim thay ten %s trong danh sach !", findName);
	}
}
void printMenu(){
	
		printf("\n\t\t\t++====================MENU====================++\n");
		printf("\t\t\t||%-44s||\n", "1. Nhap so luong va thong tin sach");
		printf("\t\t\t||%-44s||\n", "2. Hien thi thong tin sach");
		printf("\t\t\t||%-44s||\n", "3. Them sach vao vi tri bat ky");
		printf("\t\t\t||%-44s||\n", "4. Xoa sach theo ma sach");
		printf("\t\t\t||%-44s||\n", "5. Cap nhap thong tin theo ma sach");
		printf("\t\t\t||%-44s||\n", "6. Sap xep sach theo gia");
		printf("\t\t\t||%-44s||\n", "7. tim kiem theo ten sach");
		printf("\t\t\t||%-44s||\n", "8. Thoat");
		printf("\t\t\t++============================================++\n");
		printf("-------- Lua chon cua ban: ");
}

int main(){
	int choice, sortChoice;
	int size = 0;
	Book *menuBook = (Book*)malloc(size * sizeof(Book));
	if(menuBook == NULL){
		printf("Cap phat that bai !\n");
	}else{
		printf("Cap phat thanh cong !\n");
	} 
	do{
		printMenu();
		scanf("%d", &choice);
		removeBuffer();
		switch(choice){
			case 1 :{
				insertBook(&menuBook, &size);
				break;
			}
			case 2 :{
				printALL(&menuBook, &size);
				break;
			}
			case 3 :{
				addBook(&menuBook, &size);
				break;
			}
			case 4 :{
				deleteBook(&menuBook, &size);
				break;
			}
			case 5:{
				UpdateBook(&menuBook, &size);
				break;
			}
			case 6 :{
				printf("\t\t\t++====================MENU SAP XEP====================++\n");
				printf("\t\t\t||%-52s||\n", "1. Giam dan theo price");
				printf("\t\t\t||%-52s||\n", "2. Tang dan theo price");
				printf("\t\t\t||%-52s||\n", "3. Thoat");
				printf("\t\t\t++====================================================++\n");
				printf("-------- Lua chon cua ban: ");
				scanf("%d", &sortChoice);
				removeBuffer();
				sortBookPrice(&menuBook, &size, sortChoice);
				
				break;
			}
			case 7 :{
				findBook(menuBook, &size);
				break;
			}
			case  8 :
				free(menuBook);
				exit(0);
		}
	}while(1);
	
	
	return 0;
}
