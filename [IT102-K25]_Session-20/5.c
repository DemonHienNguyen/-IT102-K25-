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
// void updateVlalue(struct Sv ptr[]);
void updateValue(Sv ptr[]){
	int i, VL, updateIndex = 0;
	int found = 0;
	char newName[20];
	printf("Nhap id ma ban muon tim: ");
	scanf("%d", &VL);
	removeBuffer();
	for(i = 0; i < 50; i++){
		if(ptr[i].id == VL){
			found = 1;
			updateIndex = i;
			break;
		}
	}
	if(found){
		printf("ID : %d  -  %s \n", VL, ptr[updateIndex].name);
		printf("vui long cap nhap lai ten: ");
		fgets(newName, 20, stdin);
		removeNewLine(newName);
		strcpy(ptr[updateIndex].name, newName);
		printf("Vui long nhap lai tuoi: ");
		scanf("%d", &ptr[updateIndex].age);
		removeBuffer();
		printf("Cap nhap thanh cong !");
	}else{
		printf("Khong tim thay Id ! \n");
	}
}

int main(){
	int i;
	// struct Sv student
	Sv student[50] = {
	{1, "Nghiem Dinh Binh", 99, "09778"},
	{2, "Nguyen Van B", 18, "0099"},
	{6, "Nguyen Van c", 18, "0099"},
	{4, "Nguyen Van D", 18, "0099"},
	{3, "Nguyen Van E", 18, "0099"},
	};
	printf("---Thong tin hoc sinh vjp---\n");
	for(i= 0;  i < 5; i ++){
		printf("ID: %d \n",student[i].id);
		printf("Ten: %s \n", student[i].name);
		printf("Tuoi: %d \n", student[i].age);
		printf("SDT: %s \n", student[i].phoneNumber);
		printf("------------------------------\n");
	}
	updateValue(student);
	printf("---Thong tin hoc sinh sau khi cap nhap---\n");
	for(i= 0;  i < 5; i ++){
		printf("ID: %d \n",student[i].id);
		printf("Ten: %s \n", student[i].name);
		printf("Tuoi: %d \n", student[i].age);
		printf("SDT: %s \n", student[i].phoneNumber);
		printf("------------------------------\n");
	}
	
	
	return 0;
}

