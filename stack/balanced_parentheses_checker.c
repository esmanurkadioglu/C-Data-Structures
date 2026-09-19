#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

char stack[MAXSIZE];
int top=-1;

int isFull() {
	return top==MAXSIZE-1;
}

int isEmpty() {
	return top==-1;
}

void push(char value) {
	if(isFull()) {
		printf("Stack is full!\n");
		return;
	}
	stack[++top]=value;
}


char pop() {
	if(isEmpty()) {
		printf("Stack is empty!\n");
		return '\0';
	}
	return stack[top--];
}


int isBalanced(char expression[]) {
	for(int i=0;expression[i]!='\0';i++) {
		if(expression[i]== '(') {
			push('(');
		}
		else if(expression[i]== ')') {
			if(isEmpty()) {
				return 0;
			}
			pop();
		}
	}
	return isEmpty();
}


int main() {
	char expression[MAXSIZE];
	
	printf("Enter an expression:\n");
	fgets(expression, MAXSIZE, stdin);
	
	if(isBalanced(expression)) printf("Balanced\n");
	else printf("Not balanced!\n");
	
	return 0;
}