#include <stdio.h>
#include <stdlib.h>

int insert(int *arrPtr);
void print(int *arrPtr, int *lengthPtr);
void len(int *lengthPtr);
void sum(int *arrPtr, int *lengthPtr);
int maxArray(int *arrPtr, int *lengthPtr);

int insert(int *arrPtr){
	int length;
	int i;
	printf("Enter your size: ");
	scanf("%d", &length);
	printf("Enter your Element in Array: \n");
	for(i= 0; i< length; i++){
		printf("Array[%d] = ", i);
		scanf("%d", arrPtr+i);
	}
	printf("Nhap thanh cong !\n");
	return length;
	
}
void len(int *lengthPtr){
	printf("Vay do dai cua mang la: %d \n", *lengthPtr);
}
void sum(int *arrPtr, int *lengthPtr){
	int i, sum = 0; 
	for(i= 0; i < *lengthPtr; i ++){
		sum += *(arrPtr + i);
	}
	printf("Vay tong cac phan tu trong mang la: %d \n", sum);
}
void print(int *arrPtr, int *lengthPtr){
	int i;
	printf("\t\tVay mang la: \n\t\t");
	for(i= 0; i<*lengthPtr;i++){
		printf("  %d", *(arrPtr + i));
	}
	printf("\n");
}
int maxArray(int *arrPtr, int *lengthPtr){
	int maxValue = *arrPtr, i;
	for(i= 1;i<*lengthPtr;i++){
		if(*(arrPtr + i) > maxValue){
			maxValue = *(arrPtr + i);
		}
		
	}
	return maxValue;
}

int main(){
	int choice, hasPick1 = 0, size; 
	int list[100], max;
	do{
		printf("\t\t+==============MENU==============+\n");
		printf("\t\t|%-25s \t |\n", "1. Nhap kich co va phan tu");
		printf("\t\t|%-25s \t |\n", "2. Hien thi phan tu");
		printf("\t\t|%-25s \t |\n", "3. Tinh do dai cua mang");
		printf("\t\t|%-25s \t |\n", "4. Tong cac phan tu");
		printf("\t\t|%-25s \t |\n", "5. Hien thi phan tu lon nhat");
		printf("\t\t|%-25s \t |\n", "6. Thoat");
		printf("\t\t+================================+\n\n");
		printf("\t\t---Lua chon cua ban: ");
		scanf("%d", &choice);
		switch(choice){
			case 1 :
				size = insert(list);
				hasPick1 = 1;
				break;
			case 2 :
				if(hasPick1){
					print(list, &size);
				}else{
					printf("Vui long chon 1 !\n");
				}
				break;
			case 3 :
				if(hasPick1){
					len(&size);
				}else{
					printf("Vui long chon 1 !\n");
				}
				break;
			case 4 :
				if(hasPick1){
					sum(list, &size);
				}else{
					printf("Vui long chon 1 !\n");
				}
				break;
			case 5 :
				if(hasPick1){
					max = maxArray(list, &size);
					printf("Vay gia tri lon nhat trong mang la: %d \n", max);
				}else{
					printf("Vui long chon 1 !\n");
				}
				break;
			case 6 :
				exit(0);
			default :
				printf("Vui long nhap tu (1 -> 6) !");
		}
	}while (1);
	
	return 0;
}
