#include <stdio.h>
#include <ctype.h>
#include <string.h>

void getWordMAx(char arr[], int size){
	int currentWordLength = 0, maxWordLength = 0, maxStartIndex = 0;
	char listPhu[100];
	int i;
	for(i= 0; i <= size; i++){
		if(arr[i] != ' ' && arr[i] != '\0' && arr[i] != '\t'){
			currentWordLength++;
		}else{
			if(currentWordLength > maxWordLength){
				maxWordLength = currentWordLength;
				maxStartIndex = i - maxWordLength;
			}
			currentWordLength = 0;
		}
 	}

	strncpy(listPhu, arr + maxStartIndex, maxWordLength);
	listPhu[maxWordLength] = '\0';
	
	printf("Vay tu dai nhat trong mang la: \"%s\" (voi do dai la: %d)", listPhu, maxWordLength);
}


int main(){
	char list[1000];
	int i, j;
	
	printf("Enter your string: ");
	fgets(list, 1000, stdin);
	list[strcspn(list,"\n")] = '\0';
	int size = (int)strlen(list);
	getWordMAx(list, size);
			
		
	return 0;
}
