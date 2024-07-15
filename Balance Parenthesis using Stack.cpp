// Balance Parenthesis
#include<stdio.h>
#define MAX 50
char stack[MAX];
int top=-1;

void push(char item){
    if(top==MAX-1){
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

int main(void){
	char s[MAX],temp;
	int i;
	int valid=1;  // valid is true: valid
	
	printf("Enter the Expression:"); 
	gets(s); 
	
	for(i=0;s[i]!='\0';i++){
		if(s[i]=='('||s[i]=='{'||s[i]=='[')
			push(s[i]);  
			
		if(s[i]==')'||s[i]=='}'||s[i]==']'){
			if(top==-1) // Stack Empty
				valid=0; // Invalid
				
			else{
				temp=pop();  // ')' top=0
				if(s[i]==')'&&(temp=='{'||temp=='[')){
					valid=0;				
					break;
				}
				
				if(s[i]=='}'&&(temp=='('||temp=='[')){
					valid=0;				
					break;
				}
				if(s[i]==']'&&(temp=='('||temp=='{')){
					valid=0;				
					break;
				} //end if
			}//end else
		}//end if
	}// end for
	if(top>=0)
		valid=0;
	if(valid==0)
		printf("Expression is Invalid!!!");
	else
		printf("Expression is Valid !!");
	return 0;  
}
