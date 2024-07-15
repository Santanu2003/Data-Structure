// Operations on priority queue using linear queue Menu driven program
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int front=-1,rear=-1,i,j;
void insert(int item)
{
	if(rear==MAX-1)
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
		queue[++rear]=item;
	for(i=front;i<rear;i++)
	{
		for(j=i+1;j<=rear;j++)
		{
			if(queue[i]>queue[j])
			{
				int temp=queue[i];
				queue[i]=queue[j];
				queue[j]=temp;
			}
		}
	}
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
		front+=1;
}
void display()
{
	if(front==-1)
	{
		printf("Queue is empty!!");
		return ;
	}
	for(i=front;i<=rear;i++)
	{
		printf("%d\t",queue[i]);
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
