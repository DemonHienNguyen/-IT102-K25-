#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
	// siKibiDi Va1 L1t@gmail.memaybeo
	char list[100];
	int i;
	int specialCount = 0, nomaralCount = 0, capitalCount = 0, numberCount = 0;
do{

	printf("Enter your password: ");
	fgets(list, 100, stdin);
	list[strcspn(list,"\n")] = '\0';
	
	int size = (int)strlen(list);
	
	
	specialCount = 0, nomaralCount = 0, capitalCount = 0, numberCount = 0;
	for(i = 0; i < size; i++){
		if(islower(list[i])){
			nomaralCount++;
		}else if(isdigit(list[i])){
			numberCount++;
		}else if(isupper(list[i])){
			capitalCount++;
		}else if(list[i] == ' '){
			specialCount++;
		}
	}
	int valued = (nomaralCount >= 1 &&  numberCount >= 1 && capitalCount >= 1 && specialCount >= 1);
	if(valued){
		printf("Hop le!");
		break;
	}else{
		printf("khong hop le!");
	}
}while(1);

	
	return 0;
}
