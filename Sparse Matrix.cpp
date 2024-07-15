// Sparse Matrix using DMA
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int m,n,i,j,f=0,s;
	int** ptr;
	int** arr;
	printf("Enter the no of row and columns:");
	scanf("%d%d",&m,&n);
	ptr= (int**)malloc(m*sizeof(int*));
	for(i=0;i<m;i++)
	{
		*(ptr+i)=(int*)malloc(n*sizeof(int));
	}
	/* Scan the matrix */
	printf("Enter the element of matrix:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",(*(ptr+i)+j));
		}
	}
	/* Print the matrix */
	printf("The matrix is:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",*(*(ptr+i)+j));
		}
		printf("\n");
	}
	/* Check it is a sparse matrix or not */
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(*(*(ptr+i)+j)==0)
				f+=1;
		}
	}
	if(f>(m*n/2))
	{
		s=1;
		printf("It is a sparse matrix!!\n");
	}
	else
	{
		s=0;
		printf("It is not a sparse matrix !!\n");
	}
	/* Efficient Representation */
	arr=(int**)malloc(m*sizeof(int*));
	for(i=0;i<m;i++)
	{
		*(arr+i)=(int*)malloc(3*sizeof(int));
	}
	for(i=0;i<=(m*n-f);i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==0)
			{
				if(j==0)
					*(*(arr+i)+j)=m;
				else if(j==1)
					*(*(arr+i)+j)=n;
				else
					*(*(arr+i)+j)=m*n-f;
			}
			else
			{
				if(*(*(ptr+i-1)+j-1)!=0)
				{
					if(j==0)
						*(*(arr+i)+j)=i;
					else if(j==1)
						*(*(arr+i)+j)=j;
					else
						*(*(arr+i)+j)=*(*(ptr+i)+j);
				}
			}	
		}
	}
	/* Print the efficient representation */
	for(i=0;i<=(m*n-f);i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",*(*(arr+i)+j));
		}
		printf("\n");
	}
	return 0;
}
