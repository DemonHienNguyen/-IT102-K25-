#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main(){
	
	char listOne[100], listTwo[100];
	int i;
	printf("Enter your first string: ");
	fgets(listOne, 100, stdin);
	listOne[strcspn(listOne, "\n")] = '\0';
	int sizeOne = (int)strlen(listOne);
	
	printf("Enter your second string: ");
	fgets(listTwo, 100, stdin);
	listTwo[strcspn(listTwo, "\n")] = '\0';
	int sizeTwo = (int)strlen(listTwo);
// cach 1:	
//	for(i= 0;  i < sizeOne; i++){
//		listOne[i] = tolower(listOne[i]);
//	}
//	for(i= 0;  i < sizeTwo; i++){
//		listTwo[i] = tolower(listTwo[i]);
//	}
//	if(strcmp(listOne, listTwo) == 0){
// cach 2: dung stricmp ! : dùng de so sanh 2 chuoi khong quan trong chu thuong hay chu hoa
	if(stricmp(listOne, listTwo) == 0){
		printf("Giong nhau");
	}else{
		printf("Khac nhau !");
	}
	
	return 0;
}
