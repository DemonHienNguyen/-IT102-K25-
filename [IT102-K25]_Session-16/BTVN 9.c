#include <stdio.h>
#include <string.h>

int main(){
	char list[100];
	int i, j;
	printf("Enter your string: ");
	fgets(list, 100, stdin);
	
	int size = (int)strlen(list);
	
	if(size > 0 && list[size -1] == '\n'){
		list[size -1] = '\0';
		size--;
	}
	
	char deleteChar;
	printf("Nhap ky tu can xoa: ");
	scanf(" %c", &deleteChar);
	
	for(i= 0; i < size; i++){
		if(list[i] == deleteChar){
			for(j = i; j < size; j++){
				list[j] = list[j+1];
			}
			size--;
			i--;
		}
	}
	printf("Vay chuoi sau khi xoa la: \"%s\" ", list);
	
	return 0;
}
