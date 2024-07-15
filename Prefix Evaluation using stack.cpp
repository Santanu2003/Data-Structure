// Prefix Evaluation
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define MAX 20
char prefix[MAX];
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
int prefix_evaluation(char* prefix)
{
	int i,a,b,r;
	int len=strlen(prefix);
	for(i=len-1;i>=0;i--)
	{
		if(isalpha(prefix[i]))
		{
			push(x[i]);
		}
		else
		{
			a=pop();
			b=pop();
			switch(prefix[i])
			{
				case '+':
					r=a+b;
					break;
				case '-':
					r=a-b;
					break;
				case '*':
					r=a*b;
					break;
				case '/':
					r=a/b;
					break;
				case '%':
					r=a%b;
					break;
				case '^':
					r=pow(a,b);
					break;
				case '$':
					r=pow(a,b);
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
	char prefix[MAX];
	printf("Enter the postfix expression:");
	gets(prefix);
	while(prefix[i]!='\0')
	{
		if(isalpha(prefix[i]))
		{
			printf("Enter the value for the operand %c:",prefix[i]);
			scanf("%d",&x[i]);
		}
		i++;
	}
	printf("The value of the prefix expression is:%d",prefix_evaluation(prefix));
	return 0;
}
