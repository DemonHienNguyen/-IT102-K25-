#include <stdio.h> // dung cho cac ham nhap -> xuat: printf(), fgets, scanf.  
#include <stdlib.h> // dung ham cho exit(0), system("cls").
#include <string.h>	// dung ham cho strtol, strtod, sscanf().
#include <ctype.h> // ham dung cho isspace , isalpha, isdigit.
#include <unistd.h> // ham dung cho:  sleep(int).

#define EMP_PER_PAGE 5 // so luong nhan vien toi da moi trang - > co the thay doi lai duoc
#define MAX_TIME_EMP 100 // so luong thoi gian Record toi da : 100 phan tu

							// BANG MAU
							/* ===========================
							   RESET
							   =========================== */
							#define RESET   "\033[0m"
							
							/* ===========================
							   BASIC 16 COLORS (FOREGROUND)
							   =========================== */
							#define BLACK         "\033[30m"
							#define RED           "\033[31m"
							#define GREEN         "\033[32m"
							#define YELLOW        "\033[33m"
							#define BLUE          "\033[34m"
							#define MAGENTA       "\033[35m"
							#define CYAN          "\033[36m"
							#define WHITE         "\033[37m"
							
							#define BRIGHT_BLACK   "\033[90m"
							#define BRIGHT_RED     "\033[91m"
							#define BRIGHT_GREEN   "\033[92m"
							#define BRIGHT_YELLOW  "\033[93m"
							#define BRIGHT_BLUE    "\033[94m"
							#define BRIGHT_MAGENTA "\033[95m"
							#define BRIGHT_CYAN    "\033[96m"
							#define BRIGHT_WHITE   "\033[97m"
							// BANG MAU
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

// ham bi bo trong
void removeBuffer();
void removeNewLine(char *a);
void getToUpper(char *b, int size);
// ham bi bo trong


// ham phu tro
int hasLeadingOrTrailingSpace(char *s); // kiem tra neu co cach o truoc va sau hay khong ?
void trimSpace(char *str);  // ham xoa dau cach ca truoc va sau
int onlySpace(char *str);	// su dung ham void trimSpace neu nhu co dau cach va tra gia tri 0 / 1 
int isDigitAndSpecial(char *b, int size);
void inputToName(char *a, int size);  // nguyen van a  -> Nguyen Van A
int forSure(int choice, char *something); 
// ham phu tro

// ham dac biet
void getString(char *c, int max, char *something);
int findCorrectID(Employee *empPtr, int *length);
int findSomethingSameSame(Employee *empPtr, int *length, int *inSide, int *targetIndexPtr);
void valudateChoice(int *choicePtr);  //   1 - 1abc
void valudateSalary(double *choicePtr);  
int validateDate(char *datePtr);  // Ngay/Thang/Nam
void validateCharractor(char *choiceMenuPtr); // ký tu 
// ham dac biet

// ham in an
void printLine();
void displayEmployee(Employee *emp);
void printMenu();
void managementList();
void profileManagementList();
void dataManagementAndReportingList();
void civilAdministrationList();
void employeeList();
//ham in an

// khai bao bien
void insertEmployee(Employee **empPtr, int *length, int *employee); 
void printEmployee(Employee *empPtr, int *length);
void updateEmployee(Employee *empPtr, int *length);
void DismissEmployee(Employee *empPtr, int *length, int *employee);
void findEmployeeByName(Employee *empPtr, int *length);
void sortBySalary(Employee *empPtr, int *length, int*sortchoice);
void attendanceForTheDay(Employee *empPtr, TimeSheet *empTimePtr,int *length , int *timeSheetLength);
void viewTheWorkSchedule(Employee *empPtr, TimeSheet *empTimePtr,int *length,int *timeSheetLength);
//khai bao bien
 
