#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printFlowerAndNomral(char arr[], int size, int choices);

void printFlowerAndNomral(char arr[], int size, int choices){
	int i;
	if(choices == 1){
		for(i= 0;i < size; i++){
			arr[i] = toupper(arr[i]);
		}
		printf("Vay mang sau khi in hoa la: %s\n", arr);
	}else if(choices == 2){
		for(i= 0;i < size; i++){
			arr[i] = tolower(arr[i]);
		}
		printf("Vay mang sau khi in thuong la: %s\n", arr);
	}
}

int main(){
	int choice, i;
	char list[100];
	printf("Enter your String: ");
	fgets(list, 100, stdin);
	int size = (int)strlen(list);
	list[strcspn(list,"\n")] = '\0';
	
do{
	printf("+----------MENU----------+\n");
	printf("|%-21s \t |\n", "1.In Hoa");
	printf("|%-21s \t |\n", "2.In Thuong");
	printf("|%-21s \t |\n", "3.Thoat");
	printf("+------------------------+\n");
	printf("Lua chon cua ban: ");
	scanf("%d", &choice);
		switch(choice){
			case 1 :{
				printFlowerAndNomral(list, size, choice);
				break;
			}
			case 2 :{
				printFlowerAndNomral(list, size, choice);
				break;
			}
			case 3 :{
				exit(0);
				break;
			}
		}
		
}while(choice != 3);
	
	
	return 0;
}
