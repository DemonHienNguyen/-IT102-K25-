#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define EMP_PER_PAGE 5
#define MAX_TIME_EMP 100
typedef struct{
	char empId[20];  // id cua nhan vien
	char nameEmp[50]; // ten nhan vien
	char position[15]; // chuc vu nhan vien
	double baseSalary; // luong co ban
	int workDay; // ngay cong tinh tu ( 0 )
}Employee;

typedef struct{
	char logId[20]; // Mã giao dich / nhat ky (Sinh ngau nhiên hoac tu tang). 
	char empId[20]; // ma tai khoan nhan vien
	char date[20]; //ngay cham cong (ví d?: "DD/MM/YYYY").
	char status[10]; //loai cham cong (Ví d?: "Ði làm", "Nghi").
}TimeSheet;
// ham phu tro 
void removeBuffer(){
	 int c;
	 while((c = getchar()) != '\n' && c != EOF);
}

void removeNewLine(char *a){
	 size_t len = strlen(a);
	 a[len -1] = '\0';
}

void getToUpper(char *b, int size){
	for(int i = 0; i < size; i++){
		b[i] = toupper(b[i]);
	}
}
void deleteCharactor(char *string, int index){
	int length = strlen(string);
	for(int i = index; i < length - 1; i++){
		string[i] = string[i+1];
	}
	string[length-1] = '\0';
}
void removeSpace (char *str){
	int index = 0;
	while(str[index] == ' '){
		deleteCharactor(str, index);
	}
}

int onlySpace(char *str){
	char temp[100];
	strcpy(temp, str);
	removeSpace(temp);
	if(strlen(temp) == 0){
		return 1;
	}
	return 0;
	
}

void getString(char *c, int max, char *something){
	int sizeOfString;
	int sizeIndex;
	int inputIsTruncated;
	do{
		printf("%s (max %d ky tu): ", something, max - 1);
		if(fgets(c, max, stdin) == NULL){
			printf("Loi Tran Bo Nho hoac EOF ! \n");
		}
		
		sizeIndex = strcspn(c, "\n");
		// abc\n   abcdefh\n
		if(c[sizeIndex] != '\n'){
			inputIsTruncated = 1;
			int c;
			while((c = getchar()) != '\n' && c !=EOF);
		}else{
			c[sizeIndex]  = '\0';
			inputIsTruncated = 0;
		}
		
		sizeOfString = (int)strlen(c);
		
		if(inputIsTruncated){
			printf("Nhap da qua muc chi dinh !\n");
			continue;
		}
		if(sizeOfString == 0 ){
			printf("Loi !\nVui long nhap lai: ");
		}else if(onlySpace(c)){
			printf("khong duoc chua dau cach va khong duoc bo trong !\n");
		}else{
			break;
		}
	}while(1);
}
int isDigit(char *b, int size){
	for(int i = 0; i < size; i++){
		if(isdigit(b[i])){
			return 1;
		}
	}
	return 0;
}


// ham phu tro

