#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
	char list[1000], listPhu[100];
	int i, j;
	
	printf("Enter your string: ");
	fgets(list, 1000, stdin);
	list[strcspn(list,"\n")] = '\0';
	int size = (int)strlen(list);
	
	int currentWordLength = 0, maxWordLength = 0, maxStartIndex = 0;
	
	for(i= 0; i <= size; i++){
		if(list[i] != ' ' && list[i] != '\0' && list[i] != '\t'){
			currentWordLength++;
		}else{
			if(currentWordLength > maxWordLength){
				maxWordLength = currentWordLength;
				maxStartIndex = i - maxWordLength;
			}
			currentWordLength = 0;
		}
 	}

	strncpy(listPhu, list + maxStartIndex,maxWordLength);
	listPhu[maxWordLength] = '\0';
			
	printf("Vay tu dai nhat trong mang la: \"%s\" (voi do dai la: %d)", listPhu, maxWordLength);
		
	return 0;
}
