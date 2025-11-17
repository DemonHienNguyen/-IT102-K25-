#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
int isPrime(int *a);
int insertArray(int *arrPtr);
void printArray(int *arrPtr, int *length);
void printOdd(int *arrPtr, int *length);
void printPrime(int *arrPtr, int *length);
void reverseArray(int *arrPtr, int *length);
void sortArray(int *arrPtr, int *length, int choice);
void findValue(int *arrPtr, int *length, int value);

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
int isPrime(int *a){
	int i;
	int Prime = 1;
	if(*a < 2){
		Prime = 0;
	}else{
		for(i = 2; i*i <= *a; i++){
			if(*a % i == 0){
				Prime = 0;
				break;
			}
		}
	}
	return Prime;
}
int insertArray(int *arrPtr){                                                   
	int length;
	int i;
	printf("Nhap kich co cua mang: ");
	scanf("%d", &length);
	for(i = 0; i < length; i ++){
		printf("Array[%d] = ", i);
		scanf("%d", arrPtr + i);
	}
	printf("Nhap thanh cong ! \n");
	return length;
}
void printArray(int *arrPtr, int *length){
	int i;
	printf("Vay mang la: \n");
	for(i = 0; i < *length; i++){
		printf("   %d", *(arrPtr + i));
	}
	
}
void printOdd(int *arrPtr, int *length){
	int i;
	printf("Vay so phan tu chan xuat hien trong mang la: \n");
	for(i =0 ; i < *length; i++){
		if(*(arrPtr + i) % 2 == 0 ){
			printf("   %d", *(arrPtr + i));
		}
	}
}
void printPrime(int *arrPtr, int *length){
	int i; 
	printf("Vay cac so nguyen to trong mang la: \n");
	for(i =0 ; i <*length; i ++){
		if(isPrime(&*(arrPtr+i))){
			printf("   %d", *(arrPtr+i));
		}
	}
}
void reverseArray(int *arrPtr, int *length){
	int i =0, j = *length -1;
	while(i < j){
		swap(&*(arrPtr +i), &*(arrPtr+j));
		i++;
		j--;
	}
	printArray(arrPtr,length);
}
void sortArray(int *arrPtr, int *length, int choice){
	int i, j;
	if(choice == 1){
		for(i = i; i < *length; i++){
		int value = *(arrPtr+ i);
		j = i - 1;
		while(j>= 0 && *(arrPtr+ j) > value){
			*(arrPtr + j + 1) = *(arrPtr+j);
			j--;
		}
		*(arrPtr + j + 1) = value;
		}
	}else if(choice == 2){
		for(i = i; i < *length; i++){
		int value = *(arrPtr+ i);
		j = i - 1;
		while(j >= 0 && *(arrPtr + j) < value){
			*(arrPtr + j + 1) = *(arrPtr+j);
			j--;
		}
			*(arrPtr + j + 1) = value;
		}
	}
	printArray(arrPtr, length);
}
void findValue(int *arrPtr, int *length, int value){
	int i;
	int found = 0;
	for(i= 0; i < *length; i++){
		if(*(arrPtr+ i) == value){
			found = 1;
			break;
		}
	}
	if(found){
		printf("Vay da tim thay %d o vi tri %d\n", value, i);
	}else{
		printf("Vay khong tim thay gia tri nao !\n");
	}
}

int main(){
	int choice, c, sortChoice, VALUE = 0;
	int hasPick1 = 0;
	int size;
	int list[100];
	do{
		printf("\n\t\t+======================MENU=====================+\n");
		printf("\t\t|%-38s \t|\n", "1. Nhap phan tu");
		printf("\t\t|%-38s \t|\n", "2. In ra phan tu");
		printf("\t\t|%-38s \t|\n", "3. In ra cac phan tu la so chan");
		printf("\t\t|%-38s \t|\n", "4. In ra cac phan tu la so nguyen to");
		printf("\t\t|%-38s \t|\n", "5. Dao nguoc mang");
		printf("\t\t|%-38s \t|\n", "6. Sap xep mang");
		printf("\t\t|%-38s \t|\n", "7. Nhap 1 phan tu va tim kiem");
		printf("\t\t|%-38s \t|\n", "8. Thoat");
		printf("\t\t+===============================================+\n\n");
		printf("\t\t---Lua chon cua ban: ");
		scanf("%d", &choice);
		while((c = getchar()) != '\n' && c != EOF){}
		switch(choice){
			case 1 :{
				size  = insertArray(list);
				hasPick1 = 1; 
				break;
			}
			case 2 :{
				printArray(list, &size);
				break;
			}
			case 3 :{
				printOdd(list, &size);
				break;
			}
			case 4 :{
				printPrime(list, &size);
				break;
			}
			case 5 :{
				reverseArray(list, &size);
				break;
			}
			case 6 :{
				printf("--------- MENU SAP XEP ---------\n");
				printf("1. Sap xep tang dan\n");
				printf("2. Sap xep giam dan\n");
				printf("Lua chon cua ban: ");
				scanf("%d", &sortChoice);
				sortArray(list, &size, sortChoice);
				break;
			}
			case 7 :
				printf("Nhap gia tri ma ban muon tim kiem: ");
				scanf("%d", &VALUE);
				findValue(list, &size,VALUE);
				break;
			case 8 :{
				exit(0);
			}
		}
	}while(1);
	
	return 0;
}
