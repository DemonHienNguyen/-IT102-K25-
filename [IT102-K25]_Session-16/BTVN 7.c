#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
	char list[100];
	int i;
	printf("Enter your string: ");
	fgets(list, 100, stdin);
	
	int size = (int)strlen(list);
	
	if(size > 0 && list[size -1] == '\n'){
		list[size -1] = '\0';
		size--;
	}
	
	int special_Characters_Count = 0;
	int letter_Count = 0;
	int number_Count = 0;
	for(i= 0; i < size; i++){
		if(isalpha(list[i])){
			letter_Count++;
		}else if(isdigit(list[i])){
			number_Count++;
		}else{
			special_Characters_Count++;
		}
	}
	printf("Vay trong \"%s\" xuat hien: \n",list);
	printf("So chu cai xuat hien: %d \n", letter_Count);
	printf("So chu cai dac biet xuat hien: %d \n", special_Characters_Count);
	printf("So xuat hien: %d \n", number_Count);
	
}
