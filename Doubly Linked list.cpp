// Doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node* prev;
	int data;
	struct node* link;
};
struct node* head=NULL;
void insert_Beg(int item){
	struct node* x;
	x=(struct node*)malloc(sizeof(struct node));
	x->data=item;
	x->prev=NULL;
	x->link=head;
	if(head==NULL){
		head=x;
	}
	else{
		head->prev=x;
		head=x;			
	}
}
void insert_End(int item){
	struct node* x,*ptr;
	x=(struct node*)malloc(sizeof(struct node));
	x->data=item;
	x->link=NULL;
	x->prev=head;
	if(head==NULL){
		head=x;
	}
	else{
		ptr=head;
		while(ptr->link!=NULL){
			ptr=ptr->link;
		}
		ptr->link=x;
		x->prev=ptr;	
	}
}
void insert_Any(int item,int pos){
	struct node* x,*ptr;
	x=(struct node*)malloc(sizeof(struct node));
	x->data=item;
	x->prev=NULL;
	if(pos==1){
		x->link=head;
		head=x;	
	}
	else{
		ptr=head;
		for(int i=1;i<=pos-2 && ptr!=NULL;i++){
			ptr=ptr->link;
		}
		if(ptr==NULL){
			printf("Invalid choice!!");
			free(x);
			return;
		}
		x->link=ptr->link;
		if(ptr->link!=NULL){
			ptr->link->prev=x;
		}
		ptr->link=x;
		x->prev=ptr;
	}
}
void delete_Beg(){
	struct node* ptr;
	ptr=head;
	if(ptr==NULL){
		printf("List is empty!!");
		return ;
	}
	head=head->link;
	if(head!=NULL){
		head->prev=NULL;
	}
	printf("Deleted item is %d",ptr->data);
	free(ptr);
}
void delete_End(){
	struct node* ptr,*prevptr;
	ptr=head;
	if(ptr==NULL){
		printf("List is empty!!");
		return;
	}
	else{
		if(ptr->link==NULL){
			head=NULL;
		}
		else{
			while(ptr->link!=NULL){
				prevptr=ptr;
				ptr=ptr->link;
			}
			prevptr->link=NULL;
		}
		printf("Deleted item is %d",ptr->data);
		free(ptr);
		return;	
	}
}
void delete_Any(int pos){
	struct node* ptr,*next;
	ptr=head;
	if(ptr==NULL){
		printf("List is empty!!");
		return;
	}
	else{
		if(pos==1){
			head=head->link;
			printf("Deleted item is %d",ptr->data);
			free(ptr);
			return;
		}
		else{
			for(int i=1;i<=pos-2 && ptr!=NULL;i++){
				ptr=ptr->link;
			}
			if(ptr->link==NULL){
				printf("Invalid choice !!!");
				return;
			}
			next=ptr->link;
			ptr->link=next->link;
			if(next->link!=NULL)
				next->link->prev=ptr;
			printf("Deleted item is %d",next->data);
			free(next);
		}	
	}
}
void reverse(){
	struct node *prevptr=NULL,*curr=head,*next=NULL;
	if(curr==NULL){
		printf("List is empty!!");
		return;
	}
	while(curr!=NULL){
		next=curr->link;
		curr->link=prevptr;
		prevptr=curr;
		prevptr->prev=curr;
		curr=next;
	}
	head=prevptr->prev;
	printf("Reverse is done....");
}

void display(){
	struct node *ptr;
	ptr=head;
	if(ptr==NULL){
		printf("List is empty!!");
		return;
	}
	while(ptr->link!=NULL){
		printf("%d->",ptr->data);
		ptr=ptr->link;
	}
	printf("%d",ptr->data);
}
/*Search,sort,count,minmax,display ->this functions are same in singly and doubly linked list*/
int main()
{
	int ch,item,pos;
	do{
		printf("\n***** Double Linked list Operation *****");
		printf("\nInsert at beginning->1");
		printf("\nInsert at end->2");
		printf("\nInsert at any position->3");
		printf("\nDelete at beginning->4");
		printf("\nDelete at end->5");
		printf("\nDelete at any position->6");
		printf("\nReverse the Double linked list->7");//	
		printf("\nDisplay->8");
		printf("\nExit->9");
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
				reverse();
				break;
			case 8:
				display();
				break;
			case 9:
				printf("Bye!!");
				exit(0);
			default:
				printf("Wrong choice!!");
				printf("\nEnter the valid option..");
		}
	}while(1);
	return 0;
} 
