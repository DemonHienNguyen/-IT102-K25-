#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
	char title[100];
	char author[50];
	float price;
}Book;

void removeNewLine(char *a){
	size_t len = strlen(a);
	a[len - 1] = '\0';
}
void removeBuffer(){
	int c;
	while((c = getchar()) != '\n' && c != EOF);
}

void insertBook(Book *Bk, int length);
void insertBook(Book *Bk, int length){
	int i;
	printf("--- Nhap thong tin cho Sach thu %d---\n", i+1);
	for( i =0 ; i < length; i++){
		printf("Nhap ten cua con sach thu %d: ", i+1);
		fgets(Bk[i].title, 50, stdin);
		removeNewLine(Bk[i].title);
		printf("Nhap ten Tac gia cua cuon sach thu %d: ",i+1);
		fgets(Bk[i].author, 50, stdin);
		removeNewLine(Bk[i].author);
		printf("Nhap Gia cua cuon sach Thu %d: ",i+1);
		scanf("%f", &Bk[i].price);
		removeBuffer();
		
	}
	
	
}



int main(){
	int i;
	int size = 3;
	Book book[size];
	insertBook(book,size);
	printf("Danh sach cac quyen sach\n");
	for( i = 0 ; i  <size; i++){
		printf("------------------------------------\n");
		printf("| Ten: %s | Tac Gia: %s | Gia: %.1f | \n", book[i].title, book[i].author, book[i].price);
		printf("------------------------------------\n");
	}
	
	return 0;
}

