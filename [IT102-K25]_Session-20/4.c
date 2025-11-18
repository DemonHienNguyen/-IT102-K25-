#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct{
	int id;
	char name[20];
	int age;
	char phoneNumber[11];
}Sv ;

void removeBuffer(){
	int c;
	while( (c = getchar()) != '\n' && c != EOF);
}

void removeNewLine(char *a){
	size_t len = strlen(a);
	a[len - 1] = '\0';
}
void insertInfor(Sv ptr[]);

void insertInfor(Sv ptr[]){
	int i;
	for(i =  0; i < 5; i ++){
		printf("---- Nhap thuong tin hoc sinh thu %d---- \n",i +1);
		ptr[i].id = i+1;
		printf("Nhap ten cua Hoc sinh thu %d:  ", i+1);
		fgets(ptr[i].name, 20, stdin);
		removeNewLine(ptr[i].name);
		printf("Nhap tuoi cua Hoc sinh thu %d:  ", i+1);
		scanf("%d", &ptr[i].age);
		removeBuffer();
		printf("Nhap SDT cua Hoc sinh thu %d:  ", i+1);
		fgets(ptr[i].phoneNumber, 50, stdin);
		removeNewLine(ptr[i].phoneNumber);
	}
}

int main(){
	int i; 
	Sv student[50];
	insertInfor(student);
	printf("---Thong tin hoc sinh vjp---\n");
	for(i= 0;  i < 5; i ++){
		printf("ID: %d \n",student[i].id);
		printf("Ten: %s \n", student[i].name);
		printf("Tuoi: %d \n", student[i].age);
		printf("SDT: %s \n", student[i].phoneNumber);
		printf("------------------------------\n");
	}
	return 0;
}

