// Stack using linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* link;
};
struct node* top=NULL;
void push(int item){
	struct node* x;
	x=(struct node*)malloc(sizeof(struct node));
	x->data=item;
	x->link=top;
	top=x;
	return;
}
void pop(){
	struct node* ptr;
	ptr=top;
	if(top==NULL){
		printf("List is empty!!");
	}
	else{
		top=ptr->link;
		printf("Deleted item is %d",ptr->data);
		free(ptr);
		return;
	}
}
void display(){
	struct node *ptr;
	ptr=top;
	if(top==NULL){
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
	int ch,item;
	
	do{
		printf("\n***Linked Stack***");
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
