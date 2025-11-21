#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// khai bao ham struct
typedef struct{
	char name[50];
	int age;
	float grade;	
}Sv;
// khai bao ham struct

// khai bao ham bo tro 
void removeBuffer(){
	 int c;
	 while((c = getchar()) != '\n' && c != EOF);
}
void removeNewLine(char *a){
	 size_t len = strlen(a); 
	 a[len -1] = '\0';
}
// khai bao ham bo tro 

// khai bao ham chuc nang//
void printMenu(); // in ra menu;
void insertStu(Sv **stu, int *length);
void printStu(Sv *stu, int *length);
void sumGrade(Sv *stu, int *length, float *sum);
// khai bao ham chuc nang//

void printMenu(){
		printf("\n\t\t\t++====================MENU====================++\n");
		printf("\t\t\t||%-44s||\n", "1. Nhap thong tin hoc sinh");
		printf("\t\t\t||%-44s||\n", "2. Hien thi thong tin Hoc sinh");
		printf("\t\t\t||%-44s||\n", "3. tinh diem trung binh cua tat ca sinh vien");
		printf("\t\t\t||%-44s||\n", "4. Thoat");
		printf("\t\t\t++============================================++\n");
		printf("-------- Lua chon cua ban: ");
}
void insertStu(Sv **stu, int *length){
	int index;
	int currentIndex = *length;
	printf("Vui long chon so luong hoc sinh: ");
	scanf("%d", &index);
	removeBuffer();
	Sv *temp = (Sv*)realloc((*stu),((*length) + index) * sizeof(Sv));
	(*stu) = temp;
	for(int i = 0; i < index; i++){
		printf(">>> Nhap thong tin cua hoc sinh thu %d <<< \n",currentIndex + i + 1);
		printf("Nhap ten hoc sinh: ");
		fgets((*stu)[currentIndex + i].name,50, stdin);
		removeNewLine((*stu)[currentIndex + i].name);
		printf("Nhap tuoi cua hoc sinh: ");
		scanf("%d", &(*stu)[currentIndex + i].age);
		removeBuffer();
		printf("Nhap diem cua hoc sinh: ");
		scanf("%f",&(*stu)[currentIndex + i].grade);
		removeBuffer();
		
	}
	printf("Nhap hoc sinh thanh cong ! \n");
	(*length) += index;
}
void printStu(Sv *stu, int *length){
	printf(" >>> Danh sach hoc sinh \n");
	printf("-------------------------------------\n");
	for(int i = 0; i < *length; i++){
		printf("-------------------------------------\n");
		printf("| Ten: %s | Tuoi: %d | Diem: %.1f | \n", (stu)[i].name, (stu)[i].age, (stu)[i].grade);
		printf("-------------------------------------\n");
	}
}
void sumGrade(Sv *stu, int *length, float *sum){
	*sum = 0;
	for(int i = 0 ; i < *length; i++){
		*sum += stu[i].grade;
	}
	printf("Vay tong trung binh diem cac hoc sinh la: %.1f", (*sum)/(*length));
}
int main(){
	int choice;
	float result = 0;
	int size = 0;
	Sv *menuStu = (Sv*)malloc(size *sizeof(Sv));
	if(menuStu == NULL){
		printf("Cap phat that bai roi em\n");
	}else{
		printf("Cap phat thanh cong my man \n");
	}
	do{
		printMenu();
		scanf("%d", &choice);
		removeBuffer();
		switch (choice){
			case 1 :{
				insertStu(&menuStu, &size);
				break;
			}
			case 2 :{
				printStu(menuStu, &size);
				break;
			}
			case 3 :{
				sumGrade(menuStu,&size,&result);
				break;
			}
			case 4 :
				free(menuStu);
				exit(0);
		}
	}while(1);
	return 0;
}

