#include <stdio.h>
#include <stdlib.h>
int main() {
	int arr[100], even[100], odd[100], mid[100];
	int n, i, j, choice, sum, max, min, flag, key, m, temp, indexOdd=0, indexMid=0, indexEven=0;
	do{
	printf("************************MENU**************************\n");
	printf("1. Nhap gia tri n phan tu cua mang(n nhap tu ban phim)\n");
	printf("2. in cac gia tri trong mang\n");
	printf("3. tinh tong cac phan tu chia het cho 2 va 3\n");
	printf("4. in ra phan tu lon nhat va nho nhat trong mang\n");
	printf("5. su dung thuat toan sap xep chen sap xep mang tang dan\n");
	printf("6. tinh tong cac phan tu la so nguyen to trong mang\n");
	printf("7. Sap xep các phan tu le chia het cho 5 o dau mang theo thu tu giam dan, cac phan tu chan chia het cho 5 o cuoi mang theo thu tu tang dan,cac phan tu con lai o giua mang theo thu tu giam dan\n");
	printf("8. Nhap gia tri m tu ban phim, chen gia tri m vao mang (sap xep tang dan) dung vi tri\n");
	printf("9. thoat\n");
	printf("nhap lua chon cua ban :\n");
	scanf("%d", &choice);
		switch (choice){
			case 1:
				printf("nhap gia tri n:");
				scanf("%d", &n);
				for(i=0;i<n;i++){
					printf("arr[%d]=", i);
					scanf("%d", &arr[i]);
				}
				printf("\n");
			break;
			case 2:
				printf("cac gia tri trong mang la:\n");
				for(i=0;i<n;i++){
					printf("%d\t", arr[i]);
				}
				printf("\n");
			break;
			case 3:
				sum=0;
				for(i=0;i<n;i++){
					if(arr[i]%6==0){
					sum+=arr[i];
					}
				}
				printf("tong cac so chia het ca 2 va 3 trong mang la:%d\n", sum);
				break;
			case 4:
				max=arr[0];
				for(i=1;i<n;i++){
					max=(max>arr[i]) ? max : arr[i];
				}
				min=arr[0];
				for(i=1;i<n;i++){
					min=(min<arr[i]) ? min : arr[i];
				}
				printf("so lon nhat la:%d\n", max);
				printf("so nho nhat la:%d\n", min);
				printf("\n");
				break;
			case 5:
				for (i=1;i<n;i++){
    				key=arr[i];
   					j = i-1;
    				while(j>=0 && key<arr[j]){ 
     				 	arr [j+1] = arr[j]; 
      					j-=1;
    				}
    			arr [j+1] = key;
  				}
  				printf("Mang sau khi da sap xep tang dan:\n"); 
  				for (int i=0;i<n;i++) {
    				printf("%d\t", arr[i]);
  				}
  				printf("\n");
  				break;
			case 6:
				sum=0;
				for(i=0;i<n;i++){
					flag=0;
					for(j=2;j<arr[i];j++){
						if(arr[i]%j==0){
							flag=1;
							break;
						}
					}
					if(flag==0){
						sum+=arr[i];
					}
				}
				printf("tong cac so nguyen to trong mang la:%d\n", sum);
				break;
			case 7:
				for (int i=0;i<n-1;i++){
   					for(j=0;j<n-i-1;j++){
      					if (arr[j]<arr[j+1]){
        				temp = arr[j];
        				arr[j] = arr [j+1]; 
        				arr[j+1] = temp;
      					}
    				}
 				}
  				for (int i=0;i<n;i++){
  					if(arr[i]%2!=0&&arr[i]%5==0){
    					odd [indexOdd]=arr[i];
    					indexOdd++;
    				}
  				}
  				for (int i=0;i<n;i++){
  					if(arr[i]%5!=0){
    					mid[indexMid]=arr[i];
    					indexMid++;
    				}
  				}
  				for (int i=0;i<n-1;i++){
   					for(j=0;j<n-i-1;j++){
      					if (arr[j]>arr[j+1]){
        				temp = arr[j];
        				arr[j] = arr [j+1]; 
        				arr[j+1] = temp;
      					}
    				}
 				}
 				for (i=0;i<n;i++){
  					if(arr[i]%2==0&&arr[i]%5==0){
    					even [indexEven]=arr[i];
    					indexEven++;
    				}
    			}
  				for(i=0;i<indexOdd;i++){
					printf("%d\t", odd[i]);
				}
				for(i=0;i<indexMid;i++){
					printf("%d\t", mid[i]);
				}
				for(i=0;i<indexEven;i++){
					printf("%d\t", even[i]);
				}
			printf("\n");
			break;
			case 8:
				printf("nhap gia tri m muon them vao mang:");
				scanf("%d", &m);
				arr[n]=m;
				for (int i=0;i<n;i++){
   					for(j=0;j<n-i;j++){
      					if (arr[j]>arr[j+1]){
        				temp = arr[j];
        				arr[j] = arr [j+1]; 
        				arr[j+1] = temp;
      					}
    				}
 				 }
  				printf("Mang sau khi da sap xep tang dan:\n"); 
  				for (int i=0;i<n+1;i++){
    			printf("%d\t", arr[i]);
  				}
  				printf("\n");
  				break;
				
			case 9:
				exit(0);
			default :
				printf("Vui long chon tu 1-9\n");	
		}
	}while (choice!=9);
}
