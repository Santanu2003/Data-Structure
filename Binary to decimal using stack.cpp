// Binary to decimal using stack
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int top=-1,stack[MAX];
void push(int r)
{
	if(top==MAX-1)
	{
		printf("Stack Overflow!!");
		return;
	}
	top++;
	stack[top]=r;	//0		0	1	1
}
int pop()
{
	if(top==-1)
	{
		printf("Stack Underflow!!");
		return 0;
	}
	int b=stack[top];
	top--;
	return b;
}
int main()
{
	int n,r;
	printf("Enter a decimal no:");	
	scanf("%d",&n);	//12
	int t=n;
	while(n!=0)		
	{
		r=n%2;	//	0	0	1	1
		push(r);	
		n/=2;
	}
	printf("The binary equivalent of %d is ",t);
	while(top!=-1)
	{
		printf("%d",pop());
	}
	return 0;
}
