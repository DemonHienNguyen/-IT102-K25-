#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void addValue(Sv stu[], int *length){
	int i;
	int addIndex;
	printf("Nhap vi tri ma ban muon chen (1 -> %d): ", *length);
	scanf("%d", &addIndex);
	removeBuffer();
	// chuyen sang 0Base;
	int addIndex0 = addIndex - 1;
	for(i = *length ; i >= addIndex0; i--){
		stu[i] = stu[i-1];
		// ptr[i] = ptr[i-1];
	}
	printf("Nhap Id cua ban: ");
	scanf("%d", &stu[addIndex0].id);
	removeBuffer();
	printf("Nhap vao ten cua ban: ");
	fgets(stu[addIndex0].name, 20, stdin);
	removeNewLine(stu[addIndex0].name);
	printf("Nhap tuoi cua ban: ");
	scanf("%d", &stu[addIndex0].age);
	removeBuffer();
	printf("Nhap so dien thoai cua ban: ");
	fgets(stu[addIndex0].phoneNumber, 20, stdin);
	removeNewLine(stu[addIndex0].phoneNumber);
	(*length)++;
}

int main(){
	int i;
	int size = 5;
	Sv student[50] = {
	{1, "Nguyen Van A", 18, "0099"},
	{2, "Nguyen Van B", 18, "0099"},
	{6, "Nguyen Van c", 18, "0099"},
	{4, "Nguyen Van D", 18, "0099"},
	{3, "Nguyen Van E", 18, "0099"},
	};
	
	printf("---Thong tin hoc sinh vjp---\n");
	for(i= 0;  i < size; i ++){
		printf("ID: %d \n",student[i].id);
		printf("Ten: %s \n", student[i].name);
		printf("Tuoi: %d \n", student[i].age);
		printf("SDT: %s \n", student[i].phoneNumber);
		printf("------------------------------\n");
	}
	addValue(student, &size);
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

