#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
	char name[50];
	int age;
	float grade;
	
}Student ;
void removeBuffer();
void removeNewLine(char *a);
void insertCar(Student *ptr);

void removeNewLine(char *a){
	size_t len = strlen(a);
	a[len - 1] = '\0';
}
void removeBuffer(){
	int c;
	while((c = getchar()) != '\n' && c != EOF);
}

void insertCar(Student *ptr){
	printf("Nhap ten Hoc Sinh ");
	fgets(ptr -> name, 50, stdin);
	removeNewLine(ptr -> name);
	printf("Nhap Tuoi cua Hoc Sinh: ");
	scanf("%d", &ptr -> age);
	removeBuffer();
	printf("Nhap Diem cua hoc sinh: ");
	scanf("%f", &ptr -> grade);
	removeBuffer();
}



int main(){
	Student student1;
	insertCar(&student1);
	printf("----- Thong Tin Hoc Sinh ----- \n");
	printf("Ten Hoc Sinh: %s \n", student1.name);
	printf("Tuoi: %d \n",student1.age);
	printf("Diem Hoc Sinh: %.1f \n",student1.grade);
	
	
	
	
	

	return 0;
}

