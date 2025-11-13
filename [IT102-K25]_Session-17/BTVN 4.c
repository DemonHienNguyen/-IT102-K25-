#include <stdio.h>
#include <string.h>

void deleteCharacter(char arr[],int size,int deleteChar);
	

void deleteCharacter(char arr[],int size,int deleteChar){
	int i, j;
	for(i = 0 ; i < size; i++){
		if(arr[i] == deleteChar){
			for(j = i; j< size; j++){
				arr[j] = arr[j+1];
			}
			size--;
			i--;
		}
	}
	printf("Vay mang sau khi xoa la: %s", arr);
}


int main(){
	
	char list[100];
	char deleteChar;
	
	printf("Enter your string: ");
	fgets(list, 100, stdin);
	list[strcspn(list, "\n")] ='\0';
	int length = (int)strlen(list);
	printf("Nhap ky tu can xoa: ");
	scanf(" %c", &deleteChar); 
	deleteCharacter(list,length,deleteChar );
	return 0;
}