// ket thuc !!!
int main(){
	int size = 20; // kich co cung nhu so luong nhan vien luc dau luon !
	int logCount  = 0;  // kich cu cua Record -> se tang khi nhan vien cham cong
	int choice; // lua chon khi moi vao Menu
	int recordAndRecruitmentManagementChoice; // lua chon quan ly ho so
	int humanResourceManagementChoice; //Lua chon quan ly nhan su
	int dataManagementAndReportingChoice; //Lua chon quan ly du lieu va bao cao
	int employees = 20; // so luong nhan vien -> tang khi them nhan vien va giam khi sa thai nhan vien
	Employee *empList = (Employee*)malloc(size * sizeof(Employee)); // cap phat bo nho cho luon 20 nhan vien luc dau
	TimeSheet *empTime = (TimeSheet*)malloc(MAX_TIME_EMP * sizeof(TimeSheet)); // cap phat cho Record TimeSheet 100 phan tu
	if(empList == NULL){ 
		printf("Loi Cap phat ! \n");
	}else{
		printf("Cap phat thanh cong ! \n");
	}
	// cho truoc 20 phan tu !!
	empList[0] =  (Employee){"NV001","Song tong empity", "Quan Ly", 1600};
	empList[1] =  (Employee){"NV002","SooBin Sam Son", "Quan Ly", 1000};
	empList[2] =  (Employee){"NV003","Ngo Gia Tu", "Quan Ly", 1700};
	empList[3] =  (Employee){"NV004","Sach Binh", "Quan Ly", 1700};
	empList[4] =  (Employee){"NV005","Tan Thuy Hoang", "Quan Ly", 1400};
	empList[5] =  (Employee){"NV006","Ca Ric", "Nhan Vien", 1000};
	empList[6] =  (Employee){"NV007","Bell Gate", "Nhan Vien", 1100};
	empList[7] =  (Employee){"NV008","Quy Buu Bach Khoa", "Nhan Vien", 1200};
	empList[8] =  (Employee){"NV009","Binh Xang To", "Nhan Vien", 1400};
	empList[9] =  (Employee){"NV010","Putin", "Nhan Vien", 1800};
	empList[10] =  (Employee){"NV011","Ngan Chin Tam", "Nhan Vien", 1100};
	empList[11] =  (Employee){"NV012","Hang Du Muc", "Nhan Vien", 1200};
	empList[12] =  (Employee){"NV013","Quang Linh Vlogs", "Nhan Vien", 1800};
	empList[13] =  (Employee){"NV014","Donal Trump", "Nhan Vien", 1800};
	empList[14] =  (Employee){"NV015","Chu Be Te liet", "Nhan Vien", 1600};
	empList[15] =  (Employee){"NV016","Vi Khuan", "Thuc Tap Sinh", 1200};
	empList[16] =  (Employee){"NV017","Tra Bong", "Thuc tap sinh", 1300};
	empList[17] =  (Employee){"NV018","Cau Banh", "Thuc tap sinh", 1900};
	empList[18] =  (Employee){"NV019","Adolf Hitler", "Thuc tap sinh", 1000};
	empList[19] =  (Employee){"NV020","Nguyen Minh Hien", "Chu Tich", 10000000};
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
										printf("%s\t\t\t>>> Thoat thanh cong !\n%s", GREEN, RESET);
										sleep(1);
										break;
									}
									default :
										printf("%sLua chon cua ban ko chinh xac ! vui long nhap lai ! %s", RED, RESET);
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
										printf("%s\t\t\t>>> hoat thanh cong\n%s", GREEN, RESET);
										sleep(1);
										break;
									}
									default :
										printf("%sLua chon cua ban ko chinh xac ! vui long nhap lai ! %s", RED, RESET);
								}
							}while(humanResourceManagementChoice != 2);
							break;
						
						case 3 :
							do{
								dataManagementAndReportingList();
								valudateChoice(&dataManagementAndReportingChoice);
								switch (dataManagementAndReportingChoice){
									case 1 :{
										printEmployee(empList, &size);
										break;
									}
									case 2 : {
										findEmployeeByName(empList, &size);
										break;
									}
									case 3 : {
										sortBySalary(empList, &size, &choice);
										break;
									}
									case 4 : {
										printf("%s\t\t\t>>> Thoat thanh cong !\n%s", GREEN, RESET);
										sleep(1);
										break;
									}
									default :
										printf("%sLua chon cua ban ko chinh xac ! vui long nhap lai ! %s",RED, RESET);
								}
							}while(dataManagementAndReportingChoice != 4);
							break;
						case 4 :
							printf("%s\t\t\t>>> Thoat thanh cong !\n%s", GREEN, RESET);
							sleep(1);
							break;
						default :
							printf("%sLua chon cua ban ko chinh xac ! vui long nhap lai !%s", RED, RESET);
							sleep(1);
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
							attendanceForTheDay(empList, empTime, &size, &logCount );
							break;
						case 2 :{
							viewTheWorkSchedule(empList, empTime, &size, &logCount );
							break;
						}
						case 3 :
							printf("%s\t\t\t>>> Thoat thanh cong ! \n%s", GREEN, RESET);
							sleep(1);
							break;
						default :
							printf("%sLua chon cua ban ko chinh xac ! vui long nhap lai ! %s", RED, RESET);
					}
				}while(choice != 3);
				break;
			
			case 3 :
				free(empList);
				// mau me hoa la he :D
				printf("\t\t\t%s>>> Cam on vi da xu dung chuong trinh !!!%s", RED, RESET);
				sleep(1);
				system("cls");
				printf("%s\t\t\t\tDDDDDD%s   %sEEEEEE%s  %sMM   MM%s   %sOOOO%s   %sNN   NN%s\n", RED, RESET,YELLOW, RESET, GREEN, RESET, BRIGHT_MAGENTA, RESET,BRIGHT_BLUE, RESET );
				printf("%s\t\t\t\tDD   DD%s  %sEE%s      %sMMM MMM%s  %sOO  OO%s  %sNNN  NN%s\n",RED, RESET,YELLOW, RESET, GREEN, RESET, BRIGHT_MAGENTA, RESET,BRIGHT_BLUE, RESET );
				printf("%s\t\t\t\tDD   DD%s  %sEE%s      %sMMM MMM%s  %sOO  OO%s  %sNNN  NN%s\n",RED, RESET,YELLOW, RESET, GREEN, RESET, BRIGHT_MAGENTA, RESET,BRIGHT_BLUE, RESET );
				printf("%s\t\t\t\tDD   DD%s  %sEEEEE%s   %sMM M MM%s  %sOO  OO%s  %sNN N NN%s\n",RED, RESET,YELLOW, RESET, GREEN, RESET, BRIGHT_MAGENTA, RESET,BRIGHT_BLUE, RESET );
				printf("%s\t\t\t\tDD   DD%s  %sEE%s      %sMM   MM%s  %sOO  OO%s  %sNN  NNN%s\n",RED, RESET,YELLOW, RESET, GREEN, RESET, BRIGHT_MAGENTA, RESET,BRIGHT_BLUE, RESET );
				printf("%s\t\t\t\tDDDDDD%s   %sEEEEEE%s  %sMM   MM%s   %sOOOO%s   %sNN   NN%s\n", RED, RESET,YELLOW, RESET, GREEN, RESET, BRIGHT_MAGENTA, RESET,BRIGHT_BLUE, RESET );
				exit(0);
				break;
				
			default :{
				printf("%sLua chon cua ban ko chinh xac ! vui long nhap lai !%s", RED, RESET);
				sleep(1);
			}
		}
	}while(1);
	return 0;
}

// BAT DAU !!!
// ----- THUC THI HAM ----
			// Ham Bo Tro
void removeBuffer(){
	 int c;
	 while((c = getchar()) != '\n' && c != EOF);
}

void removeNewLine(char *a){
	 size_t len = strlen(a);
	 a[len -1] = '\0';
}

// ham bien ky tu thanh in hoa het 
void getToUpper(char *b, int size){
	for(int i = 0; i < size; i++){
		b[i] = toupper(b[i]);
	}
}
// Xoa het ky tu cach va Dich chuyen ky tu len truoc
void trimSpace(char *str) {
    int start = 0;
    int end = strlen(str) - 1;
    while (isspace(str[start])){
    	start++;
	}
    while (end >= start && isspace(str[end])){
    	end--;
	} 
    int j = 0;
    for (int i = start; i <= end; i++) {
        str[j++] = str[i];
    }
    str[j] = '\0';
}

