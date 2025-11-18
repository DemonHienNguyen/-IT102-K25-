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

void deleteValue(Sv ptr[], int *length){
	int i, deleteIndex = 0;
	int IdValue;
	int found = 0;
	printf("Nhap id ma ban muon tim: ");
	scanf("%d", &IdValue);
	removeBuffer();
	for(i = 0; i < 50; i++){
		if(ptr[i].id == IdValue){
			found = 1;
			deleteIndex = i;
			break;
		}
	}
	if(found){
		printf("ID : %d  -  %s \n", IdValue, ptr[deleteIndex].name);
		for(i = deleteIndex; i<*length; i++){
			ptr[i] = ptr[i+1];
		}
		printf("xoa nhap thanh cong !\n");
	}else{
		printf("Khong tim thay Id ! \n");
	}
	(*length)--;
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
	for(i= 0;  i < 5; i ++){
		printf("ID: %d \n",student[i].id);
		printf("Ten: %s \n", student[i].name);
		printf("Tuoi: %d \n", student[i].age);
		printf("SDT: %s \n", student[i].phoneNumber);
		printf("------------------------------\n");
	}
	deleteValue(student, &size);
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

