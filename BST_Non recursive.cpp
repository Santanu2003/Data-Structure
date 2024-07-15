// BST [Using Non Recursion]
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct node{
	struct node* left;
	int data;
	struct node* right;	
};
struct node	*root=NULL,*par=NULL;
int top=-1,item;
struct node	stack[MAX];
void push(struct node* item){
	if(top==MAX-1)
	{
		printf("Stack Overflow!!!");
	}
	stack[++top]=item;
}
struct node* pop(){
	if(top==-1)
	{
		printf("Stack Underflow!!!");
	}
	return stack[top--];
}
void insert(int item){
	struct node* ptr;
	ptr=root;
	while(ptr!=NULL){
		par=ptr;
		if(item<ptr->data)
			ptr=ptr->left;
		else if(item>ptr->data)
			ptr=ptr->right;
	}
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->left=NULL;
	temp->right=NULL;
	if(par==NULL)
		root=temp;
	else if(item<par->data)
		par->left=temp;
	else if(item>par->data)
		par->right=temp;
}
void inorder(struct node* ptr){
	do{
		while(ptr->left!=NULL){
			push(ptr);
			ptr=ptr->left;
		}
		while(ptr->right==NULL){
			printf("%d\t",ptr->data);
			if(top==-1)
				return;
			ptr=pop();
		}
		printf("%d\t",ptr->data);
		ptr=ptr->right;
	}while(1);
}
void preorder(struct node* ptr){
	push(ptr);
	do{
		ptr=pop();
		printf("%d\t",ptr->data);
		if(ptr->right!=NULL)
			push(ptr->right);
		if(ptr->left!=NULL)
			push(ptr->left);
		if(top==-1)
			return;
	}while(1);
}
/*void postorder(struct node* ptr){
	if(ptr!=NULL){
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d\t",ptr->data);
	}
}*/
int main(){
	int ch,item;
	do{
		printf("\n*****BST[Using Non recursion]*****");
		printf("\ninsert->1");
		printf("\ninorder->3");
		printf("\npreorder->4");
		printf("\npostorder->5");
		printf("\nexit->6");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter the item to be inserted:");
				scanf("%d",&item);
				insert(item);
				break;
			case 3:
				inorder(root);
				break;
			case 4:
				preorder(root);
				break;
			case 5:
			//	postorder(root);
				break;
			case 6:
				printf("Bye!!");
				exit(0);
			default:
				printf("Wrong choice");
		}
	}while(1);
}
