// Reverse the String
#include<stdio.h>
#define Max 50
char stack[Max];
int top=-1;
void push(int item){
    if(top==Max-1){
        printf("Stack Overflow!!!");
        return;
    }
    stack[++top]=item;
}
char pop(){
    if(top==-1){
        printf("Stack Underflow");
        return -1;
    }
    return stack[top--];
}
int main(){
	char s[Max];
	printf("Enter the String:");
	gets(s);
	int i=0;
	while(s[i]!='\0'){
		push(s[i]);
		i++;
	}
	printf(" The reverse string is:");
	while(top!=-1){
		char v=pop();
		printf("%c",v);
	}
	return 0;		
}
