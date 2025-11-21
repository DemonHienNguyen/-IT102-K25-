#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
	int day;
	int month;
	int year;
}Birth;


typedef struct{
	int id;
	char name[50];
	char address[50];
	char phoneNumber[15];
	Birth Bir;
}Stu;


void removeBuffer(){
	 int c;
	 while((c = getchar()) != '\n' && c != EOF);
}
void removeNewLine(char *a){
	 size_t len = strlen(a);
	 a[len -1] = '\0';
}

// khai bao bien 
void enterStudent(Stu **stuPtr, int *length);
void printStudent(Stu *stuPtr, int *length);
void addBottomStudent(Stu **stuPtr, int *length);
void deleteStudent(Stu **stuPtr, int *length);
void updateStudent(Stu *stuPtr , int *length);
void sortStudentASCName(Stu *stuPtr, int *length);
void findStudentById(Stu *stuPtr, int *length);
// khai bao bien
 
 /*
 bat dau lam ham ! 
 */
 
//          >>> solo <<< 
void enterStudent(Stu **stuPtr, int *length){
	int index;
	int currentIndex = *length;
	printf("Vui long nhap so luong hoc sinh can them: ");
	scanf("%d", &index);
	removeBuffer();
	Stu *temp = (Stu*)realloc((*stuPtr), ((*length) + index) * sizeof(Stu));
	(*stuPtr) = temp;
	for(int i = 0; i < index; i ++){
		printf(">>>> Thong tin  cua hoc sinh thu %d <<<< \n", currentIndex + i + 1);
		(*stuPtr)[currentIndex + i].id = 100 + currentIndex + i;
		printf("Vui long nhap ten cua hoc sinh: ");
		fgets((*stuPtr)[currentIndex + i].name, 100, stdin);
		removeNewLine((*stuPtr)[currentIndex + i].name);
		printf("Vui long nhap ngay/thang/nam: ");
		scanf("%d/%d/%d", &(*stuPtr)[currentIndex + i].Bir.day, &(*stuPtr)[currentIndex + i].Bir.month, &(*stuPtr)[currentIndex + i].Bir.year);
		removeBuffer();
		printf("Vui long nhap dia chi cua hoc sinh: ");
		fgets((*stuPtr)[currentIndex + i].address, 50, stdin);
		removeNewLine((*stuPtr)[currentIndex + i].address);
		printf("Vui long nhap So dien thoai cua hoc sinh: ");
		fgets((*stuPtr)[currentIndex + i].phoneNumber, 50, stdin);
		removeNewLine((*stuPtr)[currentIndex + i].phoneNumber);
	}
	(*length) += index;
	
}
void printStudent(Stu *stuPtr, int *length){
	if((*length) == 0){
		printf("---------------------------------------\n");
		printf(">>>>>>>>>>>> Danh Sach Trong <<<<<<<<<<\n");
		printf("---------------------------------------\n");
	}else{
		printf("-------------------------------------------\n");
		printf(">>>>>>>>>>>> Danh Sach Sinh Vien <<<<<<<<<<\n");
		printf("-------------------------------------------\n");
		for(int i = 0 ;i < (*length); i++){
			printf("------------------------------------------------------------------------------------------------------------------\n");
			printf("|Ma ID: %3d  |Ten: %-20s  |Birth: %02d/%02d/%4d  |Dia chi: %-10s|SDT: %-15s  |\n"
			, stuPtr[i].id, 
			stuPtr[i].name, 
			stuPtr[i].Bir.day,stuPtr[i].Bir.month, stuPtr[i].Bir.year, 
			stuPtr[i].address, 
			stuPtr[i].phoneNumber);
			printf("------------------------------------------------------------------------------------------------------------------\n");
		}
	}
}
void addBottomStudent(Stu **stuPtr, int *length){
	Stu *temp = (Stu*)realloc((*stuPtr), ((*length) + 1)*sizeof(Stu));
	(*stuPtr) = temp;
	int currentIndex  = *length;
	printf(">>>> Them hoc sinh vao cuoi mang <<<< \n");
	printf(">>>> Thong tin  cua hoc sinh thu %d <<<< \n", currentIndex + 1);
		(*stuPtr)[currentIndex].id = 100 + currentIndex;
		printf("Vui long nhap ten cua hoc sinh: ");
		fgets((*stuPtr)[currentIndex].name, 100, stdin);
		removeNewLine((*stuPtr)[currentIndex].name);
		printf("Vui long nhap ngay/thang/nam: ");
		scanf("%d/%d/%d", &(*stuPtr)[currentIndex].Bir.day, &(*stuPtr)[currentIndex].Bir.month, &(*stuPtr)[currentIndex].Bir.year);
		removeBuffer();
		printf("Vui long nhap dia chi cua hoc sinh: ");
		fgets((*stuPtr)[currentIndex].address, 50, stdin);
		removeNewLine((*stuPtr)[currentIndex].address);
		printf("Vui long nhap So dien thoai cua hoc sinh: ");
		fgets((*stuPtr)[currentIndex].phoneNumber, 50, stdin);
		removeNewLine((*stuPtr)[currentIndex].phoneNumber);
	(*length)++;
	printf("Them thanh cong ! \n");
}
void deleteStudent(Stu **stuPtr, int *length){
	int findID;
	int find;
	int sure;
	printf("Nhap Ma sinh vien ma ban muon tim: ");
	scanf("%d", &findID);
	removeBuffer();
	find = -1;
	for(int i = 0; i < *length; i++){
		if((*stuPtr)[i].id == findID){
			find = i;
			break;
		}
	}
	if(find != -1){
		printf("Da Tim thay ! \n");
		printf("------------------------------------------------------------------------------------------------------------------\n");
		printf("|Ma ID: %3d  |Ten: %-20s  |Birth: %02d/%02d/%4d  |Dia chi: %-10s|SDT: %-15s  |\n"
		, (*stuPtr)[find].id, 
		(*stuPtr)[find].name, 
		(*stuPtr)[find].Bir.day,(*stuPtr)[find].Bir.month, (*stuPtr)[find].Bir.year, 
		(*stuPtr)[find].address, 
		(*stuPtr)[find].phoneNumber);
		printf("------------------------------------------------------------------------------------------------------------------\n");
		printf("Ban co muon xoa hay khong (1: Yes | 0: No): ");
		scanf("%d",&sure);
		removeBuffer();
		if(sure == 1){
//			Stu *temp  = (Stu*)realloc((*stuPtr), ((*length) -1) * sizeof(Stu));
//			(*stuPtr) = temp;
			for(int j = find; j < (*length) - 1; j++){
				(*stuPtr)[j] = (*stuPtr)[j+1];
			}
			(*length)--;
			printf("Xoa thanh cong ! \n");
			if((*length) > 0){
				Stu *temp  = (Stu*)realloc((*stuPtr), ((*length) -1) * sizeof(Stu));
				if(temp == NULL){
					printf("Cap phat bo nho that bai \n");
				}else{
					(*stuPtr) = temp;
				}
			}else{
				free((*stuPtr));
				*stuPtr = NULL;
			}
			
		}else{
			printf("CAm on Vi DA DEN ! \n");
		}
	}else if(find == -1){
		printf("Khong tim thay Ma %d trong danh sach ! \n", findID);
	}
}
void updateStudent(Stu *stuPtr , int *length){
	int findID;
	int find;
	int sure;
	char newName[50];
	char newAddress[20];
	char newPhoneNumber[15];
	printf("Nhap Ma sinh vien ma ban muon tim: ");
	scanf("%d", &findID);
	removeBuffer();
	find = -1;
	for(int i = 0; i < *length; i++){
		if(stuPtr[i].id == findID){
			find = i;
			break;
		}
	}
	if(find != -1){
		printf("Da Tim thay ! \n");
		printf("------------------------------------------------------------------------------------------------------------------\n");
		printf("|Ma ID: %3d  |Ten: %-20s  |Birth: %02d/%02d/%4d  |Dia chi: %-10s|SDT: %-15s  |\n"
		, stuPtr[find].id, 
		stuPtr[find].name, 
		stuPtr[find].Bir.day,stuPtr[find].Bir.month, stuPtr[find].Bir.year, 
		stuPtr[find].address, 
		stuPtr[find].phoneNumber);
		printf("------------------------------------------------------------------------------------------------------------------\n");
		printf("Ban co muon Cap nhap khong (1: Yes | 0: No): ");
		scanf("%d",&sure);
		removeBuffer();
		if(sure == 1){
			printf(">>> Nhap thong tin moi cho hoc sinh %d <<<\n", findID);
			printf("Vui long nhap ten cua hoc sinh moi: ");
			fgets(newName, 100, stdin);
			removeNewLine(newName);
			strcpy(stuPtr[find].name,newName);
			printf("Vui long nhap ngay/thang/nam moi: ");
			scanf("%d/%d/%d", &stuPtr[find].Bir.day, &stuPtr[find].Bir.month, &stuPtr[find].Bir.year);
			removeBuffer();
			printf("Vui long nhap dia chi moi cua hoc sinh: ");
			fgets(newAddress, 50, stdin);
			removeNewLine(newAddress);
			strcpy(stuPtr[find].address,newAddress);
			printf("Vui long nhap So dien thoai cua hoc sinh: ");
			fgets(newPhoneNumber, 50, stdin);
			removeNewLine(newPhoneNumber);
			strcpy(stuPtr[find].phoneNumber,newPhoneNumber);
			printf("Cap nhap thanh cong ! \n");
		}else{
			printf("CAm on Vi DA DEN ! \n");
		}
	}else if(find == -1){
		printf("Khong tim thay Ma %d trong danh sach ! \n", findID);
	}
}
void sortStudentASCName(Stu *stuPtr, int *length){
	// selection sort
	int minName;
	Stu temp;
	for(int i = 0 ; i < (*length) -1 ;i++){
		minName = i;
		for(int j = i+1; j < (*length); j++){
			if(strcmp(stuPtr[j].name,stuPtr[minName].name) < 0){
				minName = j;
			}
		}
		if(minName != i){
			temp = stuPtr[minName];
			stuPtr[minName] =stuPtr[i];
			stuPtr[i]= temp;
		}
	}
	printf("SAp xep thanh cong ! \n");
}
void findStudentById(Stu *stuPtr, int *length){
	int findID;
	int find;
	printf("Nhap Ma sinh vien ma ban muon tim: ");
	scanf("%d", &findID);
	removeBuffer();
	find = -1;
	for(int i = 0; i < *length; i++){
		if(stuPtr[i].id == findID){
			find = i;
			break;
		}
	}
	if(find != -1){
		printf("Da Tim thay ! \n");
		printf("------------------------------------------------------------------------------------------------------------------\n");
		printf("|Ma ID: %3d  |Ten: %-20s  |Birth: %02d/%02d/%4d  |Dia chi: %-10s|SDT: %-15s  |\n"
		, stuPtr[find].id, 
		stuPtr[find].name, 
		stuPtr[find].Bir.day,stuPtr[find].Bir.month, stuPtr[find].Bir.year, 
		stuPtr[find].address, 
		stuPtr[find].phoneNumber);
		printf("------------------------------------------------------------------------------------------------------------------\n");
	}else{
		printf("Khong tim thay Ma ID trong Danh sach ! \n");
	}
}



