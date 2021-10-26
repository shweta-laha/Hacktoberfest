#include<stdio.h>
#include<string.h>
#define MAX 20

char st[MAX];
int top = -1;
char item;
void push(char item)
{
	if (top == MAX-1)    //Full Stack
	printf("The stack is full.\n");
	else{
		top++;
		st[top] = item;
	}
}

char pop()
{
	if (top == -1)     //Empty Stack
	printf("\nThe stack is empty.");
	else{
		item = st[top];
		top--;
		return item;
	}
}

int main()
{
	int i,t;
	printf("\nMaximum word in string shouldn't be more than 20.");
	printf("\nInput a string:-  ");
	gets(st);
	for(i=0;i<strlen(st);i++)
	push(st[i]);
	printf("\nReversed string is:-  ");
	for (i=top;i>=0;i--){
	item = pop();
	printf("%c", item);
	}
	return 0;
}
