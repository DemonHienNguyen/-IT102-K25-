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
void printALL(Book *Bk, int *length);
int insertBook(Book **Bk, int *length);
void deleteBook(Book *Bk, int *length);
void UpdateBook(Book *Bk);
void sortBookPrice(Book *Bk, int *length);
void findBook(Book *Bk, int *length);
void addBook(Book **Bk, int *length);
// khai bao bien //

// bat dau lam ham !
void printALL(Book *Bk, int *length){
	int i;
	if (*length == 0){
		printf("-----------------------------\n");
		printf(">>>>>>>Danh sach trong<<<<<<<\n");
		printf("-----------------------------\n");
	}else{
		printf(">>>>Danh sach cac quyen Sach<<< \n");
		printf("--------------------------\n");
		for(i = 0 ; i  < *length; i++){
		printf("-----------------------------------------------------------------------------------------------------\n");
		printf("| %-8s: %-3d | %-8s: %-20s | %-7s: %-20s | %-8s: %.1f |\n","Ma Sach",Bk[i].id, "Ten Sach", Bk[i].name,"Tac Gia", Bk[i].author, "Gia Tien", Bk[i].price);
		printf("-----------------------------------------------------------------------------------------------------\n");
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
	Book *temp = (Book*)realloc(*Bk, *length  + index * sizeof(Book));
	*Bk = temp;
	for(i = 0; i < index; i++){
		printf(">>> Thong tin cua cuon sach thu %d <<< \n",*length + i+1);
		(*Bk)[currentIndex + i].id = currentIndex + i + 1;
		printf("Nhap ten cua cuon sach: ");
		fgets((*Bk)[currentIndex].name, 50, stdin);
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
void deleteBook(Book *Bk, int *length){
	
	printf("");
}


void printMenu(){
		printf("\t\t\t++====================MENU====================++\n");
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
	int choice, sortchoie;
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
		switch(choice){
			case 1 :{
				insertBook(&menuBook, &size);
				break;
			}
			case 2 :{
				printALL(menuBook, &size);
				break;
			}
			case 3 :{
				break;
			}
			case 4 :{
				break;
			}
			case 5:{
			
				break;
			}
			case 6 :{
				break;
			}
			case 7 :{
				break;
			}
			case  8 :
				exit(0);
		}
	}while(1);
	
	free(menuBook);
	return 0;
}

