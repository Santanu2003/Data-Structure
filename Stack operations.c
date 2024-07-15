// Stack
#include<stdio.h>
#include<stdlib.h>
int top=-1,item,n;
int* stack;
void push(int item)
{
	if(top==n-1)
	{
		printf("Stack Overflow!!!");
	}
	top=top++;
	*(stack+top)=item;
}
void pop()
{
	if(top==-1)
	{
		printf("Stack Underflow!!!");
	}
	
	printf("The logically deleted item is %d",*(stack+top));
	top=top--;
}
void display()
{
	if(top==-1)
	{
		printf("Stack is empty!!!");
	}
	for(int i=top;i>=0;i--)
	{
		printf("%d",*(stack+top));
	}
}
int main()
{
	int ch,item;
	stack=(int*)malloc(n*sizeof(int));
	do{
		printf("\n*****Stack*****");
		printf("\nPush->1");
		printf("\nPop->2");
		printf("\nDisplay->3");
		printf("\nExit->4");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the item:");
				scanf("%d",&item);
				push(item);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Bye!!");
				exit(0);
				break;
			default:
				printf("Wrong choice!!!");
		}
	}while(1);
	return 0;
}