//      >>> ket thuc ham <<< 
void printMenu(){
		printf("\n\t\t\t++====================MENU====================++\n");
		printf("\t\t\t||%-44s||\n", "1. Nhap thong tin sinh vien");
		printf("\t\t\t||%-44s||\n", "2. Hien thi thong tin sinh vien");
		printf("\t\t\t||%-44s||\n", "3. Them sinh vien vao cuoi danh sach");
		printf("\t\t\t||%-44s||\n", "4. Xoa sinh vien theo ma sinh vien");
		printf("\t\t\t||%-44s||\n", "5. Cap nhap sinh vien theo ma sinh vien");
		printf("\t\t\t||%-44s||\n", "6. Sap xep sinh vien (A -> Z)");
		printf("\t\t\t||%-44s||\n", "7. Tim kiem sinh vien theo ma sinh vien");
		printf("\t\t\t||%-44s||\n", "8. Thoat");
		printf("\t\t\t++============================================++\n");
		printf("-------- Lua chon cua ban: ");
}

int main(){
	int choice;
	int size = 0;
	Stu *menuStu = (Stu*)malloc( size * sizeof(Stu));
	if(menuStu == NULL){
		printf("Cap phat that bai ! \n");
	}else{
		printf("Cap phat thanh cong ! \n");
	}
	do{
		printMenu();
		scanf("%d", &choice);
		removeBuffer();
		switch(choice){
			case 1 :{
				enterStudent(&menuStu, &size);
				break;
			}
			case 2 :{
				printStudent(menuStu, &size);
				break;
			}
			case 3 :{
				addBottomStudent(&menuStu, &size);
				break;
			}
			case 4 :{
				deleteStudent(&menuStu, &size);
				break;
			}
			case 5 :{
				updateStudent(menuStu, &size);
				break;
			}
			case 6 :{
				sortStudentASCName(menuStu, &size);
				break;
			}
			case 7 :
				findStudentById(menuStu, &size);
				break;
			case 8 :
				free(menuStu);
				exit(0);
		}

	}while(1);
	return 0;
}
