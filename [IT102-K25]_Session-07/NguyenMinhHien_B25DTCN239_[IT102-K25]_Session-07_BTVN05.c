#include <stdio.h>
#include <math.h> 

int countDigits(int n) {
    if (n == 0) return 1;
    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

void kiemTraArmstrong() {
    int Number, Goc_Num;
    int So_Chu_So, Tong_Luy_Thua = 0;
    int chu_so_rieng;

    do {
        printf("\nNhap so Nguyen Duong: ");
        if (scanf("%d", &Number) != 1) {
            printf("----So khong hop le! Vui long nhap lai.\n");
            while (getchar() != '\n'); 
            continue;
        }
        while (getchar() != '\n'); 

        if (Number <= 0) {
            printf("----So phai la so Nguyen Duong! Nhap lai.\n");
        }
    } while (Number <= 0);

    Goc_Num = Number;
    So_Chu_So = countDigits(Number);

    int temp_num = Number;
    while (temp_num > 0) {
        chu_so_rieng = temp_num % 10;
        Tong_Luy_Thua += (int)round(pow(chu_so_rieng, So_Chu_So)); 
        temp_num /= 10;
    }

    printf("So ban vua nhap: %d\n", Goc_Num);
    
    if (Goc_Num == Tong_Luy_Thua) {
        printf("----So %d la so AMSTRONG (Bac %d)!\n", Goc_Num, So_Chu_So);
    } else {
        printf("----So %d KHONG phai la so Amstrong.\n", Goc_Num);
    }
}


int main(){
    int Choice;

    printf("---KIEM TRA SO AMSTRONG---\n");

    do {
        printf("\n1. Kiem tra so \n");
        printf("2. Thoat \n");
        printf("\nlua chon cua ban: ");
        
        if (scanf("%d", &Choice) != 1) {
            printf("Loi nhap! Vui long nhap 1 hoac 2.\n");
            Choice = 0; 
            while (getchar() != '\n'); 
        }
        while (getchar() != '\n' && Choice != 0); 

        switch (Choice) {
            case 1:
                kiemTraArmstrong();
                break;
            case 2:
                printf("Tam biet!\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (Choice != 2); 

    return 0;
}
