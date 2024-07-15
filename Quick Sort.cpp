// Quick Sort
#include<stdio.h>
#include<stdlib.h>
void swap(int* p,int* q){
	int temp=*p;
	*p=*q;
	*q=temp;
}
int partition(int* a,int low,int high){
	int pivot=a[low];
	int j=low,i=low+1;
	while(i<=high){
		if(a[i]>pivot)
			i++;
		else{
			j++;
			swap(&a[i],&a[j]);
			i++;
		}	
	}
	swap(&a[j],&a[low]);
	return j;
}
void quicksort(int* arr,int low,int high){
	int j;
	if(high>low){
		j=partition(arr,low,high);
		quicksort(arr,low,j-1);
		quicksort(arr,j+1,high);
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
	quicksort(arr,0,n-1);
	printf("\nAfter sorting the array is:");
	for(i=0;i<n;i++)
		printf("%d\t",*(arr+i));
	return 0;	
}
