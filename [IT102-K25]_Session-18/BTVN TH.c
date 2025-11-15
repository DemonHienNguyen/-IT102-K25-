#include <stdio.h>
#include <stdlib.h>

void addValue(int *arrPtr, int *lengthPtr, int *indexPtr, int *valuePtr);
void deleteValue(int*arrPtr, int *lengthPtr, int *indexPtr);
void printArray(int *arrPtr, int *lengthPtr);
void update(int *arrPtr, int*indexPtr, int*valuePtr);



void addValue(int *arrPtr, int *lengthPtr, int *indexPtr, int *valuePtr){
	int i;
	for(i = *lengthPtr; i >= *indexPtr; i--){
		*(arrPtr + 1 + i) = *(arrPtr + i);
	}
	*(arrPtr + *indexPtr) = *valuePtr;
	(*lengthPtr)++;
}
void printArray(int *arrPtr, int *lengthPtr){
	int i;
	printf("\t\tVay mang la: \n");
	printf("\t\t ");
	for(i = 0;i < *lengthPtr; i++){
		printf("  %d", *(arrPtr + i));
	}
	printf("\n\n");
}
void deleteValue(int*arrPtr, int *lengthPtr, int *indexPtr){
	int i;
	for(i = *indexPtr; i < *lengthPtr; i++){
		*(arrPtr + i) = *(arrPtr + i + 1);
	}
	(*lengthPtr)--;
}
void update(int *arrPtr, int*indexPtr, int*valuePtr){
	*(arrPtr + *indexPtr) = *valuePtr;
}



int main(){
	
	int addIndex, addNumber;
	int deleteIndex;
	int updateIndex, updateValue;
	
	int choice, i;
	int size;
	do{
		printf("Enter your size: ");
		if(scanf("%d", &size) != 1){
			printf("Loi ! Vui long nhap lai ! \n");
			size = 0;
			while(getchar() != '\n');
			continue;
		}else{
			while(getchar() != '\n');
			if(size <= 0){
				printf("Kich co phai lon hon 0 ! \n");
			}
		}
	}while(size <=0);
	int arr[100];
	printf("Enter your Element in Array: \n");
	for(i= 0; i < size;i ++){
		printf("Array[%d] = ", i);
		scanf("  %5d", arr + i);
	}
	do{
		printf("\t\t+==========MENU==========+\n");
		printf("\t\t|%-21s \t |\n", "1. Them phan tu");
		printf("\t\t|%-21s \t |\n", "2. Xoa phan tu");
		printf("\t\t|%-21s \t |\n", "3. Cap nhap phan tu");
		printf("\t\t|%-21s \t |\n", "4. Hien thi mang");
		printf("\t\t|%-21s \t |\n", "5. Thoat");
		printf("\t\t+========================+\n\n");
		printf("\t\t---Lua chon cua ban: ");
		scanf("%d", &choice);
		switch(choice){
			case 1 :{
				printf("Nhap chi so ma ban muon chen (0 -> %d): ", size);
				do{
					scanf("%d", &addIndex);
					if(addIndex < 0 || addIndex > size){
						printf("Loi ! Vui long nhap lai: ");
					}
				}while(addIndex < 0 || addIndex > size);
				printf("Nhap gia tri can them vao mang: ");
				scanf("%d", &addNumber);
				addValue(arr,&size,&addIndex,&addNumber);
				printf("them thanh cong! \n");
				break;
			}
			case 2 :{
				printf("Nhap chi so ma ban muon xoa (0 -> %d): ", size);
				do{
					scanf("%d", &deleteIndex);
					if(deleteIndex < 0 || deleteIndex > size){
						printf("Loi ! Vui long nhap lai: ");
					}
				}while(deleteIndex < 0 || deleteIndex > size);
				deleteValue(arr,&size,&deleteIndex);
				printf("Xoa thanh cong! \n");
				break;
			}
			case 3 :{
				printf("Nhap chi so ma ban muon cap nhap (0 -> %d): ", size -1);
				do{
					scanf("%d", &updateIndex);
					if(updateIndex < 0 || updateIndex >= size){
						printf("Loi ! Vui long nhap lai: ");
					}
				}while(updateIndex < 0 || updateIndex >= size);
				printf("Nhap gia tri can cap nhap vao mang: ");
				scanf("%d", &updateValue);
				
				
				update(arr,&updateIndex,&updateValue);
				printf("Cap nhap thanh cong! \n");
				break;
			}
			case 4: {
				printArray(arr,&size);
				break;
			}
			case 5: {
				printf("\t\tDemon_Of_Ambittion :) \t\t\n \t\t\tGOODBYE\n");
				exit(0);
			}
			default : {
				printf("Xin vui long nhap tu (1 -> 5) !");
				break;
			}
		}
	}while(1);
	
	
	return 0;
}
