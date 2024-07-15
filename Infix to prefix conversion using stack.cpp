// Infix to prefix Conversion 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50
char infix[MAX],prefix[MAX],stack[MAX];
int top=-1;
void push(char item)
{
	if(top==MAX-1)
	{
		printf("Stack Overflow!!");
		return;
	}
	stack[++top]=item;	// )
}
char pop()
{
	if(top==-1)
	{
		printf("Stack Underflow!!");
		return 0;
	}
	return 	stack[top--];
}
int prec(char symbol)
{
	switch(symbol)
	{
		case ')':
			return 0;
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
		case '%':
			return 2;
		case '^':
		case '$':
			return 3;
	}
}
void infix_to_prefix(char* infix)
{
	int i,j=0;
	char n;
	int len=strlen(infix);	//	17
	for(i=len-1;i>=0;i--)
	{
		if(infix[i]==')')	// )
			push(infix[i]);
		else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='%'||infix[i]=='^')	// +
		{
			while(top!=-1 && prec(infix[i])<prec(stack[top]))
			{
				prefix[j++]=pop();	
			}
			push(infix[i]);		// )+
		}
		else if(infix[i]=='(')	//	(
		{
			while((n=pop())!=')')
			{
				prefix[j++]=n;	// GG+
			}
		}
		else
			prefix[j++]=infix[i];	//	GG
	}
	prefix[j]='\0';
	while(top!=-1)
	{
		prefix[j++]=pop();
	}
}
int main()
{
	printf("Enter the infix expression:");
	gets(infix);	// A$B*C-D+E/F/(G+G)
	infix_to_prefix(infix);
	printf("Finally the prefix expression is %s",prefix);
	return 0;
}
