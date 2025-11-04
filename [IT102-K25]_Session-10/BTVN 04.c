#include <stdio.h>

int main(){
	
	int n, i,j ;
	printf("\t---SAP XEP NOI BOT----\n");
	printf("\tnhap so phan tu cua ban: ");
do{
	if(scanf("%d",  &n) != 1 || n <=0){
		printf("Lo! vuilong nhap lai: ");
		while(getchar() != '\n');
	}
}while(n <= 0);

int maTran[n];
int temp;		
int size  = sizeof(maTran)/sizeof(maTran[0]);
	printf("\tnhap cac phan tu: \n");
	for(i = 0; i < size; i++){
		printf("Array[%d] = ", i);
		scanf("%d", &maTran[i]);
	}
printf("\n\tvay mang: \n");
	for(i= 0; i < size; i++){
		printf("\t%d", maTran[i]);
	}
	for(i = 0; i < size-1; i++){
		for(j = 0; j < size-i-1; j++){
			if(maTran[j] > maTran[j+1]){
				temp = maTran[j];
				maTran[j] = maTran[j+1];
				maTran[j+1] = temp;
			}else{
				continue;
			}
		}
	}
	printf("\n\tvay mang sau khi sap  xep la: \n");
	for(i= 0; i < size; i++){
		printf("\t%d", maTran[i]);
	}
return 0; 
}
