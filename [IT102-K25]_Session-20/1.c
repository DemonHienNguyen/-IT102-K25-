#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
	char Name[50]; 
	int Age;
	char PhoneNumber[10];
}Sv;



int main(){
	Sv student01 = {
	"Demon Of Ambittion",
	19,
	"0987782067",
	};
	printf("Thong tin Ca nhan: \n");
	printf("--------------------------\n");
	printf("Ten: %s \n",student01.Name);
	printf("Tuoi: %d \n",student01.Age);
	printf("So dien thoai: %s \n", student01.PhoneNumber);
	printf("--------------------------\n");
	return 0;
}

