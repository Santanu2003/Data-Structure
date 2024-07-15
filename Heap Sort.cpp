// Heap Sort
#include<stdio.h>
#include<stdlib.h>
void maxheap(int *a,int i,int n){
	int l=2*i+1;
	int r=2*i+2;
	int largest=i;
	if(l<n && a[l]>a[i])
		largest=l;
	if(r<n && a[r]>a[largest])
		largest=r;
	if(largest!=i){
		int temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		maxheap(a,largest,n);
	}
}
void heapify(int *a,int n){
	int i;
	for(i=n/2-1;i>=0;i--){
		maxheap(a,i,n);
	}
}
void heapsort(int *a, int n){
	heapify(a,n);
	for(int i=n-1;i>=1;i--){
		int temp=a[i];
		a[i]=a[0];
		a[0]=temp;
		maxheap(a,0,i);
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
	heapsort(arr,n);
	printf("\nAfter sorting the array is:");
	for(i=0;i<n;i++)
		printf("%d\t",*(arr+i));
	return 0;	
}
