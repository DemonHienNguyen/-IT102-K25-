#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct{
	char name[50]; 
	int age; 
	float grade;
		
}Sv;
void removeBuffer(){
	 int c;
	 while((c = getchar()) != '\n' && c != EOF);
}
void removeNewLine(char *a){
	 size_t len = strlen(a);
	 a[len -1] = '\0';
}

void insertStudent(Sv *ptr, int *length){
	int i;
	for(i = 0; i< *length; i++){
	printf("Nhap ten Hoc Sinh ");
	fgets(ptr[i].name, 50, stdin);
	removeNewLine(ptr[i].name);
	printf("Nhap Tuoi cua Hoc Sinh: ");
	do{
		scanf("%d", &ptr[i].age);
		if(ptr[i].age < 18 || ptr[i].age > 100){
			printf("Tuoi cua ban phai > 18 va < 100 ! \nVui long nhap lai: ");
		}
	}while(ptr[i].age < 18 || ptr[i].age > 100);
	removeBuffer();
	printf("Nhap Diem cua hoc sinh: ");
	do{
		scanf("%f", &ptr[i].grade);
		if(ptr[i].grade < 0 || ptr[i].grade > 10){
			printf("Diem cua ban phai thuoc (0 -> 10) ! \nVui long nhap lai: ");
		}
	}while(ptr[i].grade < 0 || ptr[i].grade > 10);
	removeBuffer();
	}
	printf("Them thanh cong ! \n");
}

void findStudent(Sv *ptr, int *length){
	int i;
	char findName[20];
	int find = 0;
	int findIndex;
	printf("Nhap ten can tim cua ban: ");
	fgets(findName, 20, stdin);
	removeNewLine(findName);
	for(i =0 ; i< *length; i++){
		if(strcmp(ptr[i].name, findName) == 0){
			find = i;
			break;
		}
	}
	if(find == i){
		printf("Da tim thay ! \n");
		printf("------------------------------------\n");
		printf("| Ten: %s | Tuoi : %d | Diem Trung Binh : %.1f \n", ptr[find].name, ptr[find].age, ptr[find].grade);
		printf("------------------------------------\n");
	}else if(find != i){
		printf("Khong tim thay sinh Vien %s ! ", ptr[find].name);
	}
	
}

int main(){
	int i;
	int size = 2;
	Sv *stu = (Sv*)malloc(size * sizeof(Sv));
	if(stu == NULL){
		printf("Cap phat fail roi em ! \n");
	}else{
		printf("Cap Phat thanh cong my man !\n");
	}
	insertStudent(stu, &size);
	for( i= 0 ; i < size ;i++){
		printf("------------------------------------\n");
		printf("| Ten: %s | Tuoi : %d | Diem Trung Binh : %.1f \n", stu[i].name, stu[i].age, stu[i].grade);
		printf("------------------------------------\n");
	}
	findStudent(stu, &size);
	
	free(stu);
	return 0;
}

