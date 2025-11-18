#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
	char Name[20]; 
	int Age;
	char PhoneNumber[10];
}Sv;

void removeBuffer(){
	int c;
	while( (c = getchar()) != '\n' && c != EOF);
}

void removeNewLine(char *a){
	size_t len = strlen(a);
	a[len -1] = '\0';
}

void insertName(Sv *ptr){
	printf("Nhap vao ten cua ban: ");
	fgets(ptr -> Name, 20, stdin);
	removeNewLine(ptr -> Name);
	printf("Nhap tuoi cua ban: ");
	scanf("%d", &ptr -> Age);
	removeBuffer();
	printf("Nhap so dien thoai cua ban: ");
	fgets(ptr -> PhoneNumber, 10, stdin);
	removeNewLine(ptr -> PhoneNumber);
}

int main(){
	Sv student01;
	insertName (&student01);
	printf("Thong tin Ca nhan: \n");
	printf("--------------------------\n");
	printf("Ten: %s \n",student01.Name);
	printf("Tuoi: %d \n",student01.Age);
	printf("So dien thoai: %s \n", student01.PhoneNumber);
	printf("--------------------------\n");
	return 0;
}

