# include <stdio.h>

int main (){
	printf("---BANG CUU CHUONG--- \n");
	int N;
	int i;
	do{
		printf(" vui long nhap mot so nguyen duong (tu 1 den 10): ");
		if (scanf(" %d", &N) != 1){
			printf("Loi: Dau vao khong phai la so nguyen, vui long nhap lai: \n");
			while (getchar() != '\n');
			N =0;
		}else if (N < 1 || N > 10) {
            printf("Loi: So ban nhap (%d) nam ngoai pham vi cho phep (1 den 10). Vui long nhap lai.\n", N);
        }
        } while (N < 1 || N > 10);
    	printf("\n--- BANG CUU CHUONG CUA SO %d ---\n", N);
    	for (i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", N, i, N * i);
    }

    return 0;
}

