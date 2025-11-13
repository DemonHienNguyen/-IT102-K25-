#include <stdio.h>
#include <string.h>

int main(){
	char list[100];
	char stringValue[50];
	int i, j;
	int exist = 0, match = 0;
	printf("Enter your string: ");
	fgets(list, 100, stdin);
	list[strcspn(list,"\n")] = '\0';
	int sizeOne = (int)strlen(list);
	
	printf("Nhap chuoi can tim: ");
	fgets(stringValue, 50, stdin);
	stringValue[strcspn(stringValue,"\n")] = '\0';
	int sizeTwo = (int)strlen(stringValue);
	// cach 1: 
//	for (i= 0; i <sizeOne; i++){
//		if(list[i] == stringValue[0]){
//			match = 1;
//			for(j = 0; j < sizeTwo; j++){
//				if(list[i+j] != stringValue[j]){
//					match = 0;
//					break;
//				}
//			}
//			if(match){
//				exist = 1;
//				break;
//			}
//		}
//	}
//	if(exist){
//		printf("%s la chuoi con cua %s", stringValue, list);
//	}else{
//		printf("%s khong la chuoi con cua %s", stringValue, list);
//	}
	// cach 2 :
	if(strstr(list, stringValue) != NULL){
		printf("Vay %s la chuoi con cua %s",stringValue, list);
	}else{
		printf("Vay %s khong la chuoi con cua %s",stringValue, list);
	}
	
	
	return 0;
}

