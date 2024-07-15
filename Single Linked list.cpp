// Singly Linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* link;
};
struct node* head=NULL;
void insert_Beg(int item){
	struct node* x;
	x=(struct node*)malloc(sizeof(struct node));
	x->data=item;
	x->link=head;
	head=x;
}
void insert_End(int item){
	struct node* x,*ptr;
	x=(struct node*)malloc(sizeof(struct node));
	x->data=item;
	x->link=NULL;
	if(head==NULL){
		head=x;
	}
	else{
		ptr=head;
		while(ptr->link!=NULL){
			ptr=ptr->link;
		}
		ptr->link=x;	
	}
}
void insert_Any(int item,int pos){
	struct node* x,*ptr;
	x=(struct node*)malloc(sizeof(struct node));
	x->data=item;
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
			printf("Invalid position!!");
			free(x);
			return;
		}
		x->link=ptr->link;
		ptr->link=x;
	}
}
void delete_Beg(){
	struct node* ptr;
	ptr=head;
	if(ptr==NULL){
		printf("List is empty!!");
	}
	else{
		head=ptr->link;
		printf("Deleted item is %d",ptr->data);
		free(ptr);
		return;
	}
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
	}
	return;	
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
		}
		else{
			for(int i=1;i<=pos-2 && ptr!=NULL;i++){
				ptr=ptr->link;
			}
			if(ptr==NULL){
				printf("Invalid position !!!");
			}
			next=ptr->link;
			ptr->link=next->link;
			printf("Deleted item is %d",next->data);
			free(next);
		}	
	}
}
void reverse(){
	struct node *prev=NULL,*curr=head,*next=NULL;
	while(curr!=NULL){
		next=curr->link;
		curr->link=prev;
		prev=curr;
		curr=next;
	}
	head=prev; // Very very important
	printf("Reverse is done....");
}
void search(int v){
	struct node* ptr;
	ptr=head;
	int flag=0;
	while(ptr!=NULL){
		if(ptr->data==v){
			flag++;
			break;
		}
		ptr=ptr->link;
	}
	if(flag!=0)
		printf("Item found..");
	else
		printf("Item not found..");
}
void sort(){
	struct node* ptr,*last=NULL;
	int flag;
	do{
		ptr=head;
		flag=0;
		while(ptr->link!=last){
			if((ptr->data)>(ptr->link->data)){
				int temp=ptr->data;
				ptr->data=ptr->link->data;
				ptr->link->data=temp;
				flag++;
			}
			ptr=ptr->link;
		}
		last=ptr;
	}while(flag);
	printf("Sorting is done..");
}
void count(){
	struct node* ptr;
	ptr=head;
	int c=0;
	while(ptr!=NULL){
		c++;
		ptr=ptr->link;
	}
	printf("The no of node present in the Single linked list is:%d",c);
}
void min_max(){
	struct node* ptr;
	int min,max;
	ptr=head->link;
	if(ptr==NULL){
		printf("List is empty!!");
		return;
	}
 	min=max=head->data;
	while(ptr!=NULL){
		if(ptr->data>max)
			max=ptr->data;
		else if(ptr->data<min)
			min=ptr->data;
		ptr=ptr->link;
	}
	printf("Min value of the linked list is:%d",min);
	printf("\nMax value of the linked list is:%d",max);	
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
int main()
{
	int ch,item,pos;
	do{
		printf("\n***** Single Linked list Operation *****");
		printf("\nInsert at beginning->1");
		printf("\nInsert at end->2");
		printf("\nInsert at any position->3");
		printf("\nDelete at beginning->4");
		printf("\nDelete at end->5");
		printf("\nDelete at any position->6");
		printf("\nReverse the single linked list->7");
		printf("\nSearch the single linked list->8");
		printf("\nBubble Sort the single linked list->9");
		printf("\nCount->10");
		printf("\nMin and Max element of the list->11");	
		printf("\nDisplay->12");
		printf("\nExit->13");
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
				printf("Enter the item to be searched:");
				scanf("%d",&item);
				search(item);
				break;
			case 9:
				sort();
				break;
			case 10:
				count();
				break;
			case 11:
				min_max();
				break;
			case 12:
				display();
				break;
			case 13:
				printf("Bye!!");
				exit(0);
			default:
				printf("Wrong choice!!");
				printf("\nEnter the valid option..");
		}
	}while(1);
	return 0;
} 
