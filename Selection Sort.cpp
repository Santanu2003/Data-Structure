// Selection Sort
#include<stdio.h>
#include<stdlib.h>
void selectionSort(int* a,int n){
	for(int i=0;i<=n-2;i++){
		int smallest=i;
		for(int j=i+1;j<=n-1;j++){
			if(a[j]<a[smallest])
				smallest=j;
		}
		if(smallest!=i){
			int temp=a[smallest];
			a[smallest]=a[i];
			a[i]=temp;
		}
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
	selectionSort(a,n);
	printf("After sorting the array is: ");
	for(i=0;i<n;i++){
		printf("%d\t",*(a+i));
	}
	return 0;
}
