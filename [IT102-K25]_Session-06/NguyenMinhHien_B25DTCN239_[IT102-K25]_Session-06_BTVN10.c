#include <stdio.h>
#include <math.h>

int main(){
	
	long long Number1,Number2, i, Reversed_Num =0, So;
	int Dem0;

	
	printf("---IN TUNG CHU SO CUA MOT SO NGUYEN--- \n");

do{
	printf("---nhap mot so nguyen bat ky: ");
	
	if(scanf("%lld",&Number1) != 1){
		printf(" Loi: nhap so nguyen khong hop le ! \n");
	}
}while(getchar() !=  '\n');

if (Number1 > 0){
	Number2 = Number1;
}else{
	Number2 = -Number1;
}
do{
		So = Number2 % 10;
		if(So ==0 && Reversed_Num ==0 ){
		Dem0++;
		}else{
		Reversed_Num = Reversed_Num * 10 + So;
		}
		Number2 /= 10;
}while (Number2 >0);

	printf(" chu so in tung chu la: \n");
	while(Reversed_Num > 0){
		i = Reversed_Num % 10;
		printf(" %lld ", i);
		Reversed_Num /= 10;
	}
	for ( i= 0; i < Dem0; i++){
		printf(" 0 ");
	}


	return 0;
}
