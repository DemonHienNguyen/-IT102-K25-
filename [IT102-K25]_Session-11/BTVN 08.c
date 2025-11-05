# include <stdio.h>



int main(){
	
	int i, j;
	int index;
	
	printf("\tNhap kich thuoc cua mang: ");
do{
	scanf("%d", &index);
	if(index < 0){
		printf("Loi ! Vui long nhap lai: ");
		fflush(stdin);
	}
}while(index<0);

int arr[index];


printf("\tNhap phan tu cua mang: \n");
for(i= 0; i < index; i++){
	printf("Array[%d] = ", i);
	scanf("%d", &arr[i]);
}
for(i=0; i<index; i++){
	printf("\t%5d", arr[i]);
}
// dem lan lap

	int count, maxCount = 0, currentIndex ;
	int soXuatHienNhieuNHat;
	int mangPhu[currentIndex];
	
	for(i= 0; i < index; i++){
		count = 0;
		soXuatHienNhieuNHat = arr[i];	
		for(j = 0; j < index; j++){
			if(arr[i] == arr[j]){
				count++;
			}
		}
		if(count > maxCount){
			maxCount = count;
			currentIndex = 0;
			mangPhu[currentIndex] = soXuatHienNhieuNHat;
			currentIndex++;
		}else if(count == maxCount){
			int Exist = 0;
			for(i = 0; i < index; i++){
				if(mangPhu[i] == arr[i]){
					Exist = 1;
				}
			}
			if(Exist){
				mangPhu[currentIndex] = soXuatHienNhieuNHat;
				currentIndex++;
			}
		}
	}
printf("\nVay so %d xuat hien nhieu nhat voi tan so : %d", mangPhu[0], count);
	
	
	
	
}
