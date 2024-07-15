// Radix Sort
#include<stdio.h>
#include<stdlib.h>
void radixsort(int *a,int n){
	int buck[10], bucket[10][n];
	int i,j,k,r,x,y,z;
	int divisor=1;
	int largest,count=0;
	for (i=0;i<n;i++){
		largest=a[i];
		if(a[i+1]>largest)
			largest=a[i+1];
	}
	while(largest!=0){
		largest/=10;
		count++;
	}
	for(i=0;i<count;i++){
		for(j=0;j<10;j++){
			buck[j]=0;
		}
		for(k=0;k<n;k++){
			r=(a[k]/divisor)%10;
			bucket[r][buck[r]]=a[k];
			buck[r]++;
		}
		z=0;
		for(x=0;x<10;x++){
			for(y=0;y<buck[x];y++){
				a[z++]=bucket[x][y];
			}
		}
		divisor*=10;
	}
}
int main(){
	int n,*arr,i;
	printf("Enter the size of the array:");
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",arr+i);
	printf("Before sorting the array is:");
	for(i=0;i<n;i++)
		printf("%d\t",*(arr+i));
	radixsort(arr,n);
	printf("\nAfter sorting the array is:");
	for(i=0;i<n;i++)
		printf("%d\t",*(arr+i));
	return 0;	
}