// ham xac dinh co dau cach
int onlySpace(char *str){
	char temp[100];
	strcpy(temp, str);
	trimSpace(temp);
	if(strlen(temp) == 0){
		return 1;
	}
	return 0;
	
}
// kiem tra dau va cuoi co dau  ' ' hay khong  ! 
int hasLeadingOrTrailingSpace(char *s) {
    int len = strlen(s);
    if (len == 0){
    	return 0;
	}
    return isspace(s[0]) || 
           isspace(s[len - 1]);
}
// ham lay Chuoi Ky tu va Validate o ben trong
void getString(char *c, int max, char *something){
	int sizeOfString;
	int sizeIndex;
	int inputIsTruncated;
	do{
		
		printf("%s%s (max %d ky tu): %s",BRIGHT_YELLOW ,something, max - 1, RESET);
		printf("%s", GREEN);
		fgets(c, max, stdin);
		printf("%s", RESET);
		
		sizeIndex = strcspn(c, "\n");
		// abc\n   abcd   efh\n
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
			printf("%sERROR !! Nhap da qua muc chi dinh !\n%s", RED, RESET);
			continue;
		}
		if(sizeOfString == 0 ){
			printf("%sERROR !!\nVui long nhap lai! \n%s", RED, RESET);
		}else if(onlySpace(c)){
			printf("%sERROR !! Khong duoc chua dau cach va khong duoc bo trong !\n%s", RED, RESET);
		}else if(hasLeadingOrTrailingSpace(c)){
			printf("%sERROR !!Co dau cach ! vui long nhap lai ! %s\n", RED, RESET);
		}else{
			break;
		}
	}while(1);
}
// tim gia tri ID chinh xac va Luu lai bien cua Index
int findCorrectID(Employee *empPtr, int *length){
	int targetIndex;
	char findNewID[20];
	do{
		getString(findNewID, 21,"Vui long nhap ID CHINH XAC ma ban can cap nhap"  );
	}while((int)strlen(findNewID) > 20);
			targetIndex = - 1;
			for(int i = 0; i  < *length; i++){
				if(strcmp(empPtr[i].empId, findNewID) == 0){
						targetIndex = i;
						break;
				}
			}
	return targetIndex;
}
// ham xac dinh trong co ky tu so hay ky tu dac biet nao khong
int isDigitAndSpecial(char *b, int size){
	for(int i = 0; i < size; i++){
		if(isdigit(b[i])){
			return 1;
		}else if(isalpha(b[i]) || b[i] == ' '){
			continue;
		}else{
			return 1;
		}
	}
	return 0;
}
				// Ham Bo Tro



				// Ham Dac Biet
