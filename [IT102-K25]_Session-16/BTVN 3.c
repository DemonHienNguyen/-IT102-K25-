#include <stdio.h>
#include <string.h>

void swap(char*a, char*b){
	int temp  = *a;
	*a = *b;
	*b = temp;
}




int main(){
	
	char string[100];
	int i, j;
	printf("Enter your String: ");
	fgets(string, 100, stdin);
	
	int size = (int)strlen(string);
	
	if(size > 0 && string[size - 1] == '\n'){
		string[size - 1] = '\0';
		size--;
	}
	printf("Vay chuoi Truoc khi dao nguoc la: ");
	fputs(string, stdout);
	//  cách 1 :
//	printf("\nChuoi sau khi dao nguoc la: ");
//	for(i = size -1; i>=0;i--){
//		printf("%c", string[i]);
//	}
	// cach 2 : su dung con tro gian tiep / su dung ngay trong main cung duoc 
	i = 0;
	j = size - 1;
	while(i < j){
		swap(&string[i], &string[j]);
		i++;
		j--;
	}
	printf("\nChuoi sau khi dao nguoc la: ");
	for(i = 0; i<size;i++){
		printf("%c", string[i]);
	}	

	return 0;
}
