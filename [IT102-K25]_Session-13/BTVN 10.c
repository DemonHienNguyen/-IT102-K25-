#include <stdio.h>
#include <stdlib.h>

int choice, hasPick1 = 0, foundChoice, isFound, sortChoice, isSort = 0;;
int arr[100];
int size, currnentIndex = 0;


void insertArray();
void printArray();
void addArray();
void updateArray();
void deleteArray();
void sortArray();
void findArray();


void insertArray(){
	int i;
	
	printf("Nhap kich thuoc: ");
do{
	if(scanf("%d", &size) != 1){
		printf("Loi ! Vui long nhap lai: ");
		while(getchar() != '\n');
		continue;
	}
	while(getchar() != '\n');
	if(size <=0){
		printf("Loi ! Vui long nhap lai: ");
	}
}while(size <=0);
	for(i = 0; i < size; i++){
		printf("Array[%d] = ",currnentIndex);
		scanf("%d",&arr[currnentIndex]);
		currnentIndex++;
	}
}
void printArray(){
	int i;
	printf("Vay mang la: \n");
	for(i=0;i<currnentIndex;i++){
		printf("\t%5d",arr[i]);
	}
}
void addArray(){
	int i;
	int addIndex, addNumber;
	printf("Nhap chi so can duoc them vao(0 -> %d): ", size );
	scanf("%d", &addIndex);
	printf("Nhap gia tri can them vao: ");
	scanf("%d", &addNumber);
	for(i = currnentIndex; i>= addIndex; i--){
		arr[i+1] = arr[i];
	}
	arr[addIndex] = addNumber;
	currnentIndex++;
	printf("Them thanh cong ! \n");
}
void updateArray(){
	int updateIndex, updateNumber;
	printf("Nhap chi so can cap nhap (0 -> %d): ", currnentIndex -1);
	scanf("%d", &updateIndex);
	printf("Nhap Gia tri can cap nhap: ");
	scanf("%d", &updateNumber);
	arr[updateIndex] = updateNumber;
	printf("Cap nhap thanh cong ! \n");
}
void deleteArray(){
	int i, deleteIndex;
	printf("Nhap chi so can xoa (0-> %d): ", currnentIndex-1);
	scanf("%d", &deleteIndex);
	for(i = deleteIndex; i < currnentIndex; i ++){
		arr[i] = arr[i+1];
	}
	currnentIndex--;
	printf("Xoa thanh cong ! \n");
}
void sortArray(){
	int i, j; 
	int temp;
	if(sortChoice == 1){
		for(i= 0; i <currnentIndex-1; i++){
			for(j = 0; j < currnentIndex - i - 1; j++){
				if(arr[j] < arr[j+1]){
					temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}
			}
		}
		isSort = 1;
	}else if(sortChoice == 2){
		for(i= 0; i <currnentIndex-1; i++){
			for(j = 0; j < currnentIndex - i - 1; j++){
				if(arr[j] > arr[j+1]){
					temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}
			}
		}
	}
	isSort = 1;
	printf("Sap xep thanh cong !");
}
void findArray(){
	int i, left, right, mid, searchValue;
	if(isSort && foundChoice == 2){
		isFound = 0;
		left = 0; right = currnentIndex -1;
		printf("Nhap gia tri can tim: ");
		scanf("%d", &searchValue);
		while(left <= right){
			mid = left + (right - left)/2;
			if(arr[mid] == searchValue){
				isFound = 1;
				break;
			}else if(arr[mid] > searchValue){
				right = mid - 1;
			}else if(arr[mid] < searchValue){
				left = mid + 1;
			}
		}
		if(isFound){
			printf("Vay tim thay %d o vi tri %d \n",searchValue, mid);
		}else{
			printf("Khong co gia tri can tim ! \n");
		}
	}else if(!isSort && foundChoice == 1){
		isFound = 0;
		printf("Nhap gia tri can tim: ");
		scanf("%d", &searchValue);
		for (i = 0;i<currnentIndex; i++){
			if(arr[i] == searchValue){
				isFound = 1;
				break;
			}
		}
		if(isFound){
			printf("Vay tim thay %d o vi tri %d \n",searchValue, i);
		}else{
			printf("Khong co gia tri can tim ! \n");
		}
	}else{
		printf("Vui long (phai Sap xep roi dung nhi phan) HOAC (khong sap xep thi dung tuyen tinh) ! \n");
	}
}



int main(){

do{
	printf("\n\t_____________MENU_____________\n");
	printf("\t1. Nhap gia tri cac phan tu cua mang\n");
	printf("\t2. In gia tri cac phan tu \n");
	printf("\t3. Them phan tu vao vi tri chi dinh\n");
	printf("\t4. Sua mot phan tu o vi tri bat ky\n");
	printf("\t5. xoa phan tu o vi tri chi dinh\n");
	printf("\t6. sap xep cac phan tu\n");
	printf("\t7. Tim kiem phan tu nhap vao\n");
	printf("\t8. Thoat\n");
	printf("\tNHAP LUA CHON CUA BAN: ");
	scanf("%d", &choice);
		switch(choice){
			case 1 : 
				insertArray();
				hasPick1 = 1;
				break;
			case 2 :
				if(hasPick1){
					printArray();
				}else{
					printf("Vui long nhap cac phan tu vao truoc ! \n");
				}
				break; 
			case 3 :
				if(hasPick1){
					addArray();
				}else{
					printf("Vui long nhap cac phan tu vao truoc ! \n");
				}
				break;
			case 4 :
				if(hasPick1){
					updateArray();
				}else{
					printf("Vui long nhap cac phan tu vao truoc ! \n");
				}
				break;
			case 5 :
				if(hasPick1){
					deleteArray();
				}else{
					printf("Vui long nhap cac phan tu vao truoc ! \n");
				}
				break;
			case 6 :
				if(hasPick1){
					printf("\n\t_____________MENU SAP XEP_____________\n");
					printf("\t1. Giam dan\n");
					printf("\t2. Tang dan\n");
					printf("\t3. Thoat\n");
					printf("\tNHAP LUA CHON CUA BAN: ");
					scanf("%d", &sortChoice);
					switch(sortChoice){
						case 1 :
							sortArray();
							break;
						case 2 :
							sortArray();
							break;
						case 3 :
							printf("Thoat thanh cong ! \n");
							break;	 
					}
				}else{
					printf("Vui long nhap cac phan tu vao truoc ! \n");
				}
				break;
			case 7 :
				if(hasPick1){
					printf("\n\t_____________MENU TIM KIEM_____________\n");
					printf("\t1. Tim kiem tuyen tinh\n");
					printf("\t2. Tim kiem  nhi phan\n");
					printf("\t3. Thoat\n");
					printf("\tNHAP LUA CHON CUA BAN: ");
					scanf("%d", &foundChoice);
					switch(foundChoice){
						case 1 :
							findArray();
							break;s
						case 2 :
							findArray();
							break;
						case 3 :
							printf("Thoat thanh cong ! \n");
							break;	 
					}
				}else{
					printf("Vui long nhap cac phan tu vao truoc ! \n");
				}
				break;
			case 8 :
				exit(0);
			default :
				printf("Vui long nhap lai (1 -> 8): ");
				break;
		}
}while(1);
return 0;
}
