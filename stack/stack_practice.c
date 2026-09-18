#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5
int stack[MAXSIZE];
int top=-1;

int isFull(){
	return top==MAXSIZE-1;
}

int isEmpty(){
	return top==-1;
}


void push(int _data) {
	if(isFull()) {
		printf("Stack is full!\n");
		return;
	} 
	stack[++top]=_data;
	printf("%d is added.\n", _data);
}


int pop() {
	if(isEmpty()) {
		printf("Stack is empty!\n");
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


void printStack(){
	if(isEmpty()){
		printf("Stack is empty!\n");
		return;
	}
	for(int i=top;i>=0;i--){
		printf("%d\n", stack[i]);
	}
}


int main() {
	int data;
	printf("Enter 5 numbers:\n");
	for(int i=0;i<MAXSIZE;i++){
		scanf("%d", &data);
		push(data);
	}
	printStack();
	printf("--------------\n");
	printf("The peek element is %d\n", peek());
	printf("--------------\n");
	pop();
	pop();
	printStack();
	
	return 0;
}