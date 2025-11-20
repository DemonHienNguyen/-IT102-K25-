#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// cac bo sung phu 
typedef struct{
	int id;
	char name[50];
	float importPrice;  // gia nhap
	float selling_Price;  // gia ban
	int quantity;
}Product ;


//
void removeBuffer(){
	 int c;
	 while((c = getchar()) != '\n' && c != EOF);
}
void removeNewLine(char *a){
	 size_t len = strlen(a);
	 a[len -1] = '\0';
}
// bo sung phu 

// khai bao bien //
void printMenu();
void printALL(Product **Pt, int *length);
void insertproduct(Product **Pt, int *length);
void importProduct(Product **Pt, int *length, float *revenuePtr);
void UpdateProduct(Product **Pt, int *length);
void sortProductPrice(Product **Pt, int *length, int choice);
void findProduct(Product *Pt, int *length);
void soldProduct(Product **Pt, int *length, float *revenuePtr);
void printDoanhThu(float *result);
// khai bao bien //


// bat dau lam ham !
void insertproduct(Product **Pt, int *length){
	int i, j;
	int index;
	int currentIndex = *length;
	printf("Nhap so luong san pham ma ban co :D: ");
	scanf("%d", &index);
	removeBuffer();
	Product *temp  = (Product*)realloc((*Pt), ((*length) + index) * sizeof(Product));
	*Pt = temp;
	for(i =0; i < index; i++){
		printf("-----------------------------------------------\n");
		printf(">>> Nhap thong tin san pham thu %d <<<\n", i+1);
		printf("-----------------------------------------------\n");
		(*Pt)[i].id = 100 + currentIndex + i; 
		printf("Nhap Ten cua san pham: ");
		fgets((*Pt)[i].name, 50, stdin);
		removeNewLine((*Pt)[currentIndex + i].name);
		printf("Nhap gia Nhap cua ban: ");
		scanf("%f", &(*Pt)[currentIndex + i].importPrice);
		removeBuffer();
		printf("Nhap gia Ban cua ban: ");
		scanf("%f", &(*Pt)[currentIndex + i].selling_Price);
		removeBuffer();
//		printf("Nhap so luong cua san pham: ");
//		scanf("%d", &(*Pt)[currentIndex + i].quantity);
//		removeBuffer();
		(*Pt)[currentIndex + i].quantity = 0;
	}
	(*length) += index;
}
void printALL(Product **Pt, int *length){
	int i;
	if (*length == 0){
		printf("-----------------------------\n");
		printf(">>>>>>> Danh sach trong <<<<<<<\n");
		printf("-----------------------------\n");
	}else{
		printf("\t\t\t\t>>>>Danh sach San pham<<< \n");
		printf("------------------------------------------------------------------------------------------------------------------------\n");
		for(i = 0 ; i  < *length; i++){
		printf("+----------------------------------------------------------------------------------------------------------------------+\n");
		printf("| %-8s: %-3d | %-8s: %-30s | %-7s: %.1f | %-8s: %.1f | %-8s: %-5d |\n",
			"Ma Sp",(*Pt)[i].id, 
			"Ten SP",(*Pt)[i].name,
			"Gia nhap", (*Pt)[i].importPrice, 
			"Gia Ban", (*Pt)[i].selling_Price,
			"So luong", (*Pt)[i].quantity);
		printf("+----------------------------------------------------------------------------------------------------------------------+\n");
	}
	}
}
void importProduct(Product **Pt, int *length, float *revenuePtr){
	int i;
	char newProduct[50];
	int addQuantity;
	int findIndex;
	printf(">>> Nhap san pham <<< \n");
	printf(">>> Nhap ten san pham vao: ");
	fgets(newProduct, 50, stdin);
	removeNewLine(newProduct);
	findIndex = -1;
	for(i = 0; i < *length; i++){
		if(strcmp((*Pt)[i].name, newProduct) == 0){
			findIndex = i;
			break;
		}
	}
	if(findIndex != -1){
		printf("Da tim thay %s con o trong kho voi so luong %d",newProduct,(*Pt)[findIndex].quantity);
		printf("Nhap so luong ban muon them: ");
		scanf("%d", &addQuantity);
		( (*Pt)[findIndex].quantity ) += addQuantity;
		*revenuePtr -=  ( addQuantity * (*Pt)[findIndex].importPrice);
		printf("Them san luong thanh cong ! \n");
	}else{
		Product *temp = (Product*)realloc((*Pt),((*length) + 1) * sizeof(Product));
		*Pt = temp;
		for(i = *length; i > 0; i--){
			(*Pt)[i] = (*Pt)[i-1]; 
		}
		strcpy((*Pt)[0].name, newProduct);
		printf("Nhap ID Moi: ");
		scanf("%d", &(*Pt)[0].id);
		removeBuffer();
		printf("Nhap gia Nhap cua ban: ");
		scanf("%f", &(*Pt)[0].importPrice);
		removeBuffer();
		printf("Nhap gia Ban cua ban: ");
		scanf("%f", &(*Pt)[0].selling_Price);
		removeBuffer();
		printf("Nhap so luong ma ban muon them: ");
		scanf("%d", &(*Pt)[0].quantity);
		removeBuffer();
		*revenuePtr -=  ( (*Pt)[0].quantity * (*Pt)[0].importPrice);
		(*length)++;
	}
	
}
void UpdateProduct(Product **Pt, int *length){
	int i, findIndex;
	int updateID;
	char newProduct[50];
	printf("Vui long nhap ma Sp can cap nhap: ");
	scanf("%d", &updateID);
	removeBuffer();
	findIndex = -1;
	for(i = 0; i < *length ; i++){  
		if((*Pt)[i].id  == updateID){
			findIndex = i;
			break;
		}
	}
	if(findIndex != -1){
		printf("Ten SP: %s | Gia Nhap: %.f | Gia Ban : %.1f | So Luong: %d |\n", (*Pt)[findIndex].name, (*Pt)[findIndex].importPrice, (*Pt)[findIndex].selling_Price, (*Pt)[findIndex].quantity);
		printf(">>>Cap nhap thong tin moi cho SP %d \n", 100 + findIndex);
//		printf("Vui long Nhap Ma Sach Moi:");
//		scanf("%d", &(*Pt)[findIndex].id);
//		removeBuffer();
		printf("Nhap ten cua San pham moi : ");
		fgets(newProduct, 50, stdin);
		removeNewLine(newProduct);
		strcpy((*Pt)[findIndex].name, newProduct);
		printf("Nhap Gia nhap moi: ");
		scanf("%f", &(*Pt)[findIndex].importPrice);
		removeBuffer();
		printf("Nhap Gia ban moi: ");
		scanf("%f", &(*Pt)[findIndex].selling_Price);
		removeBuffer();
		printf("Cap nhap thanh cong ! \n");
	}else{
		printf("Khong tim thay duoc ma sach ! \n");
	}
}
void sortProductPrice(Product **Pt, int *length, int choice){
	int i, j;
	Product temp;
	if(choice == 1){
		for(i = 0; i < (*length) -1 ;i ++){
			for(j = 0; j <(*length) - i - 1; j++){
				if((*Pt)[j].selling_Price < (*Pt)[j+1].selling_Price){
					temp = (*Pt)[j];
					(*Pt)[j] = (*Pt)[j +1];
					(*Pt)[j +1] = temp;
				}
			}
		}
		printf("Sap xep thanh cong !");
	}else if(choice == 2){
		for(i = 0; i < (*length) -1 ;i ++){
			for(j = 0; j <(*length) - i - 1; j++){
				if((*Pt)[j].selling_Price > (*Pt)[j+1].selling_Price){
					temp = (*Pt)[j];
					(*Pt)[j] = (*Pt)[j +1];
					(*Pt)[j +1] = temp;
				}
			}
		}
		printf("Sap xep thanh cong !");
	}else if(choice == 3){
		printf("Cam on Vi Da Den :D \n");
	}
	
	
}
void findProduct(Product *Pt, int *length){
	int i;
	char findName[50];
	int findIndex;
	printf("Nhap ten ma ban muon tim: ");
	fgets(findName, 50, stdin);
	removeNewLine(findName);
	findIndex = -1;
	for(i = 0; i < *length; i++){
		if(strcmp(Pt[i].name, findName) == 0){
			findIndex = i;
			break;
		}
	}
	if(findIndex != -1){
		printf(">>> Da tim thay ! \n");
		printf("------------------------------------------------------------------------------------------------------\n");
		printf("|Ma SP: %d | Ten SP: %s | Gia Nhap: %.1f | Gia Ban : %.1f | So Luong: %d |\n",Pt[findIndex].id ,Pt[findIndex].name, Pt[findIndex].importPrice, Pt[findIndex].selling_Price, Pt[findIndex].quantity);
		printf("------------------------------------------------------------------------------------------------------\n");
		printf("xuat hien o vi tri thu %d", findIndex + 1);
	}else{

		printf("Khong tim thay ten %s trong danh sach !", findName);
	}
	
}
void soldProduct(Product **Pt, int *length, float *revenuePtr){
	int i;
	char findName[50];
	int findIndex;
	int soldQuatity;
	printf("Nhap ten ma ban muon tim: ");
	fgets(findName, 50, stdin);
	removeNewLine(findName);
	findIndex = -1;
	for(i = 0; i < *length; i++){
		if(strcmp((*Pt)[i].name, findName) == 0){
			findIndex = i;
			break;
		}
	}
	if(findIndex != -1){
		printf(">>> Da tim thay ! \n");
		printf("------------------------------------------------------------------------------------------------------\n");
		printf("|Ma SP: %d | Ten SP: %s | Gia Nhap: %.1f | Gia Ban : %.1f | So Luong: %d |\n",(*Pt)[findIndex].id ,(*Pt)[findIndex].name, (*Pt)[findIndex].importPrice, (*Pt)[findIndex].selling_Price, (*Pt)[findIndex].quantity);
		printf("------------------------------------------------------------------------------------------------------\n");
		printf("xuat hien o vi tri thu %d \n", findIndex + 1);
		printf("Nhap so luong ma ban can ban: ");
		scanf("%d", &soldQuatity);
		removeBuffer();
		if(soldQuatity <= (*Pt)[findIndex].quantity){
			(*Pt)[findIndex].quantity = (*Pt)[findIndex].quantity - soldQuatity;
			*revenuePtr += soldQuatity  * (*Pt)[findIndex].selling_Price;
			printf("Ban thanh cong ! \n");
		}else if ((*Pt)[findIndex].quantity == 0){
			printf("DA HET HANG ! xin vui long khong mua nua !!!\n");
		}else if(soldQuatity > (*Pt)[findIndex].quantity ){
			printf("Hang Ban Qua Muc cho ! Vui long nhap them hang \n");
		}
	}else{
		printf("Khong tim thay ten %s trong danh sach !", findName);
	}
	
}


