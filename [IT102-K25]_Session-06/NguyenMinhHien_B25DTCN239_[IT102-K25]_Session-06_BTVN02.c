#include <stdio.h>
int main(){
	printf("---DOAN SO BI MAT---\n");
	int Secret;
	int Guess;
	
	printf("nhap so Bi mat:");
	scanf("%d", &Secret);
	
	printf("Doan so bi mat la gi nao: ");
	scanf("%d", &Guess);
	
	do{
		if(Secret == Guess){
			printf("Chuc mung, ban da doan dung!");
			return 0;
		}else{
			printf("Doan Lai: ");
			scanf("%d", &Guess);
		}
	}while(Guess != 0);
	
	
	return 0;
}
