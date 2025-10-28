#include <stdio.h>

int main(){
	
	char Kytu;
	printf("---MAGIC---\n");
	
	printf("nhap ky tu ban can nhap: ");
	scanf(" %c", &Kytu);
	
	if(islower(Kytu)){
		char Kytudoi = toupper(Kytu);
		printf("Ky tu tuong ung: %c", Kytudoi);
	}else if(isupper(Kytu)){
		char Kytudoi = tolower(Kytu);
		printf("Ky tu tuong ung: %c", Kytudoi);
	}else{
		printf("khong phai la chu cai ");
	}
	return 0;
}
