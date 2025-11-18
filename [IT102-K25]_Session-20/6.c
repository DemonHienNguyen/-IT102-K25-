#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 50
typedef struct{
	int id;
	char name[20];
	int age;
	char phoneNumber[11];
}Sv;

void removeBuffer(){
	int c;
	while( (c = getchar()) != '\n' && c != EOF);
}
void removeNewLine(char *a){
	size_t len = strlen(a);
	a[len - 1] = '\0';
}

void addBottom(Sv ptr[], int *length){
	int index = *length;
	printf("Nhap Id cua ban: ");
	scanf("%d", &ptr[index].id);
	removeBuffer();
	printf("Nhap vao ten cua ban: ");
	fgets(ptr[index].name, 20, stdin);
	removeNewLine(ptr[index].name);
	printf("Nhap tuoi cua ban: ");
	scanf("%d", &ptr[index].age);
	removeBuffer();
	printf("Nhap so dien thoai cua ban: ");
	fgets(ptr[index].phoneNumber, 10, stdin);
	removeNewLine(ptr[index].phoneNumber);
	(*length)++;
}
 

int main(){
	int i;
	int size = 5;
	Sv student[50] = {
	{1, "Nguyen Van A", 18, "0099"},
	{2, "Nguyen Van B", 18, "1999"},
	{6, "Nguyen Van c", 18, "6699"},
	{4, "Nguyen Van D", 18, "0099"},
	{3, "Nguyen Van E", 18, "0099"},
	};
	printf("---Thong tin hoc sinh v---\n");
	for(i= 0;  i < size; i ++){
		printf("ID: %d \n",student[i].id);
		printf("Ten: %s \n", student[i].name);
		printf("Tuoi: %d \n", student[i].age);
		printf("SDT: %s \n", student[i].phoneNumber);
		printf("------------------------------\n");
	}
	addBottom(student, &size);
	printf("---Thong tin hoc sinh sau khi cap nhap---\n");
	for(i= 0;  i < size; i ++){
		printf("ID: %d \n",student[i].id);
		printf("Ten: %s \n", student[i].name);
		printf("Tuoi: %d \n", student[i].age);
		printf("SDT: %s \n", student[i].phoneNumber);
		printf("------------------------------\n");
	}
	
	
	return 0;
}

