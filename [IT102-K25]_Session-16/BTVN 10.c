#include <stdio.h>
#include <string.h>
#include <ctype.h>

void printAppearCharacter(char arr[], int N);

void printAppearCharacter(char arr[], int N){
	int i, j, k;
	int count, exist = 0;
	char mangPhuChu[100];
	int  mangPhuSo[100]; 
	int currentNum = 0, currentChar = 0;
	for(i = 0;i <N; i++){
		count = 0;
		char tempoChar = arr[i];
		for(j = 0; j < N; j++){
			if(tempoChar == arr[j]){
				count++;
			}
		}
		exist = 0;
		for(k =0; k < currentChar; k++){
			if(mangPhuChu[k] == tempoChar){
				exist = 1;
				break;
			}
		}
		if(!exist){
			mangPhuChu[currentChar] = tempoChar;
			mangPhuSo[currentNum] = count;
			currentChar++;
			currentNum++;
		}
	}
	for(i=0;i< currentNum; i++){
		printf("%c: %d\n",mangPhuChu[i], mangPhuSo[i]);
	}
}



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
	printAppearCharacter(list, size);
	
	return 0;
}
