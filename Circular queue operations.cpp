// Operations on circular queue Menu driven program
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int front=-1,rear=-1,i;
void insert(int item)
{
	if(front==(rear+1)%MAX)
	{
		printf("Queue overflow!!");
		return;
	}
	if(front==-1)
	{
		front=rear=0;
		queue[rear]=item;
	}
	else
		rear=(rear+1)%MAX;
		queue[rear]=item;
}
void delete_ele()
{
	if(front==-1)
	{
		printf("Queue underflow!!");
		return ;
	}
	if(front==rear)
		front=rear=-1;
	else
		front=(front+1)%MAX;
}
void display()
{
	if(front==-1)
	{
		printf("Queue is empty!!");
		return ;
	}
	if(front<=rear)
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d\t",queue[i]);
		}
	}
	else
	{
		for(i=front;i<=MAX-1;i++)
		{
			printf("%d\t",queue[i]);
		}
		for(i=0;i<=rear;i++)
		{
			printf("%d\t",queue[i]);
	
		}	
	}
}
int main()
{
	int ch;
	do{
		printf("\ninsert=>1\n");
		printf("delete=>2\n");
		printf("display=>3\n");
		printf("exit=>4\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				int item;
				printf("Enter the item to be inserted:");
				scanf("%d",&item);
				insert(item);
				break;
			case 2:
				delete_ele();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Wrong choice!!!");
		}
	}while(1);
	return 0;
}