// ham bien doi ky tu dau thanh in hoa moi chu cai
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
// ham chon lua chon va chon so + Validate het
void valudateChoice(int *choicePtr){
	char input[100];
	int validate = 0;
	do{
		printf("%s", BRIGHT_GREEN);
		fgets(input, 100, stdin);
		printf("%s", RESET);
		input[strcspn(input, "\n")]= '\0';
		if(strlen(input) == 0){
			printf("%sERROR !! khong duoc de trong ! \nVui long nhap lai: %s", RED, RESET);
			continue;
		}
			if(hasLeadingOrTrailingSpace(input)){
				printf("%sERROR !! khong duoc co dau cach ! \nVui long nhap lai: %s", RED, RESET);
				continue;
			}
		char *endPtr;
		long temp = strtol(input, &endPtr,10);
		// cu phap strtol(bien can bien thanh kieu long, con tro khi chay chuoi (Aka: duyet phan tu ), He co so)
		if(*endPtr == '\0' && input[0] != '\0'){
			*choicePtr = (int)temp;
			 validate = 1;
		}else{
			printf("%sERROR !! Vui long chi nhap so ! \nVui long nhap lai: %s",RED, RESET);
		}
	}while(!validate);
}
// ham nhap so thap phan va Validate
void valudateSalary(double *choicePtr){
	char input[100];
	int validate = 0;
	do{
		printf("%s", GREEN);
		fgets(input, 100, stdin);
		printf("%s", RESET);
		input[strcspn(input, "\n")]= '\0';
		if(strlen(input) == 0){
			printf("%sDau vao khong duoc de trong ! \nVui long nhap lai: %s",RED, RESET);
			continue;
		}
		if(hasLeadingOrTrailingSpace(input)){
			printf("%sERROR !! khong duoc co dau cach!!! \nVui long nhap lai: %s", RED, RESET);
			continue;
		}
		char *endPtr;
		double temp = strtod(input, &endPtr);
		// cu phap strtol(bien can bien thanh kieu long, con tro khi chay chuoi (Aka: duyet phan tu ), He co so)
		if(*endPtr == '\0' && input[0] != '\0'){
			*choicePtr = temp;
			 validate = 1;
		}else{
			printf("%sVui long chi nhap so thap phan, khong duoc co chu ! \nVui long nhap lai: %s",RED, RESET);
		}
	}while(!validate);
}
// ham chac chan chon nay khong  
int forSure(int choice, char *something){
	printf("%sCANH CAO ! Ban co chac %s hay khong\n(1: Yes|0: No): %s",RED,something, RESET);
	do{
		valudateChoice(&choice);
		if( choice > 1 || choice < 0){
			printf("%sVui long chi chon 0 Hoac 1: %s", RED, RESET);
		}
	}while( choice > 1 || choice < 0);
	return choice;
}
// ham nhap ngay thang nam va Validate het
int validateDate(char *datePtr){
	int day, month, year;
	int is_leap;
	//                 day/month/year
	if(sscanf(datePtr, "%d/%d/%d", &day, &month, &year ) != 3){
		return 0;
	}
//	30/02/2025
	if(year > 2100 || year < 1900){
		printf("%sVui long chon nam hop le (1900 => 2100)! %s\n", RED, RESET);
		return 0;
	}	
	if(month < 1 || month > 12 ||day < 1 || day > 31){
		return 0;
	}else{
		is_leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
		int days_in_month[] = {0, 31, 28 + is_leap, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if(day > days_in_month[month]){
			return 0;
		}
	}
	return 1;

}
// Validate khi nhap chu cai o phan printEmployyee !
void validateCharractor(char *choiceMenuPtr){
	char input[100];
do{
	printf("\t\t\tVui long nhap lua chon cua ban: ");
    printf("%s", GREEN);
    fgets(input, sizeof(input), stdin);
    printf("%s", RESET);
    removeNewLine(input);
    
    if(strlen(input) == 0){
        printf("%sERROR !! Khong duoc de trong !%s\n", RED, RESET);
        continue;
    }

    if(strlen(input) != 1){
        printf("%sERROR !! Vui long chi nhap 1 ky tu !%s\n", RED, RESET);
        continue;
    }

    (*choiceMenuPtr) = input[0];

    if(strchr("qQwWeEgGsS", *choiceMenuPtr)){ // tra ve vi tri con tro duoc tim thay -> True, neu khong tim thay = NULL -> False
        break; 
    }else {
        printf("%sERROR !! Lua chon khong hop le!%s\n", RED, RESET);
    }
}while(1);
}
		// Ham Dac Biet



		// Ham In An
// ham in ra ke vach
void printLine(){
	printf("%s+-------------------------------------------------------------------------------------------------------------------+%s\n",BRIGHT_BLUE, RESET);
}
// ham hien thi nhan vien trong do 
void displayEmployee(Employee *emp) {
   			printf("\t\t\t%s++-------------------------------------------------------------------------------++%s\n",BRIGHT_BLUE, RESET);
        	   printf("\t\t\t%s||%s %-10s %s|%s %-20s %s|%s %-15s %s|%s %-10.1lf %s|%s %03d        %s||%s\n",
        	   	BRIGHT_BLUE, RESET,
                emp->empId,
                BRIGHT_BLUE, RESET,
		        emp->nameEmp,
		        BRIGHT_BLUE, RESET,
		        emp->position, 
		        BRIGHT_BLUE, RESET,
		        emp->baseSalary,
		        BRIGHT_BLUE, RESET,
		        emp->workDay,
				BRIGHT_BLUE, RESET);
}
// ham in Menu dau tien
void printMenu(){
	printf("%s\n\t\t\t\t\t++====================MENU====================++%s\n", BRIGHT_CYAN, RESET);
	printf("\t\t\t\t\t%s||%s%-44s%s||%s\n",BRIGHT_CYAN, RESET, "1. Quan ly",BRIGHT_CYAN, RESET);
	printf("\t\t\t\t\t%s||%s%-44s%s||%s\n",BRIGHT_CYAN, RESET, "2. Nhan Vien",BRIGHT_CYAN, RESET);
	printf("\t\t\t\t\t%s||%s%-44s%s||%s\n",BRIGHT_CYAN, RESET, "3. Thoat ",BRIGHT_CYAN, RESET);
	printf("\t\t\t\t\t%s++============================================++%s\n",BRIGHT_CYAN, RESET);
	printf("\t\t\t%s>>> Lua chon cua ban: %s", BRIGHT_CYAN, RESET);
}
void managementList(){ // danh sach quan ly
	printf("%s\n\t\t\t\t\t++===========MENU QUAN LY============++%s\n",BRIGHT_CYAN, RESET);
	printf("\t\t\t\t\t%s||%s%-35s%s||%s\n", BRIGHT_CYAN, RESET,"1. Quan ly ho so va tuyen dung",BRIGHT_CYAN, RESET);
	printf("\t\t\t\t\t%s||%s%-35s%s||%s\n",BRIGHT_CYAN, RESET, "2. Quan ly nhan su",BRIGHT_CYAN, RESET);
	printf("\t\t\t\t\t%s||%s%-35s%s||%s\n",BRIGHT_CYAN, RESET, "3. Quan ly du lieu va bao cao",BRIGHT_CYAN, RESET);
	printf("\t\t\t\t\t%s||%s%-35s%s||%s\n",BRIGHT_CYAN, RESET, "4. Quay lai ",BRIGHT_CYAN, RESET);
	printf("\t\t\t\t\t%s++===================================++%s\n",BRIGHT_CYAN, RESET);
	printf("\t\t\t%s>>> Lua chon cua ban: %s", BRIGHT_CYAN, RESET);
}
void profileManagementList(){ // quan ly ho so
	printf("%s\n\t\t\t\t\t++===========QUAN LY HO SO===========++%s\n", BRIGHT_CYAN, RESET);
	printf("\t\t\t\t\t%s||%s%-35s%s||%s\n",BRIGHT_CYAN, RESET, "1. Them Nhan Vien Moi",BRIGHT_CYAN, RESET);
	printf("\t\t\t\t\t%s||%s%-35s%s||%s\n",BRIGHT_CYAN, RESET, "2. Cap nhap ho so nhan vien",BRIGHT_CYAN, RESET);
	printf("\t\t\t\t\t%s||%s%-35s%s||%s\n",BRIGHT_CYAN, RESET, "3. Quay lai ",BRIGHT_CYAN, RESET);
	printf("\t\t\t\t\t%s++===================================++%s\n",BRIGHT_CYAN, RESET);
	printf("\t\t\t%s>>> Lua chon cua ban: %s", BRIGHT_CYAN, RESET);
}
void civilAdministrationList(){ // quan ly nhan su
	printf("%s\n\t\t\t\t\t++==============QUAN LY NHAN SU===============++%s\n", BRIGHT_CYAN, RESET);
	printf("\t\t\t\t\t%s||%s%-44s%s||%s\n",BRIGHT_CYAN, RESET, "1. Sa thai nhan vien",BRIGHT_CYAN, RESET);
	printf("\t\t\t\t\t%s||%s%-44s%s||%s\n",BRIGHT_CYAN, RESET, "2. Quay lai",BRIGHT_CYAN, RESET);
	printf("\t\t\t\t\t%s++============================================++%s\n",BRIGHT_CYAN, RESET);
	printf("\t\t\t%s>>> Lua chon cua ban: %s", BRIGHT_CYAN, RESET);
}
void dataManagementAndReportingList(){  // quan ly du lieu va bao cao
	printf("%s\n\t\t\t\t\t++=========QUAN LY DU LIEU VA BAO CAO=========++%s\n", BRIGHT_CYAN, RESET);
	printf("\t\t\t\t\t%s||%s%-44s%s||%s\n",BRIGHT_CYAN, RESET, "1. Hien thi danh sach nhan vien",BRIGHT_CYAN, RESET);
	printf("\t\t\t\t\t%s||%s%-44s%s||%s\n",BRIGHT_CYAN, RESET, "2. Tra cuu ho so",BRIGHT_CYAN, RESET);
	printf("\t\t\t\t\t%s||%s%-44s%s||%s\n",BRIGHT_CYAN, RESET, "3. Sap xep danh sach nhan vien",BRIGHT_CYAN, RESET);
	printf("\t\t\t\t\t%s||%s%-44s%s||%s\n",BRIGHT_CYAN, RESET, "4. Quay lai ",BRIGHT_CYAN, RESET);
	printf("\t\t\t\t\t%s++============================================++%s\n",BRIGHT_CYAN, RESET);
	printf("\t\t\t%s>>> Lua chon cua ban: %s",BRIGHT_CYAN, RESET );
	
}
void employeeList(){ // quan ly nhan vien
	printf("%s\n\t\t\t\t\t++=====MENU NHAN VIEN=====++%s\n",BRIGHT_CYAN, RESET);
	printf("\t\t\t\t\t%s||%s%-22s  %s||%s\n",BRIGHT_CYAN, RESET, "1. Cham cong",BRIGHT_CYAN, RESET);
	printf("\t\t\t\t\t%s||%s%-22s  %s||%s\n",BRIGHT_CYAN, RESET, "2. Bang cham cong",BRIGHT_CYAN, RESET);
	printf("\t\t\t\t\t%s||%s%-22s  %s||%s\n",BRIGHT_CYAN, RESET, "3. Quay lai",BRIGHT_CYAN, RESET);
	printf("\t\t\t\t\t%s++========================++%s\n",BRIGHT_CYAN, RESET);
	printf("\t\t\t%s>>> Lua chon cua ban: %s", BRIGHT_CYAN, RESET);
}			
		// Ham In An
		
		
		// HAM CHUC NANG !!!
// bat dau lam ham

// ham tim Ma ID TUONG DOI
int findSomethingSameSame(Employee *empPtr, int *length, int *inSide, int *targetIndexPtr){
	char findId[20]; 
	// mang tim kiem 
	Employee listFind[50];
	(*inSide) = 0; 
	(*targetIndexPtr) = -1;
	getString(findId, 21, "Vui long nhap ma nhan vien can duoc cham cong");
	(*inSide) = 0;
	for(int i = 0; i  < *length; i++){
		if(strstr(empPtr[i].empId, findId) != NULL){
			listFind[(*inSide)] = empPtr[i];
			(*targetIndexPtr) = i;  // luu mot ID neu co 1 nhan vien
			(*inSide)++;
		}
	}
// in ra cac nhan vien da duoc tra cuu 
	printf("\n\t\t\t>>> Danh sach cac nhan vien ban da tra <<<\n");
	printf("\t\t\t%s++-------------------------------------------------------------------------------++%s\n",BRIGHT_BLUE, RESET);
	printf("\t\t\t%s||%s %-10s %s|%s %-20s %s|%s %-15s %s|%s %-10s %s|%s %-10s %s||%s\n", 
	        BRIGHT_BLUE, RESET,"MA ID",BRIGHT_BLUE, RESET, "TEN NHAN VIEN",BRIGHT_BLUE, RESET, "CHUC VU",BRIGHT_BLUE, RESET, "LUONG",BRIGHT_BLUE, RESET, "NGAY CONG",BRIGHT_BLUE, RESET);
	printf("\t\t\t%s++-------------------------------------------------------------------------------++%s\n",BRIGHT_BLUE, RESET);
	for(int l = 0; l < (*inSide); l++){
			displayEmployee(&listFind[l]);
	}
	printf("\t\t\t%s++-------------------------------------------------------------------------------++%s\n",BRIGHT_BLUE, RESET);
}
/*
           F01: 
chuc nang: Them nhan vien va so luong
Yeu cau: Bat nhung truong hop nhap het loi
*/ 
void insertEmployee(Employee **empPtr, int *length, int *employee){
	int index;
	int currentIndex = *length;
	int size;
	int isDuplicated;
	char nameIdUnique[20];
	printf("%sSo Luong Nhan Vien Dang Co: %d  \n",BRIGHT_YELLOW ,(*employee));
	printf("Vui long them so luong nhan vien moi (Toi da 100 nhan vien): %s", RESET);
	do{
		valudateChoice(&index);
		if(index <= 0){
			printf("%sERROR !! vui long nhap so luong duong: %s",RED, RESET);
		}else{
			break;
		}
	}while(1);
	if((*length) + index > 100){
		printf("%sERROR !! Danh sach nhan vien da day ! khong the them\n%s", RED, RESET);
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
			printf("%s>>> Nhap thong tin cua nhan vien thu %d  <<< %s\n",GREEN,currentIndex + i +1,RESET);
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
					printf("%sERROR !! Vui long nhap ma ID khac cua nhan vien ! Ma ID da ton tai\n%s", RED, RESET);
				}else{
					strcpy((*empPtr)[currentIndex + i].empId,nameIdUnique);
					break;	
				}
			}while(1);
			
			do{
				getString((*empPtr)[currentIndex + i].nameEmp, 51, "Vui long nhap ten cua nhan vien");
				size = strlen(((*empPtr)[currentIndex + i].nameEmp));
				if (isDigitAndSpecial ((*empPtr)[currentIndex + i].nameEmp, size )){
					printf("%sERROR !! Vui Long Nhap Ten Ma khong co so hay khong co ky tu dac biet !\n%s", RED, RESET);
				}else{
					inputToName((*empPtr)[currentIndex + i].nameEmp, size);
					break;
				}
			}while(1);
				do{
					getString((*empPtr)[currentIndex + i].position, 16, "Nhap chuc vu cua ban");
					size = strlen((*empPtr)[currentIndex + i].position);
						if(isDigitAndSpecial((*empPtr)[currentIndex + i].position, size)){
							printf("%sERROR !! Vui long nhap chuc vu khong co so hay ky tu dac biet ! \n%s",RED, RESET);
						}else{
							inputToName((*empPtr)[currentIndex + i].position, size);
							break;
						}
				}while(1);
				

				printf("%sNhap luong cua nhan vien: %s",BRIGHT_YELLOW, RESET);
			do{
					valudateSalary(&(*empPtr)[currentIndex + i].baseSalary);
					if((*empPtr)[currentIndex + i].baseSalary <= 0){
						printf("%sERROR !! Vui long nhap lai luong phai duong: %s", RED, RESET);
					}else{
						break;
					}
			}while(1);
				(*empPtr)[currentIndex + i].workDay = 0;
				(*employee)++;
			}
		(*length) += index;
		printf("%sNhap thanh cong ! \n%s", GREEN, RESET);	
		}
}
/*
           F04: 
chuc nang: Hien thi nhan vien va so luong + so trang
Yeu cau: Nghi nhung cach nguoi dung de xem cho no tien loi
*/ 
void printEmployee(Employee *empPtr, int *length){
	int totalEmployees = (*length);
	char choiceMenu;
	int empPerPage = 5;
	int page = 0;
	// lam tron so trang ( tai vi neu lay length /EMP_PER_PAGE -> lam tron xuong                      VD 11 / 5 = 2 -> khong dung !);
	// vay nen khi ta muon tron so trang len thi phai dung (length + EMP_PER_PAGE - 1)/EMP_PER_PAGE   VD (11 + 5 -1) / 5 = 3 -> dung !);
	if((*length) == 0){
		
		printf("%s\t\t\t===================================\n", RED);
		printf("\t\t\t>>>>>>>>> Danh sach trong <<<<<<<<<\n");
		printf("\t\t\tVui long nhap thong tin nhan vien !\n");
		printf("\t\t\t===================================\n%s", RESET);
	}else{
		
			do{
			system("cls"); 
			int totalPage = ((*length) + empPerPage - 1) / empPerPage;
			int startIndex = page * empPerPage;
			int endIndex = (page + 1) * empPerPage;
			if(endIndex > totalEmployees){
				endIndex = totalEmployees;
				}
			
			printf("\n\n\n\n\n\n\n\n\n\t\t\tTong so nhan vien: %d | Tong so trang: %d\n", totalEmployees, totalPage);
			printf("\t\t\t\t\t\t      >>> Trang thu %d <<<\n", page + 1);

			printf("\n\t\t\t%s++============================DANH SACH NHAN VIEN================================++%s\n", BRIGHT_BLUE, RESET);
   			printf("\t\t\t%s||%s %-10s %s|%s %-20s %s|%s %-15s %s|%s %-10s %s|%s %-10s %s||%s\n", 
        	BRIGHT_BLUE, RESET, "MA ID", BRIGHT_BLUE, RESET, "TEN NHAN VIEN",BRIGHT_BLUE, RESET, "CHUC VU",BRIGHT_BLUE, RESET,"LUONG",BRIGHT_BLUE, RESET,"NGAY CONG", BRIGHT_BLUE, RESET);
   			 printf("\t\t\t%s++-------------------------------------------------------------------------------++%s\n",BRIGHT_BLUE,RESET);
   			for (int i = startIndex; i < endIndex; i++) {
        	   printf("\t\t\t%s||%s %-10s %s|%s %-20s %s|%s %-15s %s|%s %-10.1lf %s|%s %03d        %s||%s\n",
               BRIGHT_BLUE, RESET,
			   empPtr[i].empId,
			   BRIGHT_BLUE, RESET,
               empPtr[i].nameEmp,
               BRIGHT_BLUE, RESET,
               empPtr[i].position,
               BRIGHT_BLUE, RESET,
               empPtr[i].baseSalary,
               BRIGHT_BLUE, RESET,
               empPtr[i].workDay,
			   BRIGHT_BLUE, RESET);
    		}
    		printf("\t\t\t%s++-------------------------------------------------------------------------------++\n",BRIGHT_BLUE);
    		printf("%s", RESET);
    		printf("\t\t\t%s++===============================================================================++%s\n", RED, RESET);
    		printf("\t\t\t%s||%s   q. tro ve trang truoc  %s|%s  w. Thoat  %s|%s  e. Trang tiep  %s|%s  g. trang hien thi  %s||%s\n", RED, RESET, RED, RESET, RED, RESET, RED, RESET, RED, RESET);
    		printf("\t\t\t%s++--------------------------+------------------------------+---------------------++%s\n", RED, RESET);
    		printf("\t\t\t%s||%s                                  s. So luong                                  %s||%s\n", RED, RESET, RED, RESET);
    		printf("\t\t\t%s++===============================================================================++%s\n", RED, RESET);
    			validateCharractor(&choiceMenu);
    			switch (choiceMenu){
    				case 'q' : case 'Q' : 
    					if(page >= 1){
    						(page)--;
						}else{
							printf("\t\t\t%sERROR !!! Khong co trang truoc ! \n%s", RED, RESET);
							sleep(1);
						}
						break;
					case 'w' : case  'W' :
							return;
					case 'e' : case 'E' :
						if (page < totalPage -1){
							page++;
						}
						else{
							printf("\t\t\t%sERROR !!! Day la trang cuoi cung ! \n%s", RED, RESET);
							sleep(1);
						}
						break;
					case 'g' : case 'G':
						printf("%sVui long chon trang ma ban muon tim: %s", BRIGHT_YELLOW, RESET);
						do{
							valudateChoice(&page);
							if(page > totalPage || page < 1){
								printf("%sERROR !! Khong co trang ban muon ! \nVui long nhap lai: %s", RED, RESET);
							}else{
								page--;
								break;
							}
						}while(1);
						break;
					case 's' : case 'S' :
						do{
							printf("%sNhap so luong nhan vien hien len trong danh sach: %s", BRIGHT_YELLOW, RESET);
							valudateChoice(&empPerPage);
							if(empPerPage > totalEmployees){
								printf("%sERROR !! Khong the in so luong nhan vien nhieu hon tong nhan vien !\n%s", RED, RESET);
							}else{
								page = 0;
								break;
							}
						}while(1);
						break;
    				}
    			}while(1);
	}
}
/*
           F02: 
chuc nang: Cap nhap chuc vu nhan vien va so luong moi cua nhan vien Theo Ma ID
Yeu cau: Bat nhung truong hop nhap loi !
*/ 
void updateEmployee(Employee *empPtr, int *length){
	int choice;
	int size;
	// mang tim kiem 
	int insideIndex = 0;
	int targetIndex;
	char newPosition[16];
	double newBaseSalary;
	// mang tim kiem
	if((*length) == 0){
		printf("\t\t\t%s>>> Khong co nhan vien de Cap nhap ! <<<\n%s", RED, RESET);
	}else{
	findSomethingSameSame(empPtr, length,&insideIndex,&targetIndex);
// in ra cac nhan vien da duoc tra cuu	
// lua chon ma nhan vien CHINH XAC ma can duoc cap nhap !
	if(insideIndex == 0){
		//truong hop neu mang danh sach tra khong co:
		printf("%s\t\t\t>>> Khong co <<< \n%s", RED, RESET);
		return;
	}else if(insideIndex == 1){
		// neu danh sach chi co mot nhan vien duy nhat
			do{
				getString(newPosition, 16, "Vui long nhap vi tri moi cua ban");
				size = strlen(newPosition);
					if(isDigitAndSpecial(newPosition, size)){
						printf("%sERROR !! Vui long nhap chuc vu khong co so hay co ky tu dac biet ! \n%s", RED, RESET);
					}else{
						break;
					}
			}while(1);

			printf("%sVui long nhap luong moi: %s", BRIGHT_YELLOW, RESET);
			do{
				valudateSalary(&newBaseSalary);
				if(newBaseSalary <= 0){
					printf("%sERROR !! Luong Phai la so duong !\nVui long nhap lai luong moi: %s", RED, RESET);
				}
			}while(newBaseSalary <= 0);
			
			choice = forSure(choice, "Cap nhap");
			if (choice == 1 ){
				strcpy(empPtr[targetIndex].position,newPosition);
				empPtr[targetIndex].baseSalary = newBaseSalary;
				printf("%sCap nhap thanh cong ! \n%s", GREEN, RESET);
			}else if(choice == 0){
				printf("%sCap nhap khong thanh cong ! \n%s",RED, RESET);
			}
			
	}else{
		// neu nhieu hon 1 nhan vien 
			targetIndex = findCorrectID(empPtr, length);
			if(targetIndex != -1){
				do{
				getString(newPosition, 16, "Vui long nhap vi tri moi cua ban");
				size = strlen(newPosition);
					if(isDigitAndSpecial(newPosition, size)){
						printf("%sERROR !! Vui long nhap chuc vu khong co so va ky tu dac biet! \n%s", RED, RESET);
					}else{
						inputToName(newPosition, size);
						break;
					}
				}while(1);
				
				printf("%sVui long nhap luong moi: %s", BRIGHT_YELLOW, RESET);
				do{
					valudateSalary(&newBaseSalary);
					if(newBaseSalary <= 0){
						printf("%sERROR !! Luong Phai la so duong !\nVui long nhap lai luong moi: %s", RED, RESET);
					}
				}while(newBaseSalary <= 0);
				
				choice = forSure(choice, "Cap nhap"); // co muon cap nhap hay khong !
				if (choice == 1 ){
					strcpy(empPtr[targetIndex].position,newPosition);
					empPtr[targetIndex].baseSalary = newBaseSalary;
					printf("%sCap nhap thanh cong ! \n%s", GREEN, RESET); // thong bao cap nhap thanh cong
				}else if(choice == 0){
					printf("%sCap nhap khong thanh cong ! \n%s", RED, RESET); // thong bao fail
				}
			}else{
				printf("%sMa ID khong tim thay trong danh sach ! \n%s",RED, RESET); // kiem tra neu nguoi dung nhap khong thay ma
			}
		}
	}
	
}
/*
           F03: 
chuc nang: Xoa nhan vien Theo Ma ID
Yeu cau: Bat nhung truong hop nhap loi
*/ 
void DismissEmployee(Employee *empPtr, int *length, int *employee){
	int choice;
	// mang tim kiem 
	int insideIndex = 0;
	int targetIndex;
	// mang tim kiem
	if((*length) == 0){
		printf("%s>>> Khong co nhan vien de Xoa ! \n%s", RED, RESET);
	}else{
		findSomethingSameSame(empPtr, length,&insideIndex,&targetIndex);
	// in ra cac nhan vien da duoc tra cuu	
	// lua chon ma nhan vien CHINH XAC ma can duoc xoa !
		if(insideIndex == 0){
			printf("%s\t\t\t>>> Khong co <<< \n%s", RED, RESET);
			return;
		}else if(insideIndex == 1){
				choice = forSure(choice, "Xoa");
				if(choice){
						for(int j =targetIndex; j < (*length) -1 ;j++){
							empPtr[j] = empPtr[j+1];
						}
						(*length)--;
						(*employee)--;
						printf("%sXoa thanh cong ! \n%s", GREEN, RESET);
				}else{
					printf("%sXoa khong thanh cong !\n%s", RED, RESET);
				}
		}else{
			targetIndex = findCorrectID(empPtr, length);
			if(targetIndex == -1){
				printf("%skhong tim thay Ma ID trong danh sach ! \n%s",RED, RESET);
				return ;
			}
			choice = forSure(choice, "Xoa");
				if(choice){
						for(int j =targetIndex; j < (*length) -1 ;j++){
							empPtr[j] = empPtr[j+1];
						}
						(*length)--;
						(*employee)--;
						printf("%sXoa thanh cong ! \n%s", GREEN, RESET);
				}else{
					printf("%sXoa khong thanh cong !%s", RED, RESET);
			}	
		}
	}
}
/*
           F05: 
chuc nang: Tim nhan vien Theo ten // co the la theo ID (neu duoc yeu cau) !
Yeu cau: Bat nhung truong hop nhap het loi  // code sao tinh gon het co the
*/ 
void findEmployeeByName(Employee *empPtr, int *length){
	char findName[50];
	int size;
	if((*length) == 0){
		printf("%s>>> Khong co nhan vien can tim <<< \n%s", RED, RESET);
	}else{
		do{
			getString(findName, 51,"Vui long nhap ten can tim cua ban" );
			size = strlen(findName);
			if (isDigitAndSpecial (findName, size )){
				printf("%sERROR !! Vui Long Nhap Ten Ma khong co so va khong co ky tu dac biet !\n%s", RED, RESET);
				
			}else{
				break;
			}
		}while(1);
		printf("Danh sach cua nhanh vien \n");
		printf("%s", BRIGHT_BLUE);
		printf("\t\t\t++-------------------------------------------------------------------------------++\n");
		printf("\t\t\t|| %-10s | %-20s | %-15s | %-10s | %-10s ||\n", 
	        	"MA ID", "TEN NHAN VIEN", "CHUC VU", "LUONG", "NGAY CONG");
		for(int i = 0; i < *length; i++){
			if(strstr(empPtr[i].nameEmp, findName) != NULL){
				displayEmployee(&empPtr[i]);
			}else{
				continue;
			}
		}
		printf("\t\t\t++-------------------------------------------------------------------------------++\n");	
		printf("%s", RESET);	
	}
}
/*
           F06: 
chuc nang: Sap xep nhan vien theo luong cua minh // co the dung thuat toan khac (neu duoc yeu cau) !
Yeu cau: Bat nhung truong hop nhap het loi & code sao tinh gon la du
*/ 
void sortBySalary(Employee *empPtr, int *length, int*sortchoice){
	Employee temp;
	if((*length) == 0){
		printf("%sDanh sach rong ! Vui long them danh sach truoc khi sap xep ! \n%s",RED, RESET);
	}else if ((*length) == 1){
		printf("%sDanh sach chi co 1 nhan vien ! Khong can phai sap xep ! \n%s", RED, RESET);
	}else{
		do{
			printf("%s\t\t\t++=========MENU SAP XEP=========++\n", BRIGHT_CYAN);
			printf("\t\t\t||%-28s||\n", "1. Sap xep tang dan theo luong");
			printf("\t\t\t||%-28s||\n", "2. Sap xep giam dan theo luong");
			printf("\t\t\t||%-30s||\n", "3. Quay lai");
			printf("\t\t\t++==============================++\n");
			printf("\t\t\t>>> Lua chon cua ban: %s", RESET);
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
					printf("%sSap xep thanh cong !\n%s", GREEN, RESET);
					printEmployee(empPtr, length);
					
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
					printf("%sSap xep thanh cong !\n%s", GREEN, RESET);
					printEmployee(empPtr, length);
					
					break;
				}
				case 3 :
					printf("%sThoat thanh cong ! \n%s", RED, RESET);
					return;
				default :
					printf("%sVui long chi chon tu (1->3): %s", RED, RESET);
			}
		}while(1);
	}

}

