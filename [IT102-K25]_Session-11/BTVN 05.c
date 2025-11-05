#include <stdio.h>
#include <string.h>

int main(){

	int i, j;
	int originalSize, searchSize;
	int is_Match_Flag, found_Index = -1;
	
printf("nhap so ky tu trong chuoi goc: ");
scanf("%d", &originalSize);

char originalArr[originalSize];

for(i =0; i < originalSize; i++){
	fflush(stdin);
	printf("originalArr [%d] = ", i);
	scanf("%c", &originalArr[i]);
}
		
printf("nhap so ky tu trong chuoi tim kiem: ");
scanf("%d", &searchSize);

char searchArr[searchSize];

for(i =0; i < searchSize; i++){
	fflush(stdin);
	printf("originalArr [%d] = ", i);
	scanf("%c", &searchArr[i]);
}


for(i = 0; i <  originalSize; i++ ){
	is_Match_Flag = 1;
	for(j = 0; j < searchSize; j++){
		if(originalArr[i+j] != searchArr[j]){
			is_Match_Flag = 0;
			break;
		}
	}
	if(is_Match_Flag == 1){
		found_Index = i;
		break;
	}
	
}
printf("\n---KET QUA---\n");
if(found_Index != -1){
	printf("tim thay ");
	for(i = 0; i < searchSize;i++){
		printf("%c", searchArr[i]);
	}
	printf(" chuoi bat dau o chi so %d", found_Index );
}else{
	printf("khong tim thay chuoi tuong ung !");
}
	
	


	
	
	
}
