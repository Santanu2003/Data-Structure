#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int q[MAX];
int front = -1;
int reare=-1;

void qinsert(int element){
    int i, j, temp;
    if(front==(reare+1)%MAX){
        printf("Queue is full!!\n");
        return ;
    }
    else if(front == -1){
        front=reare=0;
    }
    else{
        reare=(reare+1)%MAX;
    }
    q[reare]=element;

    if(front<=reare){
        for(int i=front;i<reare;i++){
            for(int j=i+1;j<=reare;j++){
                if(q[i]>q[j]){
                    int temp=q[i];
                    q[i]=q[j];
                    q[j]=temp;
                }
            }
        }
    }else if(front>reare){
        for (int i=front; i<=MAX-1 || i<reare ; (i+1)%MAX){
            for(int j=(i+1)%MAX; j<=MAX-1 || j<=reare; (j+1)%MAX){
                if(q[i]>q[j]){
                    int temp=q[i];
                    q[i]=q[j];
                    q[j]=temp;
                }
            }
        }
    }
}

void qdelete(){
    if(front==-1){
        printf("The queue is empty.\n");
        return;
    }else if(reare==(front+1)%MAX){
        front=reare=-1;
    }else{
        front=(front+1)%MAX;
    }
}
void qdisplay(){
    if(front==-1){
        printf("Queue is empty,nothing to display");
        return;
    }else if(front<=reare){
        printf("The elements inside the queue are::\n");
        for(int i=front;i<=reare;i++){
            printf("%d  ",q[i]);
        }
    }else if(front>reare){
        printf("The elements stord are::");
        for(int i=reare ; i<=MAX-1;i++){
            printf("%d  ",q[i]);
        }for(int i=0;i<=front;i++){
            printf("%d  ",q[i]);
        }
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
				int element;
				printf("Enter the item to be inserted:");
				scanf("%d",&element);
				qinsert(element);
				break;
			case 2:
				qdelete();
				break;
			case 3:
				qdisplay();
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
