#include <stdio.h>
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

	char charValue;
	printf("Nhap ky tu ma ban can tim: ");
	scanf(" %c", &charValue);
	
	int count = 0;
	for(i = 0;i < size; i++){
		if(list[i] == charValue){
			count++;
		}
	}
	printf("\nso lan xuat hien cua %c trong %s la: %d", charValue, list, count);
}
