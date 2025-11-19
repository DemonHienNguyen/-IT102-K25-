#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void removeBuffer(){
	 int c;
	 while((c = getchar()) != '\n' && c != EOF);
}
void removeNewLine(char *a){
	 size_t len = strlen(a);
	 a[len -1] = '\0';
}


int main(){

	printf("Hello World");

	return 0;
}

