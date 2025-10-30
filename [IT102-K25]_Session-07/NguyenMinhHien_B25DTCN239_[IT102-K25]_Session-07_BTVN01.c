#include <stdio.h>

int main (){
	
	int Dem_chan = 0, Dem_le = 0, N, i;
	
	printf("---DEM CHAN VOI LE---- \n");
	
	
do{
	printf("nhap so nguyen (tu 1 - 1000): ");
	
	if(scanf("%d", &N) != 1){
		
		printf("So nhap khong hop le vui long nhap lai: \n ");
		N =0;
	}
	}while (getchar() != '\n');
	
	
	for (i = 1; i <= N ; i++){
		if (i % 2 == 0){
			Dem_chan++;
		}else{
			Dem_le++;
		}
		}
	printf("\nVay so chan trong N la: %d \n", Dem_chan);
	printf("Vay so Le trong N la: %d \n", Dem_le);
	printf("DEMON_IS_NOT_FUN :)");
	
	
	
	return 0;
}
