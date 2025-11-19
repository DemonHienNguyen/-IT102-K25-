#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct{
	char name[30];
	float price;
	int quality;

}Product;

void removeNewLine(char *a){
	size_t len = strlen(a);
	a[len - 1] = '\0';
}
void removeBuffer(){
	int c;
	while((c = getchar()) != '\n' && c != EOF);
}

void insert(Product arr[], int *length);
void insert(Product arr[], int *length){
	int i;
	for(i =0 ; i < *length; i++){
		printf("Nhap Ten San Pham thu %d: ", i+1);
		fgets(arr[i].name, 50, stdin);
		removeNewLine(arr[i].name);
		printf("Nhap Gia cua san pham %d: ", i+1);
		scanf("%f", &arr[i].price);
		removeBuffer();
		printf("Nhap so luong san pham %d: ", i+1);
		scanf("%d", &arr[i].quality);
		removeBuffer();
	}
	printf("Nhap thanh cong ! \n");
}
float sumMoney(Product arr[], int *length){
	int i;
	float sum = 0;
	for(i = 0;i  <*length; i++){
		sum += (arr[i].price * arr[i].quality);
	}
	return sum;
}
int main(){
	int size = 5;
	int i;
	Product *somthing = (Product*)malloc(size * sizeof(Product));
	if(somthing == NULL){
		printf("Cap phat fail roi em ! \n");
	}else{
		printf("Cap Phat thanh cong my man !\n");
	}
	insert(somthing, &size);
	printf("--- Danh sach cac san pham ---\n");
	for(i = 0 ; i < size; i++){
		printf("------------------------------------\n");
		printf("| Ten: %s | Gia: %.1f | So luong: %d | \n", somthing[i].name, somthing[i].price, somthing[i].quality);
		printf("------------------------------------\n");
	}
	float result = sumMoney(somthing, &size);
	printf("Tong gia tri san pham la: %.1f", result);
	free(somthing);
	return 0;
}

