#include <stdio.h>
#include <string.h>

void swap(char *a, char *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}




int main(){
	int i, j;
	char list[100];
	char listcpy[100];
	
	printf("Enter your String: ");
	fgets(list, 100, stdin);
	
	int size = (int)strlen(list);
	
	if(size > 0 && list[size-1] == '\n'){
		list[size - 1] = '\0';
		size--;
	}
	
	strcpy(listcpy, list);
	
	i = 0;
	j = size - 1;
	while (i < j){
		swap(&list[i], &list[j]);
		i++;
		j--;
	}
	if (strcmp(list, listcpy)==0){
		printf("La palindrome");
	}else{
		printf("Khong la palindrome");
	}
	
	
	
	return 0;
}
