// Operations on deque Menu driven program
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int front=-1,rear=-1,i;
void insert_at_rear(int item)
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
void insert_at_front(int item)
{
	if(front==(rear+1)%MAX)
	{
		printf("Queue overflow!!");
		return;
	}
	if(front==-1)
	{
		front=rear=0;
		queue[front]=item;
	}
	else
		front=(front+MAX-1)%MAX;
		queue[front]=item;
}
void delete_ele_at_front()
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
void delete_ele_at_rear()
{
	if(front==-1)
	{
		printf("Queue underflow!!");
		return ;
	}
	if(front==rear)
		front=rear=-1;
	else
		rear=(rear+MAX-1)%MAX;
}
void display1()
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
void display2()
{
	if(front==-1)
	{
		printf("Queue is empty!!");
		return ;
	}
	if(front<=rear)
	{
		for(i=rear;i>=front;i--)
		{
			printf("%d\t",queue[i]);
		}
	}
	else
	{
		for(i=0;i<=rear;i++)
		{
			printf("%d\t",queue[i]);
	
		}
		for(i=MAX-1;i>=front;i--)
		{
			printf("%d\t",queue[i]);
		}
			
	}
}
int main()
{
	int ch,item;
	do{
		printf("\ninsert_at_rear=>1\n");
		printf("insert_at_front=>2\n");
		printf("delete_at_front=>3\n");
		printf("delete_at_rear=>4\n");
		printf("display1=>5\n");
		printf("display2=>6\n");
		printf("exit=>7\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the item to be inserted:");
				scanf("%d",&item);
				insert_at_rear(item);
				break;
			case 2:
				printf("Enter the item to be inserted:");
				scanf("%d",&item);
				insert_at_front(item);
				break;
			case 3:
				delete_ele_at_front();
				break;
			case 4:
				delete_ele_at_rear();	
				break;
			case 5:
				display1();
				break;
			case 6:
				display2();
				break;
			case 7:
				exit(0);
				break;
			default:
				printf("Wrong choice!!!");
		}
	}while(1);
	return 0;
}
