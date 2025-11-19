#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct{
	char street[100]; 
	char city[50]; 
	int zip; 

}Address ;

typedef struct{
	char name[50]; 
	int age;
	Address address;
}Person ;

void removeNewLine(char *a){
	size_t len = strlen(a);
	a[len - 1] = '\0';
}
void removeBuffer(){
	int c;
	while((c = getchar()) != '\n' && c != EOF);
}

void nhapThongTinNguoiDung(Person *per){
	printf("Nhap ten cua hoc sinh: ");
	fgets(per -> name, 50, stdin);
	removeNewLine(per -> name);
	printf("Nhap tuoi cua ban: ");
	scanf("%d", &per -> age);
	removeBuffer();
	printf("Nhap ten duong: ");
	fgets(per -> address.street, 50, stdin);
	removeNewLine(per -> address.street);
	printf("Nhap ten Thanh pho: ");
	fgets(per -> address.city, 50, stdin);
	removeNewLine(per -> address.city);
	printf("Nhap ma Zip code: ");
	scanf("%d", &per -> address.zip);
	removeBuffer();
}
int main(){
	Person person01;
	nhapThongTinNguoiDung(&person01);
	printf("Ten: %s \n", person01.name);
	printf("Tuoi: %d \n", person01.age);
	printf("Ten duong: %s \n", person01.address.street);
	printf("Ten city: %s \n", person01.address.city);
	printf("Ten ma Zip: %d \n", person01.address.zip);
	
	
	return 0;
}

