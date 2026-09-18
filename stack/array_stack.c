#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXSIZE 5
int stack[MAXSIZE];
int top=-1;


int isFull() {
	return top==MAXSIZE-1;
}


int isEmpty() {
	return top==-1;
}


void push(int value){
	if(isFull()){
		printf("Stack is full.\n");
		return;
	}
	stack[++top]=value;
	printf("%d is added.\n", value);
}


int pop() {
	if(isEmpty()){
		printf("Stack is empty.\n");
		return -1;
	}
	return stack[top--];
}


int peek() {
	if(isEmpty()){
		printf("Stack is empty!\n");
		return -1;
	}
	return stack[top];
}


void printStack() {
	if(isEmpty()){
		printf("Stack is empty!\n");
		return;
	}
	printf("Stack:\n");
	for(int i=top;i>=0;i--){
		printf("%d\n", stack[i]);
	}
	printf("\n");
}


int main() {
	push(10);
	push(20);
	push(30);
	printStack();
	printf("The top element: %d\n", peek());
	printf("The popped one: %d\n", pop());
	push(40);
	push(50);
	push(60); //Overflow
	push(70);
	printStack();
	return 0;
}
