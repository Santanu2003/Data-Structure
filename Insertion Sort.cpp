// Insertion Sort
#include<stdio.h>
#include<stdlib.h>
void insertionSort(int* a,int n){
	for(int i=1;i<=n-1;i++){
		int item=a[i];
		int j=i-1;
		while(j>=0 && item<a[j]){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=item;
	}
}
int main(){
	int n,*a,i;
	printf("Enter the size of the array:");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	printf("Enter the element of the array:");
	for(i=0;i<n;i++){
		scanf("%d",a+i);
	}
	insertionSort(a,n);
	printf("After sorting the array is: ");
	for(i=0;i<n;i++){
		printf("%d\t",*(a+i));
	}
	return 0;
}