void printDoanhThu(float *result){
	printf("---------------------------------- \n");
	printf("Vay doanh thu la: %.1f \n", (*result));
	printf("---------------------------------- \n");
}
void printMenu(){
		printf("\n\t\t\t++====================MENU====================++\n");
		printf("\t\t\t||%-44s||\n", "1. Nhap so luong va thong tin san pham");
		printf("\t\t\t||%-44s||\n", "2. Hien thi thong tin san pham");
		printf("\t\t\t||%-44s||\n", "3. Nhap san pham");
		printf("\t\t\t||%-44s||\n", "4. Cap nhap thong tin san pham");
		printf("\t\t\t||%-44s||\n", "5. Sap xep sach theo gia");
		printf("\t\t\t||%-44s||\n", "6. tim kiem theo san pham");
		printf("\t\t\t||%-44s||\n", "7. Ban san pham");
		printf("\t\t\t||%-44s||\n", "8. Doanh thu hien tai");
		printf("\t\t\t||%-44s||\n", "9. Thoat");
		printf("\t\t\t++============================================++\n");
		printf("-------- Lua chon cua ban: ");
}

int main(){
	int choice, sortChoice;
	int hasPickl = 0;
	float revenue = 0; // doanh thu
	int size = 0;
	Product *menuPt = (Product*)malloc(size * sizeof(Product)); // cap phat bo nho
	if(menuPt == NULL){
		printf("Cap phat that bai !\n");
	}else{
		printf("Cap phat thanh cong !\n");
	} 
	do{
		printMenu();
		scanf("%d", &choice);
		removeBuffer();
		switch(choice){
			case 1 :{
				insertproduct(&menuPt, &size);
				hasPickl = 1;
				break;
			}
			case 2 :{
				printALL(&menuPt, &size);
				break;
			}
			case 3 :{
				if(hasPickl){
					importProduct(&menuPt, &size, &revenue);
				}else{
					printf("Vui long Nhap so luong va thong tin truoc khi chon chuc nang duoi ! \n");
				}
				
				break;
			}
			case 4 :{
				if(hasPickl){
					UpdateProduct(&menuPt, &size);
				}else{
					printf("Vui long Nhap so luong va thong tin truoc khi chon chuc nang nay ! \n");
				}
					
				break;
			}
			case 5:{
				printf("\t\t\t++====================MENU SAP XEP====================++\n");
				printf("\t\t\t||%-52s||\n", "1. Giam dan theo price");
				printf("\t\t\t||%-52s||\n", "2. Tang dan theo price");
				printf("\t\t\t||%-52s||\n", "3. Thoat");
				printf("\t\t\t++====================================================++\n");
				printf("-------- Lua chon cua ban: ");
				scanf("%d", &sortChoice);
				removeBuffer();
				sortProductPrice(&menuPt, &size, sortChoice);
				break;
			}
			case 6 :{
				if(hasPickl){
					findProduct(menuPt, &size);
				}else{
					printf("Vui long Nhap so luong va thong tin truoc khi chon chuc nang nay ! \n");
				}
				break;
			}
			case 7 :{
				if(hasPickl){
					soldProduct(&menuPt, &size, &revenue);
				}else{
					printf("Vui long Nhap so luong va thong tin truoc khi chon chuc nang nay ! \n");
				}
				

				break;
			}
			case  8 :
				printDoanhThu(&revenue);
				break;
			case 9 :{
				free(menuPt);
				exit(0);
			}
		}
	}while(1);
	
	return 0;
}
