// Queue using linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* link;
};
struct node* rear=NULL,*front=NULL;
void qinsert(int item){
	struct node* x,*ptr;
	x=(struct node*)malloc(sizeof(struct node));
	x->data=item;
	x->link=NULL;
	if(rear==NULL){
		front=x;
	}
	else{
		rear->link=x;	
	}
	rear=x;
}
void qdelete(){
	struct node* ptr;
	ptr=front;
	if(front==NULL){
		printf("List is empty!!");
	}
	else{
		front=ptr->link;
		printf("Deleted item is %d",ptr->data);
		free(ptr);
		return;
	}
}
void display(){
	struct node *ptr;
	ptr=front;
	if(front==NULL){
		printf("List is empty!!");
		return;
	}
	while(ptr->link!=NULL){
		printf("%d->",ptr->data);
		ptr=ptr->link;
	}
	printf("%d",ptr->data);
}
int main()
{
	int ch;
	do{
		printf("\n***Linked Queue***");
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
				qinsert(item);
				break;
			case 2:
				qdelete();
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
