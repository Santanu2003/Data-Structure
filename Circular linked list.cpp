// Circular linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* link;
};
struct node* tail=NULL;
void insert_Beg(int item){
	struct node* x;
	x=(struct node*)malloc(sizeof(struct node));
	x->data=item;
	x->link=tail;
	if(tail==NULL){
		tail=x;
	}
	else
		x->link=tail->link;
	tail->link=x;
}
void insert_End(int item){
	struct node* x,*ptr;
	x=(struct node*)malloc(sizeof(struct node));
	x->data=item;
	if(tail==NULL){
		x->link=x;
	}
	else{
		x->link=tail->link;
		tail->link=x;	
	}
	tail=x;
}
void insert_Any(int item,int pos){
	struct node* x,*ptr;
	x=(struct node*)malloc(sizeof(struct node));
	x->data=item;
	if(pos==1){
		if(tail==NULL){
		tail=x;
		}
		else
			x->link=tail->link;
		tail->link=x;
	}
	else{
		ptr=tail->link;
		for(int i=1;i<=pos-2;i++){
			ptr=ptr->link;
			if(ptr==tail->link){
				printf("Invalid position!!");
				free(x);
				return;
			}
		}
		x->link=ptr->link;
		ptr->link=x;
		if(ptr==tail)
			tail=x;
	}
}
void delete_Beg(){
	struct node* ptr;
	if(tail==NULL){
		printf("List is empty!!");
	}
	else{
		ptr=tail->link;
		if(tail==tail->link){
			printf("Deleted item is %d",tail->data);
			tail=NULL;
		}
		else{	
			tail->link=ptr->link;
			printf("Deleted item is %d",ptr->data);
			free(ptr);
			return;
		}
	}
}
void delete_End(){
	struct node* ptr,*prevptr;
	if(tail==NULL){
		printf("List is empty!!");
		return;
	}
	else{
		if(tail->link==tail){
			printf("Deleted item is %d",tail->data);
			tail=NULL;
		}
		else{
			ptr=tail->link;
			while(ptr!=tail){
				prevptr=ptr;
				ptr=ptr->link;
			}
			prevptr->link=ptr->link;
			tail=prevptr;
			printf("Deleted item is %d",ptr->data);
			free(ptr);
		}	
	}
	return;	
}
void delete_Any(int pos){
	struct node* ptr,*next;
	if(tail==NULL){
		printf("List is empty!!");
		return;
	}
	else{
		ptr=tail->link;
		if(pos==1){
			if(tail==tail->link){
				printf("Deleted item is %d",tail->data);
				tail=NULL;
			}
			else{	
				tail->link=ptr->link;
				printf("Deleted item is %d",ptr->data);
				free(ptr);
				return;
			}
		}
		else{
			for(int i=1;i<=pos-2;i++){
				ptr=ptr->link;
			}
		/*	if(ptr==tail->link){
				printf("Invalid position !!!");
				return;
			}	*/
			next=ptr->link;
			ptr->link=next->link;
			printf("Deleted item is %d",next->data);
			free(next);
			return;
		}	
	}
}
void display(){
	struct node *ptr;
	if(tail==NULL){
		printf("List is empty!!");
		return;
	}
	ptr=tail->link;
	while(ptr!=tail){
		printf("%d->",ptr->data);
		ptr=ptr->link;
	}
	printf("%d",ptr->data);
}
int main()
{
	int ch,item,pos;
	do{
		printf("\n***** Circular Linked list Operation *****");
		printf("\nInsert at beginning->1");
		printf("\nInsert at end->2");
		printf("\nInsert at any position->3");
		printf("\nDelete at beginning->4");
		printf("\nDelete at end->5");
		printf("\nDelete at any position->6");
		printf("\nDisplay->7");
		printf("\nExit->8");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter the item to be inserted:");
				scanf("%d",&item);
				insert_Beg(item);
				break;
			case 2:
				printf("Enter the item to be inserted:");
				scanf("%d",&item);
				insert_End(item);
				break;
			case 3:
				printf("Enter the item to be inserted:");
				scanf("%d",&item);
				printf("Enter the position where the item to be inserted:");
				scanf("%d",&pos);
				insert_Any(item,pos);
				break;
			case 4:
				delete_Beg();
				break;
			case 5:
				delete_End();
				break;
			case 6:
				printf("Enter the position where the deletion will be happend:");
				scanf("%d",&pos);
				delete_Any(pos);
				break;
			case 7:
				display();
				break;
			case 8:
				printf("Bye!!");
				exit(0);
			default:
				printf("Wrong choice!!");
				printf("\nEnter the valid option..");
		}
	}while(1);
	return 0;
} 
