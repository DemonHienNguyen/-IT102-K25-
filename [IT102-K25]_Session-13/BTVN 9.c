# include <stdio.h>


void smallest_Common_Multiple(int Number1, int Number2){
	int temp, SCM, greatest_Common_Wish;
	int ogirinalNumber1 = Number1, ogirinalNumber2 = Number2;

	while(Number2 != 0){
		temp = Number1 % Number2;
		Number1 = Number2;
		Number2 = temp;
	}
	greatest_Common_Wish = Number1;
	SCM = (ogirinalNumber1*ogirinalNumber2)/greatest_Common_Wish;
	printf("Vay UCLN la: %d", greatest_Common_Wish);
}

int main(){
	int number1, number2;
	printf("Nhap so thu nhat: ");
do{
	if(scanf("%d", &number1) != 1){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar() != '\n');
		continue;
	}
	while(getchar() != '\n');
	if(number1 <=0){
		printf("Loi ! Vui long nhap lai: ");
	}
}while(number1 <=0);
	printf("Nhap so thu Hai: ");
do{
	if(scanf("%d", &number2) != 1){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar() != '\n');
		continue;
	}
	while(getchar() != '\n');
	if(number2 <=0){
		printf("Loi ! Vui long nhap lai: ");
	}
}while(number2 <=0);

smallest_Common_Multiple(number1,number2);
	
}