// ham dac biet
void inputToName(char *a, int size){
	int appare = 0;
	for(int i = 0; i < size; i++){
		if(a[i] == ' '){
			appare = 0;
		}else if(!appare){
			a[i] = toupper(a[i]);
			appare = 1;
		}else{
			a[i] = tolower(a[i]);
		}
	}
}
void valudateChoice(int *choicePtr){
	char input[100];
	int validate = 0;
	do{
		fgets(input, 100, stdin);
		input[strcspn(input, "\n")]= '\0';
		if(strlen(input) == 0){
			printf("Dau vao khong duoc de trong ! \nVui long nhap lai: ");
			continue;
		}
		char *endPtr;
		long temp = strtol(input, &endPtr,10);
		// cu phap strtol(bien can bien thanh kieu long, con tro khi chay chuoi (Aka: duyet phan tu ), He co so)
		if(*endPtr == '\0' && input[0] != '\0'){
			*choicePtr = (int)temp;
			 validate = 1;
		}else{
			printf("Vui long chi nhap so ! \nVui long nhap lai: ");
		}
	}while(!validate);
}
void valudateSalary(double *choicePtr){
	char input[100];
	int validate = 0;
	do{
		fgets(input, 100, stdin);
		input[strcspn(input, "\n")]= '\0';
		if(strlen(input) == 0){
			printf("Dau vao khong duoc de trong ! \nVui long nhap lai: ");
			continue;
		}
		char *endPtr;
		double temp = strtod(input, &endPtr);
		// cu phap strtol(bien can bien thanh kieu long, con tro khi chay chuoi (Aka: duyet phan tu ), He co so)
		if(*endPtr == '\0' && input[0] != '\0'){
			*choicePtr = temp;
			 validate = 1;
		}else{
			printf("Vui long chi nhap so thap phan ! \nVui long nhap lai: ");
		}
	}while(!validate);
}
int forSure(int choice, char *something){
	printf("Ban co chac %s hay khong\n(1: Yes|0: No): ", something);
	do{
		valudateChoice(&choice);
		if( choice > 1 || choice < 0){
			printf("Vui long chi chon 0 Hoac 1: ");
		}
	}while( choice > 1 || choice < 0);
	return choice;
}
int validateDate(char *datePtr){
	int day, month, year;
	int is_leap;
	
	//                 day/month/year
	if(sscanf(datePtr, "%d/%d/%d", &day, &month, &year ) != 3){
		return 0;
	}
	if(month < 1 || month > 12 ||day < 1 || day > 31){
		return 0;
	}else{
		is_leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
		int days_in_month[] = {0, 31, 28 + is_leap, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if(month > days_in_month[month]){
			return 0;
		}
	}
	return 1;
}
// ham dac biet

// ham in an
void printLine(){
	printf("+--------------------------------------------------------------------------------------------------------------+\n");
}
void displayEmployee(const Employee *emp) {
    printf("|Ma ID: %-10s |Ten: %-20s |Chuc vu: %-10s |Luong: %-15.1lf      |Ngay cong: %03d |\n",
        emp->empId,
        emp->nameEmp,
        emp->position, 
        emp->baseSalary,
        emp->workDay);
}
void printMenu(){
	printf("\n\t\t\t++====================MENU====================++\n");
	printf("\t\t\t||%-44s||\n", "1. Quan ly");
	printf("\t\t\t||%-44s||\n", "2. Nhan Vien");
	printf("\t\t\t||%-44s||\n", "3. Thoat ");
	printf("\t\t\t++============================================++\n");
	printf("-------- Lua chon cua ban: ");
}
void managementList(){ // danh sach quan ly
	printf("\n\t\t\t++===========MENU QUAN LY============++\n");
	printf("\t\t\t||%-35s||\n", "1. Quan ly ho so va tuyen dung");
	printf("\t\t\t||%-35s||\n", "2. Quan ly nhan su");
	printf("\t\t\t||%-35s||\n", "3. Quan ly du lieu va bao cao");
	printf("\t\t\t||%-35s||\n", "4. Quay lai ");
	printf("\t\t\t++===================================++\n");
	printf("-------- Lua chon cua ban: ");
}
void profileManagementList(){ // quan ly ho so
	printf("\n\t\t\t++===========QUAN LY HO SO===========++\n");
	printf("\t\t\t||%-35s||\n", "1. Them Nhan Vien Moi");
	printf("\t\t\t||%-35s||\n", "2. Cap nhap ho so nhan vien");
	printf("\t\t\t||%-35s||\n", "3. Quay lai ");
	printf("\t\t\t++===================================++\n");
	printf("-------- Lua chon cua ban: ");
}
void civilAdministrationList(){ // quan ly nhan su
	printf("\n\t\t\t++==============QUAN LY NHAN SU===============++\n");
	printf("\t\t\t||%-44s||\n", "1. Sa thai nhan vien");
	printf("\t\t\t||%-44s||\n", "2. Quay lai");
	printf("\t\t\t++============================================++\n");
	printf("-------- Lua chon cua ban: ");
}
void dataManagementAndReportingList(){  // quan ly du lieu va bao cao
	printf("\n\t\t\t++=========QUAN LY DU LIEU VA BAO CAO=========++\n");
	printf("\t\t\t||%-44s||\n", "1. Hien thi danh sach nhan vien");
	printf("\t\t\t||%-44s||\n", "2. Tra cuu ho so");
	printf("\t\t\t||%-44s||\n", "3. Sap xep danh sach nhan vien");
	printf("\t\t\t||%-44s||\n", "4. Quay lai ");
	printf("\t\t\t++============================================++\n");
	printf("\t\t\t-------- Lua chon cua ban: ");
	
}
void employeeList(){ // quan ly nhan vien
	printf("\n\t\t\t++=====MENU NHAN VIEN=====++\n");
	printf("\t\t\t||%-22s  ||\n", "1. Cham cong");
	printf("\t\t\t||%-22s  ||\n", "2. Bang cham cong");
	printf("\t\t\t||%-22s  ||\n", "3. Quay lai");
	printf("\t\t\t++========================++\n");
	printf("\t\t\t-------- Lua chon cua ban: ");
}
//ham in an

// khai bao bien
void insertEmployee(Employee **empPtr, int *length, int *employee);
void printEmployee(Employee *empPtr, int *length, int *employee);
void updateEmployee(Employee *empPtr, int *length);
void DismissEmployee(Employee *empPtr, int *length, int *employee);
void findEmployeeByName(Employee *empPtr, int *length);
void sortBySalary(Employee *empPtr, int *length, int*sortchoice, int *employee);
void attendanceForTheDay(Employee *empPtr, TimeSheet *empTimePtr,int *length , int *timeSheetLength);
void viewTheWorkSchedule(Employee *empPtr, TimeSheet *empTimePtr,int *length,int *timeSheetLength);
//khai bao bien
 
// bat dau lam ham
void insertEmployee(Employee **empPtr, int *length, int *employee){
	int index;
	int currentIndex = *length;
	int size;
	int isDuplicated;
	char nameIdUnique[20];
	printf("So Luong Nhan Vien Dang Co: %d  \n", (*employee));
	printf("Vui long them so luong nhan vien moi (Toi da 100 nhan vien): ");
	do{
		valudateChoice(&index);
		if(index < 0){
			printf("Loi ! vui long nhap so luong duong: ");
		}else{
			break;
		}
	}while(1);
	if((*length) + index > 100){
		printf("Danh sach nhan vien da day ! khong the them\n");
	}else{
		// tac dung cua **
		// van de cap phat bo nho 
		// khi cap phat bo nho ban dau la ta dang cap phat cho con tro
		// con khi cap phat lai bo nho trong ham thi khi ta dung *ptr thi no chi luu ban sao cua dia chi ma mang ban truyen vao ( con tro voi con tro ) 
		// va khi realloc thanh cong thi no phai di chuyen toan bo du lien sang mot dia chi moi tren bo nho heap
		// va dia chi moi nay se gan lai cho ptr trong ham dan den sau khi ket thuc thi bien cuc bo ptr bi huy -> dia chi moi no chi luu o trong ham con 
		// bo nho cu van o giu nguyen khong doi
		// -> giai phap dung con tro cap hai tu la ( con tro tro den con tro)
		// khi ban truyen &emplist vao trong ham
		// ptr: luu tru dia chi bien cua emplist
		// *ptr: tuong duong voi emplist o ham main 
		// hay tom gon (chuyen tham chieu);
		Employee *temp = (Employee*)realloc((*empPtr), ((*length) + index) *sizeof(Employee));
		(*empPtr) = temp;
		for(int i = 0; i < index; i++){
			printf(">>> Nhap thong tin cua nhan vien thu %d  <<< \n", currentIndex + i +1);
			do{
				getString(nameIdUnique, 21, "Nhap ma Id cua nhan vien");
				isDuplicated = 0;
				for(int j = 0 ; j < currentIndex + i; j++){
					if(strcmpi(nameIdUnique, (*empPtr)[j].empId) == 0){
						isDuplicated = 1;
						break;
					}
				}
				if(isDuplicated == 1){
					printf("Vui long nhap ma ID khac cua nhan vien ! Ma ID da ton tai\n");
				}else{
					strcpy((*empPtr)[currentIndex + i].empId,nameIdUnique);
					break;	
				}
			}while(1);
			
			
			do{
				getString((*empPtr)[currentIndex + i].nameEmp, 51, "Vui long nhap ten cua nhan vien");
				size = strlen(((*empPtr)[currentIndex + i].nameEmp));
				if (isDigit ((*empPtr)[currentIndex + i].nameEmp, size )){
					printf("Vui Long Nhap Ten Ma khong co so !\n");
				}else{
					inputToName((*empPtr)[currentIndex + i].nameEmp, size);
					break;
				}
			}while(1);
				do{
					getString((*empPtr)[currentIndex + i].position, 16, "Nhap chuc vu cua ban");
					size = strlen((*empPtr)[currentIndex + i].position);
						if(isDigit((*empPtr)[currentIndex + i].position, size)){
							printf("Vui long nhap chuc vu khong co so ! \n");
						}else{
							inputToName((*empPtr)[currentIndex + i].position, size);
							break;
						}
				}while(1);
				
				
				printf("Nhap luong cua nhan vien: ");
			do{
					valudateSalary(&(*empPtr)[currentIndex + i].baseSalary);
					if((*empPtr)[currentIndex + i].baseSalary < 0){
						printf("vui long nhap lai luong phai duong: ");
					}else{
						break;
					}
			}while(1);
				(*empPtr)[currentIndex + i].workDay = 0;
				(*employee)++;
			}
		(*length) += index;
		printf("Nhap thanh cong ! \n");	
		}
}
void printEmployee(Employee *empPtr, int *length, int *employee){
	int totalEmployees = (*length);
	int choice;
	char choiceMenu;
	int empPerPage;

	// lam tron so trang ( tai vi neu lay length /EMP_PER_PAGE -> lam tron xuong                      VD 11 / 5 = 2 -> khong dung !);
	// vay nen khi ta muon tron so trang len thi phai dung (length + EMP_PER_PAGE - 1)/EMP_PER_PAGE   VD (11 + 5 -1) / 5 = 3 -> dung !);
	if((*length) == 0){
		printf("\t\t\t===================================\n");
		printf("\t\t\t>>>>>>>>> Danh sach trong <<<<<<<<<\n");
		printf("\t\t\tVui long nhap thong tin nhan vien !\n");
		printf("\t\t\t===================================\n");
	}else{
		printf("Nhap so luong nhan vien hien len trong danh sach: ");
		valudateChoice(&empPerPage);
		int totalPage = ((*length) + empPerPage - 1) / empPerPage;
		for(int page = 0; page < totalPage; page ++){
			do{
			system("cls"); 
			printf("\n\n\n\n\n\n\n\n\n\t\t\tTong so nhan vien: %d | Tong so trang: %d\n", totalEmployees, totalPage);
			printf("\t\t\t\t\t\t      >>> Trang thu %d <<<\n", page + 1);
			int startIndex = page * empPerPage;
			int endIndex = (page + 1) * empPerPage;
			if(endIndex > totalEmployees){
				endIndex = totalEmployees;
			}
			printf("\n\t\t\t++============================DANH SACH NHAN VIEN================================++\n");
   			printf("\t\t\t|| %-10s | %-20s | %-15s | %-10s | %-10s ||\n", 
        	"MA ID", "TEN NHAN VIEN", "CHUC VU", "LUONG", "NGAY CONG");
   			 printf("\t\t\t++-------------------------------------------------------------------------------++\n");
   			for (int i = startIndex; i < endIndex; i++) {
        	   printf("\t\t\t|| %-10s | %-20s | %-15s | %-10.1lf | %03d        ||\n",
               empPtr[i].empId,
               empPtr[i].nameEmp,
               empPtr[i].position,
               empPtr[i].baseSalary,
               empPtr[i].workDay);
    		}
    		printf("\t\t\t++-------------------------------------------------------------------------------++\n");
    		printf("\t\t\t++===============================================================================++\n");
    		printf("\t\t\t||    q. tro ve trang truoc    |        w. Thoat         |      e. Trang tiep    ||\n");
    		printf("\t\t\t++===============================================================================++\n");
    		printf("\t\t\tVui long nhap lua chon cua ban: ");
    			scanf("%c",&choiceMenu);
    			while(getchar() != '\n');
    			switch (choiceMenu){
    				case 'c' : case 'C' : 
    					if(page > 1){
    						(page)--;
						}else{
							printf("\t\t\tKhong co trang truoc ! \n");
						}
						break;
					case 'w' : case  'W' :
							return;
					case 'e' : case 'E' :
						if (page < totalPage -1){
							page++;
						}
						else{
							printf("\t\t\tDay la trang cuoi cung ! \n");
						}
						break;
    				}
    			}while(1);
		}
	}
}
void updateEmployee(Employee *empPtr, int *length){
	char findID[20];
	int size, exist;
	int temp;
	int choice;
	// mang tim kiem 
	Employee listFind[20];
	int insideIndex = 0;
	int targetIndex;
	char findNewID[20];
	char newPosition[16];
	double newBaseSalary;
	// mang tim kiem
	if((*length) == 0){
		printf("\t\t\t>>> Khong co nhan vien de Cap nhap ! <<<\n");
	}else{
	do{
		getString(findID, 21,"Vui long nhap ID ma ban can Cap nhap (Ma ID chi duoc dai it nhat 10 ky tu VD:B25DT01)"  );
		size = (int)strlen(findID);
		if(size > 10){
			printf("Ma ID khong Hop Le !\nVui long nhap lai:  ");
		}
	}while(size > 10);
	insideIndex = 0;
	for(int i = 0; i  < *length; i++){
		if(strstr(empPtr[i].empId, findID) != NULL){
			listFind[insideIndex] = empPtr[i];
			temp = i;
			insideIndex++;
		}
	}
// in ra cac nhan vien da duoc tra cuu 
	printf("\nDanh sach cac nhan vien ban da tra: \n");
	for(int l = 0; l < insideIndex; l++){
			printLine();
			displayEmployee(&empPtr[l]);
			printLine();
	}
// in ra cac nhan vien da duoc tra cuu	
// lua chon ma nhan vien CHINH XAC ma can duoc cap nhap !
	if(insideIndex == 0){
		//truong hop neu mang danh sach tra khong co:
		printf(">>> Khong co <<< \n");
		return;
	}else if(insideIndex == 1){
		// neu danh sach chi co mot nhan vien duy nhat
			do{
				getString(newPosition, 16, "Vui long nhap vi tri moi cua ban");
				size = strlen(newPosition);
					if(isDigit(newPosition, size)){
						printf("Vui long nhap chuc vu khong co so ! \n");
					}else{
						break;
					}
			}while(1);
			
			
			printf("Vui long nhap luong moi: ");
			do{
				valudateSalary(&newBaseSalary);
				if(newBaseSalary == 0 || newBaseSalary < 0){
					printf("Luong khong duoc bo trong !\nVui long nhap lai luong moi: ");
				}
			}while(newBaseSalary == 0 || newBaseSalary < 0);
			
			choice = forSure(choice, "Cap nhap");
			if (choice == 1 ){
				strcpy(empPtr[temp].position,newPosition);
				empPtr[temp].baseSalary = newBaseSalary;
				printf("Cap nhap thanh cong ! \n");
			}else if(choice == 0){
				printf("Cap nhap khong thanh cong ! \n");
			}
			
	}else{
		// neu nhieu hon 1 nhan vien 
			do{
				getString(findNewID, 21,"Vui long nhap ID CHINH XAC ma ban can cap nhap"  );
				size = (int)strlen(findNewID);
				if(size > 10){
					printf("Ma ID khong Hop Le !\nVui long nhap lai:  ");
				}
			}while(size > 10);

			targetIndex = - 1;
			for(int i = 0; i  < *length; i++){
				if(strcmp(empPtr[i].empId, findNewID) == 0){
						targetIndex = i;
						break;
				}
			}
			if(targetIndex != -1){
				do{
				getString(newPosition, 16, "Vui long nhap vi tri moi cua ban");
				size = strlen(newPosition);
					if(isDigit(newPosition, size)){
						printf("Vui long nhap chuc vu khong co so ! \n");
					}else{
						inputToName(newPosition, size);
						break;
					}
				}while(1);
				
				printf("Vui long nhap luong moi: ");
				do{
					valudateSalary(&newBaseSalary);
					if(newBaseSalary == 0 || newBaseSalary < 0){
						printf("Luong khong duoc bo trong !\nVui long nhap lai luong moi: ");
					}
				}while(newBaseSalary == 0 || newBaseSalary < 0);
				
				choice = forSure(choice, "Cap nhap"); // co muon cap nhap hay khong !
				if (choice == 1 ){
					strcpy(empPtr[targetIndex].position,newPosition);
					empPtr[targetIndex].baseSalary = newBaseSalary;
					printf("Cap nhap thanh cong ! \n"); // thong bao cap nhap thanh cong
				}else if(choice == 0){
					printf("Cap nhap khong thanh cong ! \n"); // thong bao fail
				}
			}else{
				printf("Ma ID %s khong tim thay trong danh sach ! \n", findNewID); // kiem tra neu nguoi dung nhap khong thay ma
			}
		}
	}
	
}
void DismissEmployee(Employee *empPtr, int *length, int *employee){
	char findID[21];
	int size;
	int temp;
	int choice;
	// mang tim kiem 
	Employee listFind[20];
	int insideIndex = 0;
	int targetIndex;
	char findNewID[21];
	// mang tim kiem
	if((*length) == 0){
		printf(">>> Khong co nhan vien de Xoa ! \n");
	}else{
	do{
		getString(findID, 21,"Vui long nhap ID ma ban can xoa (Ma ID chi duoc dai it nhat 10 ky tu VD:B25DT01) " );
		size = (int)strlen(findID);
		if(size > 10){
			printf("Ma ID khong Hop Le !\nVui long nhap lai:  ");
		}
	}while(size > 10); 
	insideIndex = 0;
	for(int i = 0; i  < *length; i++){
		if(strstr(empPtr[i].empId, findID) != NULL){
			listFind[insideIndex] = empPtr[i];
			insideIndex++;
		}
	}
// in ra cac nhan vien da duoc tra cuu 
	printf("\nDanh sach cac nhan vien ban da tra: \n");
	for(int l = 0; l < insideIndex; l++){
			printLine();
			displayEmployee(&empPtr[l]);
			printLine();
	}
// in ra cac nhan vien da duoc tra cuu	
// lua chon ma nhan vien CHINH XAC ma can duoc xoa !
	if(insideIndex == 0){
		printf(">>> Khong co <<< \n");
		return;
	}else if(insideIndex == 1){
			strcpy(findNewID, listFind[0].empId);
	}else{
			do{
				getString(findNewID, 21,"Vui long nhap ID CHINH XAC ma ban can xoa (Ma ID chi duoc dai nhieu nhat 10 ky tu)"  );
				size = (int)strlen(findNewID);
				if(size > 10){
					printf("Ma ID khong Hop Le !\nVui long nhap lai:  ");
				}
			}while(size > 10);
		
			}
			choice = forSure(choice, "Xoa");
			if(choice){
				targetIndex = -1;
				for(int i = 0; i  < *length; i++){
					if(strcmp(empPtr[i].empId, findNewID) == 0){
							targetIndex = i;
							break;
					}
				}
				if(targetIndex != -1){
					for(int j =targetIndex; j < (*length) -1 ;j++){
						empPtr[j] = empPtr[j+1];
					}
					(*length)--;
					(*employee)--;
					printf("Xoa thanh cong ! \n");
				}else{
					printf("Ma ID %s khong tim thay trong danh sach ! \n", findNewID);
				}
			}else{
				printf("Xoa khong thanh cong !");
			}	
	}
	
}
void findEmployeeByName(Employee *empPtr, int *length){
	char findName[50];
	int size;
	if((*length) == 0){
		printf(">>> Khong co nhan vien can tim <<< \n");
	}else{
	do{
		getString(findName, 51,"Vui long nhap ten can tim cua ban" );
		size = strlen(findName);
		if (isDigit (findName, size )){
			printf("Vui Long Nhap Ten Ma khong co so !\nVui long nhap lai: ");
			
		}else{
			inputToName(findName, size);
			break;
		}
	}while(1);
	printf("Danh sach cua nhanh vien \n");
	for(int i = 0; i < *length; i++){
		if(strstr(empPtr[i].nameEmp, findName) != NULL){
			printf("+--------------------------------------------------------------------------------------------------------------+\n");
			printf("|Ma ID: %-10s |Ten: %-20s |Chuc vu: %-10s |Luong: %-15.1lf     |Ngay cong: %03d |\n"
			,empPtr[i].empId,
			empPtr[i].nameEmp,
			empPtr[i].position, 
			empPtr[i].baseSalary,
			empPtr[i].workDay);
			printf("+--------------------------------------------------------------------------------------------------------------+\n");
			}
		}
	}		
}
void sortBySalary(Employee *empPtr, int *length, int*sortchoice, int *employee){
	Employee temp;
	if((*length) == 0){
		printf("Danh sach rong ! Vui long them danh sach truoc khi sap xep ! \n");
	}else if ((*length) == 1){
		printf("Danh sach chi co 1 nhan vien ! Khong can phai sap xep ! \n");
	}else{
		do{
			printf("\t\t\t++========MENU SAP XEP========++\n");
			printf("\t\t\t||%-28s||\n", "1. Sap xep tang dan");
			printf("\t\t\t||%-28s||\n", "2. Sap xep giam dan");
			printf("\t\t\t||%-28s||\n", "3. Quay lai");
			printf("\t\t\t++============================++\n");
			printf("----Lua chon cua ban: ");
			valudateChoice(&(*sortchoice));
			switch (*sortchoice){
				case 1 :{
					// insesrtion sort
					for(int i = 1; i < *length; i++){
						temp = empPtr[i];
						int j = i - 1;
						while ( j >= 0 && empPtr[j].baseSalary > temp.baseSalary){
							empPtr[j+1] = empPtr[j];
							j--;
						} 
						empPtr[j+1] = temp;
					}
					printEmployee(empPtr, length,employee);
					printf("Sap xep thanh cong !\n");
					break;
				}
				case 2 :{
					for(int i = 1; i < *length; i++){
						temp = empPtr[i];
						int j = i - 1;
						while ( j >= 0 && empPtr[j].baseSalary < temp.baseSalary){
							empPtr[j+1] = empPtr[j];
							j--;
						} 
						empPtr[j+1] = temp;
					}
					printEmployee(empPtr, length,employee);
					printf("Sap xep thanh cong !\n");
					break;
				}
				case 3 :
					printf("Cam on vi da den !");
					return;
				default :
					printf("Vui long chi chon tu 1 -> 3: ");
			}
		}while(1);
	}

}
void attendanceForTheDay(Employee *empPtr, TimeSheet *empTimePtr,int *length,int *timeSheetLength){
	char findId[20]; 
	char newDate[20];
	int newIndex;
	int currentLog = (*timeSheetLength);
	int timeSheetIndex;
	// mang tim kiem 
	Employee listFind[20];
	int insideIndex = 0; 
	int targetIndex = -1;
	char finalId[20];
	// mang tim kiem
	if((*length) == 0){
		printf("\t\t\t>>> Khong co nhan vien de Cham Cong ! <<<\n");
		return;
	}
	if ((*timeSheetLength) > MAX_TIME_EMP){
		printf("Danh sach cham cong da day ! Khong the them ! \n");
		return;
	}	
		do{
			getString(newDate, 21, "Vui long nhap ngay/thang/nam cham cong (DD/MM/YYYY)");
			if(validateDate(newDate)){
				break;
			}else{
				printf("Ngay/thang/nam khong hop le !\n Vui long nhap lai ! \n ");
			}
		}while(1);
		
		
		getString(findId, 21, "Vui long nhap ma nhan vien can duoc cham cong");
		insideIndex = 0;
	for(int i = 0; i  < *length; i++){
		if(strstr(empPtr[i].empId, findId) != NULL){
			listFind[insideIndex] = empPtr[i];
			targetIndex = i;
			insideIndex++;
		}
	}
// in ra cac nhan vien da duoc tra cuu 
	printf("\nDanh sach cac nhan vien ban da tra: \n");
	for(int l = 0; l < insideIndex; l++){
			printf("+------------------------------------------------------------------+\n");
			printf("|Ma ID: %-10s |Ten: %-20s |Chuc vu: %-10s |\n"
			,listFind[l].empId,
			listFind[l].nameEmp,
			listFind[l].position);
			printf("+------------------------------------------------------------------+\n");
	}
// in ra cac nhan vien da duoc tra cuu	

	if(insideIndex == 0){
		//truong hop neu mang danh sach tra khong co:
		printf(">>> Khong co <<< \n");
		return;
	}else if(insideIndex == 1){
		// neu danh sach chi co mot nhan vien duy nhat
		strcpy(finalId, empPtr[targetIndex].empId);

	}else{
		// neu nhieu hon 1 nhan vien 
		getString(finalId, 21, "Vui long nhap ID CHINH XAC ma ban can cap nhap" );
		targetIndex = - 1;
		for(int i = 0; i  < *length; i++){
			if(strcmp(empPtr[i].empId, finalId) == 0){
					targetIndex = i;
					break;
			}
		}
		if(targetIndex == -1){
			printf("Khong tim thay ma %s trong danh sach !\n");
			return ;
		}
		strcpy(finalId, empPtr[targetIndex].empId);	
	}
		timeSheetIndex = -1;
		for(int j = 0 ; j  < (*timeSheetLength); j++){
			if(strcmp(empTimePtr[j].empId,finalId) == 0 && strcmp(empTimePtr[j].date,newDate) == 0){
				timeSheetIndex = j;
				break;
			}
		}
		if(timeSheetIndex != -1){
			printf("Nhan vien %s da cham cong vao ngay %s roi", empPtr[timeSheetIndex].empId, newDate);
		}else{
			newIndex = (*timeSheetLength);
			strcpy(empTimePtr[newIndex].status, "Di lam");
			strcpy(empTimePtr[newIndex].date,newDate);
			sprintf(empTimePtr[newIndex].logId, "%d", 100 + currentLog);
			strcpy(empTimePtr[newIndex].empId,empPtr[targetIndex].empId);
			empPtr[targetIndex].workDay += 1;
			(*timeSheetLength) ++;
			printf("Cham cong ngay %2s cho nhan vien %s thanh cong ! \n", newDate, empPtr[targetIndex].empId);
		}
}
void viewTheWorkSchedule(Employee *empPtr, TimeSheet *empTimePtr,int *length,int *timeSheetLength){
	char findId[20];
	int find;
	if((*length) == 0){
		printf(">>> Khong co nhan vien de tra ! <<< \n");
	}else{
		getString(findId, 21, "Vui long nhap ma nhan vien cua ban");
		find = 0;
		for(int i= 0;i < *length; i++){
			if (strcmp(empPtr[i].empId, findId) == 0){
				find = 1;
				break;
			}
		}
		if(find){
			printf("\n\n\n\t\t\tMa nhan vien: %s \n", findId);
				printf("\n\t\t\t++==============DANH SACH CHAM CONG==================++\n");
	   			printf("\t\t\t|| %-10s | %-20s | %-13s ||\n", 
	        			"ID LOG", "NGAY CHAM", "TRANG THAI");
	   			 printf("\t\t\t++---------------------------------------------------++\n");
				for(int j = 0 ; j < *timeSheetLength; j++){
					if(strcmp(empTimePtr[j].empId, findId) == 0){
					   printf("\t\t\t|| %-10s | %-20s | %-13s ||\n",
		               empTimePtr[j].logId,
		               empTimePtr[j].date,
		               empTimePtr[j].status);
					}
	    		}
	    		printf("\t\t\t++===================================================++\n");
		}else{
			printf("Khong tim thay ma id trong danh sach ! \n");
		}
	}
}
	

// ket thuc !!!
int main(){
	int size = 0;
	int sizeTime = 0;
	int choice;
	int recordAndRecruitmentManagementChoice; // quan ly ho so
	int humanResourceManagementChoice; // quan ly nhan su
	int dataManagementAndReportingChoice; // quan ly du lieu va bao cao
	int employees = 0;
//	Employee listemp[100];
	Employee *empList = (Employee*)malloc(size * sizeof(Employee));
	TimeSheet *empTime = (TimeSheet*)malloc(MAX_TIME_EMP * sizeof(TimeSheet));
	if(empList == NULL){
		printf("Loi Cap phat ! \n");
	}else{
		printf("Cap phat thanh cong ! \n");
	}
	do{
		system("cls"); // xoa tat ca man hinh tren man hinh consol
		printMenu();
		valudateChoice(&choice);
		switch (choice){
			case 1 :{
				do{
					system("cls"); 
					managementList();
					valudateChoice(&choice);
					switch (choice){
						case 1 :
							do{
								profileManagementList();
								valudateChoice(&recordAndRecruitmentManagementChoice);
								switch (recordAndRecruitmentManagementChoice){
									case 1 :{
										insertEmployee(&empList, &size, &employees);
										break;
									}
									case 2 : {
										updateEmployee(empList, &size);
										break;
									}
									case 3 : {
										printf("Thoat thanh cong\n");
										break;
									}
									default :
										printf("Vui long chi chon tu 1 -> 3: ");
								}
							}while(recordAndRecruitmentManagementChoice != 3);
							break;
						 
						case 2 :
							do{
								civilAdministrationList();
								valudateChoice(&humanResourceManagementChoice);
								switch (humanResourceManagementChoice){
									case 1 :{
										DismissEmployee(empList, &size, &employees);
										break;
									}
									case 2 : {
										printf("Thoat \n");
										break;
									}
									default :
										printf("Vui long chi chon tu 1 -> 2: ");
								}
							}while(humanResourceManagementChoice != 2);
							break;
						
						case 3 :
							do{
								dataManagementAndReportingList();
								valudateChoice(&dataManagementAndReportingChoice);
								switch (dataManagementAndReportingChoice){
									case 1 :{
										printEmployee(empList, &size, &employees);
										break;
									}
									case 2 : {
										findEmployeeByName(empList, &size);
										break;
									}
									case 3 : {
										sortBySalary(empList, &size, &choice, &employees);
										break;
									}
									case 4 : {
										printf("Thoat thanh cong !\n");
										break;
									}
									default :
										printf("Vui long chi chon tu (1 -> 4): ");
								}
							}while(dataManagementAndReportingChoice != 4);
							break;
						case 4 :
							printf("Thoat thanh cong !\n");
							break;
						default :
							printf("Vui long chon chi tu 1-> 4: ");
					}
				}while (choice != 4);
				break;
			}
			case 2 :
				do{
					employeeList();
					valudateChoice(&choice);
					switch (choice){
						case 1 : 
							attendanceForTheDay(empList, empTime, &size, &sizeTime);
							break;
						case 2 :{
							viewTheWorkSchedule(empList, empTime, &size, &sizeTime);
							break;
						}
						case 3 :
							printf("Thoat thanh cong ! \n");
							break;
						default :
							printf("Vui long chon 1-> 2: ");
					}
				}while(choice != 3);
				break;
			
			case 3 :
				printf("Cam on vi da xu dung chuong trinh !\n");
				exit(0);
				break;
				
			default :{
				printf(" Lua chon cua ban ko chinh xac ! vui long nhap lai: ");
			}
		}
	}while(1);
	return 0;
}
