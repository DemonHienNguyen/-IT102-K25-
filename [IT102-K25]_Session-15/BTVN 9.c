#include <stdio.h>
#include <limits.h>

void least_Appearing_Number(int N, int Array[]);

void least_Appearing_Number(int N, int Array[]){

	int i, j, k, leastAppearingNum, count, minCount = INT_MAX;
	int list[100], currentIndex;
	for(i= 0; i < N; i++){
		count = 0;
		leastAppearingNum = Array[i];
		for(j = 0;j<N; j++){
			if(Array[j] == leastAppearingNum){
				count++;
			}
		}
		if(count < minCount){
			minCount = count;
			currentIndex = 0;
			list[currentIndex] = leastAppearingNum;
			currentIndex++;
		}else if (count == minCount){
			int tonTai = 0;
			for(k = 0; k < currentIndex; k++){
				if(list[k] == leastAppearingNum){
					tonTai = 1;
					break;
				}
			}
			if(!tonTai){
				list[currentIndex] = leastAppearingNum;
				currentIndex++;
			}	
		}
	}
	printf("Vay cac so xuat hien it nhat la: \n");
	for(i=0; i<currentIndex; i++){
		printf("\t%5d", list[0]);
	}
}

int main(){
	int size, i;
	printf("Nhap kich thuoc cua ban: ");
	scanf("%d", &size);
	int maTran[size];
	printf("Nhap phan tu trong mang: \n");
	for(i =0; i< size; i++){
		printf("Array[%d] = ", i);
		scanf("%d", &maTran[i]);
	}
	
	least_Appearing_Number(size, maTran);
	
	return 0;
}

