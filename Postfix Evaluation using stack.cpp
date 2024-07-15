// Postfix Evaluation
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define MAX 20
char postfix[MAX];
int stack[MAX];
int top=-1;
int x[MAX];
void push(int item)
{
	if(top==MAX-1)
	{
		printf("Stack Overflow!!");
		return;
	}
	stack[++top]=item;	
}
int pop()
{
	if(top==-1)
	{
		printf("Stack Underflow!!");
		return 0;
	}
	return 	stack[top--];
}
int postfix_evaluation(char* postfix)
{
	int i,a,b,r;
	//int x[MAX];
	for(i=0;postfix[i]!='\0';i++)
	{
		if(isalpha(postfix[i]))
		{
			push(x[i]);
		}
		else
		{
			a=pop();
			b=pop();
			switch(postfix[i])
			{
				case '+':
					r=b+a;
					break;
				case '-':
					r=b-a;
					break;
				case '*':
					r=b*a;
					break;
				case '/':
					r=b/a;
					break;
				case '%':
					r=b%a;
					break;
				case '^':
					r=pow(b,a);
					break;
				case '$':
					r=pow(b,a);
					break;	
			}
			push(r);
		}
	}
	return pop();
}
int main()
{
	int i=0;
//	int x[MAX];
	char postfix[MAX];
	printf("Enter the postfix expression:");
	gets(postfix);
	while(postfix[i]!='\0')
	{
		if(isalpha(postfix[i]))
		{
			printf("Enter the value for the operand %c:",postfix[i]);
			scanf("%d",&x[i]);
		}
		i++;
	}
	printf("The value of the postfix expression is:%d",postfix_evaluation(postfix));
	return 0;
}