/*
           F07: 
chuc nang: Cham cong cho nhan vien bang ma id // hoac ten (neu duoc yeu cau ) !
Yeu cau: Bat nhung truong hop nhap loi & khong de cho nhan vien khong duoc cham cong cung ngay !
*/ 
void attendanceForTheDay(Employee *empPtr, TimeSheet *empTimePtr,int *length,int *timeSheetLength){
	char newDate[20];
	int newIndex;
	int currentLog = (*timeSheetLength);
	int timeSheetIndex;
	// mang tim kiem 
	int insideIndex = 0; 
	int targetIndex = -1;
	int size;
	char finalId[20];
	// mang tim kiem
	if((*length) == 0){
		printf("\t\t\t%s>>> Khong co nhan vien de Cham Cong ! <<<\n%s", RED, RESET);
		return;
	}
	if ((*timeSheetLength) > MAX_TIME_EMP){
		printf("%sERROR !! Danh sach cham cong da day ! Khong the them ! \n%s", RED, RESET);
		return;
	}	
		do{
			getString(newDate, 21, "Vui long nhap ngay/thang/nam cham cong (DD/MM/YYYY)");
			if(validateDate(newDate)){
				break;
			}else{
				printf("%sERROR !! Ngay/thang/nam khong hop le !\nVui long nhap lai !\n %s", RED, RESET);
			}
		}while(1);
	findSomethingSameSame(empPtr, length,&insideIndex,&targetIndex);
	if(insideIndex == 0){
		//truong hop neu mang danh sach tra khong co:
		printf("%s\t\t\t>>> Khong co <<< \n%s", RED, RESET);
		return;
	}else if(insideIndex == 1){
		// neu danh sach chi co mot nhan vien duy nhat
		strcpy(finalId, empPtr[targetIndex].empId);

	}else{
		// neu nhieu hon 1 nhan vien 
		targetIndex = findCorrectID(empPtr, length);
		if(targetIndex == -1){
			printf("%sERROR !! Khong tim thay ma %s trong danh sach !\n%s", RED, RESET);
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
			printf("%sNhan vien %s da cham cong vao ngay %s roi%s",BRIGHT_BLUE, finalId, newDate, RESET);
		}else{
			newIndex = (*timeSheetLength);
			strcpy(empTimePtr[newIndex].status, "Di lam");
			strcpy(empTimePtr[newIndex].date,newDate);
			sprintf(empTimePtr[newIndex].logId, "LOG%03d", (*timeSheetLength) + 1);
			strcpy(empTimePtr[newIndex].empId,empPtr[targetIndex].empId);
			empPtr[targetIndex].workDay += 1;
			(*timeSheetLength)++;
			printf("%sCham cong ngay %s cho nhan vien %s thanh cong ! \n%s",GREEN, newDate, empPtr[targetIndex].empId, RESET);
		}
}
/*
           F08: 
chuc nang: Xuat hien bang cham cong theo MA ID // hoac ten (Tuong /Tuyet doi) (Neu duoc yeu cau) !
Yeu cau: Bat nhung truong hop nhap loi & code gon !
*/ 
void viewTheWorkSchedule(Employee *empPtr, TimeSheet *empTimePtr,int *length,int *timeSheetLength){
	char findId[20];
	int find;
	if((*length) == 0){
		printf("%s>>> Khong co nhan vien de tra ! <<< \n%s", RED, RESET);
	}else{
		getString(findId, 21, "Vui long nhap ma nhan vien cua ban (TIM TUYET DOI)");
		find = 0;
		for(int i= 0;i < *length; i++){
			if (strcmp(empPtr[i].empId, findId) == 0){
				find = 1;
				break;
			}
		}
		if(find){
			printf("%s", BRIGHT_BLUE);
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
	    		printf("%s", RESET);
		}else{
			printf("%sKhong tim thay ma id trong danh sach ! \n%s", RED, RESET);
		}
	}
}
		/// HAM CHUC NANG !!!
		
// KET THUC !!
