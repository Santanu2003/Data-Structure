// Merge Sort
#include<stdio.h>
#include<stdlib.h>
void merge(int* a,int low,int mid,int high){
	int b[high+1];
	int h=low;
	int j=mid+1;
	int i=low;
	while(h<=mid && j<=high){
		if(a[h]<a[j]){
			b[i++]=a[h++];	
		}
		else{
			b[i++]=a[j++];	
		}
	}
	if(h>mid){
		for(int k=j;k<=high;k++){
			b[i++]=a[k];
		}
	}
	else{
		for(int k=h;k<=mid;k++){
			b[i++]=a[k];
		}
	}
	for(int k=low;k<=high;k++)
		a[k]=b[k];
}
void mergesort(int* arr,int low,int high){
	if(low<high){
		int mid=(low+high)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		merge(arr,low,mid,high);
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
	mergesort(arr,0,n-1);
	printf("\nAfter sorting the array is:");
	for(i=0;i<n;i++)
		printf("%d\t",*(arr+i));
	return 0;	
}
