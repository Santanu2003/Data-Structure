// Tower of Hanoi
#include<stdio.h>
int i=0;
int toh(int n,char s,char d,char a){
	if(n>=1){
		toh(n-1,s,a,d);
		printf("\nIn %d move disk will move from %c to %c",++i,s,d);
		toh(n-1,a,d,s);
	}
	return i;
}
int main(){
	int n;
	printf("Enter the no of disk:");
	scanf("%d",&n);
	printf("\nTotal no of move is %d",toh(n,'S','D','A'));
	return 0;
}
