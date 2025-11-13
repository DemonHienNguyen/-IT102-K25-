#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
	// siKibiDi Va1 L1t@gmail.memaybeo
	char list[100];
	int i;
	int specialCount = 0, nomaralCount = 0, capitalCount = 0, numberCount = 0;
do{

	printf("Enter your password(at least 8 character): ");
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
		}else{
			specialCount++;
		}
	}

	int valued = (nomaralCount >= 1 &&  numberCount >= 1 && capitalCount >= 1 && specialCount >= 1 && size >=8);
	if(valued){
		printf("Hop le! \n");
		break;
	}else{
		printf("khong hop le! \n");
		if(nomaralCount < 1){
			printf("Thieu chu cai thuong ! \n");
		}else if(numberCount < 1){
			printf("Thieu chu so ! \n");
		}else if(capitalCount < 1){
			printf("Thieu chu cai in hoa ! \n");
		}else if(specialCount < 1){
			printf("Thieu chu cai dac biet ! \n");
		}else{
			printf("Mat khau phai dai den 8 ky tu ! \n");
		}
	}
}while(1);

	
	return 0;
}
