// Polynomial Addition using Singly Linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int coeff;
	int expo;
	struct node* link;
};
struct node* create_poly(int c,int e,struct node* start){
	struct node* x,*ptr;
	x=(struct node*)malloc(sizeof(struct node));
	x->coeff=c;
	x->expo=e;
	if(start==NULL || e>start->expo){
		x->link=start;
		start=x;
	}
	else{
		ptr=start;
		while(ptr->link!=NULL && ptr->link->expo>e){
			ptr=ptr->link;
		}
		x->link=ptr->link;
		ptr->link=x;	
	}
	return start;
}
void display(struct node* ptr){
	if(ptr==NULL){
		printf("List is empty!!");
		return;
	}
	while(ptr->link!=NULL){
		printf("%dx^%d+",ptr->coeff,ptr->expo);
		ptr=ptr->link;
	}
	printf("%dx^%d",ptr->coeff,ptr->expo);
	printf("\n");
}
struct node* polyadd(struct node* p,struct node* q){
	struct node* head=NULL;
	while(p!=NULL && q!=NULL){
	    if(p->expo==q->expo){
			struct node* x,*ptr;
			x=(struct node*)malloc(sizeof(struct node));
			x->coeff=p->coeff+q->coeff;
			x->expo=q->expo;
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
			p=p->link;	
			q=q->link;
		}
		else if(p->expo>q->expo){
			struct node* x,*ptr;
			x=(struct node*)malloc(sizeof(struct node));
			x->coeff=p->coeff;
			x->expo=p->expo;
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
			p=p->link;	
		}
		else if(p->expo<q->expo){
			struct node* x,*ptr;
			x=(struct node*)malloc(sizeof(struct node));
			x->coeff=q->coeff;
			x->expo=q->expo;
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
			q=q->link;
		}
	}
	while(p!=NULL){
		struct node* x,*ptr;
		x=(struct node*)malloc(sizeof(struct node));
		x->coeff=p->coeff;
		x->expo=p->expo;
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
		p=p->link;
	}
	while(q!=NULL){
		struct node* x,*ptr;
		x=(struct node*)malloc(sizeof(struct node));
		x->coeff=q->coeff;
		x->expo=q->expo;
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
		q=q->link;
	}
	return head;
}
int main(){
	int m,n,i,c,e;
	struct node* start1=NULL, *start2=NULL,*head=NULL;
	printf("Enter the no of terms in polynomial #1: ");
	scanf("%d",&m);
	printf("Enter the no of terms in polynomial #2: ");
	scanf("%d",&n);	
	for(i=0;i<m;i++){
		printf("Enter the coefficient in poly #1 as term #%d: ",i+1);
		scanf("%d",&c);
		printf("Enter the exponent in poly #1 as term #%d: ",i+1);
		scanf("%d",&e);
		start1=create_poly(c,e,start1);		
	}
	for(i=0;i<n;i++){
		printf("Enter the coefficient in poly #2 as term #%d: ",i+1);
		scanf("%d",&c);
		printf("Enter the exponent in poly #2 as term #%d: ",i+1);
		scanf("%d",&e);
		start2=create_poly(c,e,start2);		
	}
	head=polyadd(start1,start2);
	printf("The first polynomial is: ");
	display(start1);
	printf("The second polynomial is: ");
	display(start2);
	printf("The resultant polynomial is: ");
	display(head);
	return 0;
}
