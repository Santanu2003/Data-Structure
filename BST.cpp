// BST [Using Recursion]
#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node* left;
	int data;
	struct node* right;	
};
struct node* insert(struct node* ptr,int item){
	if(ptr==NULL){
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->data=item;
		ptr->left=NULL;
		ptr->right=NULL;
	}
	else if(item<ptr->data){
		ptr->left=insert(ptr->left,item);
	}
	else if(item>ptr->data){
		ptr->right=insert(ptr->right,item);
	}
	else
		printf("Duplicate not allowed!!");
	return ptr;
}
void inorder(struct node* ptr){
	if(ptr!=NULL){
		inorder(ptr->left);
		printf("%d\t",ptr->data);
		inorder(ptr->right);
	}
}
void preorder(struct node* ptr){
	if(ptr!=NULL){
		printf("%d\t",ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}
void postorder(struct node* ptr){
	if(ptr!=NULL){
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d\t",ptr->data);
	}
}
int main(){
	struct node* root=NULL;
	int ch,item;
	do{
		printf("\n*****BST[Using recursion]*****");
		printf("\ninsert->1");
		printf("\ndelete->2");
		printf("\ninorder->3");
		printf("\npreorder->4");
		printf("\npostorder->5");
		printf("\nsearch->6");
		printf("\nminimum->7");
		printf("\nmaximum->8");
		printf("\nexit->9");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter the item to be inserted:");
				scanf("%d",&item);
				root=insert(root,item);
				break;
			case 2:
				break;
			case 3:
				inorder(root);
				break;
			case 4:
				preorder(root);
				break;
			case 5:
				postorder(root);
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				printf("Bye!!");
				exit(0);
			default:
				printf("Wrong choice");
		}
	}while(1);
}
