#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
	char model[50];
	int year;
	float price;
	
}Xe ;
void removeBuffer();
void removeNewLine(char *a);
void insertCar(Xe *ptr);

void removeNewLine(char *a){
	size_t len = strlen(a);
	a[len - 1] = '\0';
}
void removeBuffer(){
	int c;
	while((c = getchar()) != '\n' && c != EOF);
}

void insertCar(Xe *ptr){
	printf("Nhap ten mau cua xe: ");
	fgets(ptr -> model, 50, stdin);
	removeNewLine(ptr -> model);
	printf("Nhap nam san xuat cua xe: ");
	scanf("%d", &ptr -> year);
	removeBuffer();
	printf("Nhap gia cua xe: ");
	scanf("%f", &ptr -> price);
	removeBuffer();
}



int main(){
	Xe myCar;
	insertCar(&myCar);
	printf("----- Thong Tin Xe ----- \n");
	printf("Ten xe: %s \n", myCar.model);
	printf("Nam su dung xe: %d \n",myCar.year);
	printf("Gia xe: %.1f \n",myCar.price);
	
	
	
	
	

	return 0;
}

