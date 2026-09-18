#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10

char stack[MAXSIZE][100];
int top=-1;

int isFull() {
	return top==MAXSIZE-1;
}

int isEmpty() {
	return top==-1;
}

void push(char page[]) {
	if(isFull()) {
		printf("Stack is full!\n");
		return;
	}
	++top;
	strcpy(stack[top], page);
	
}


void pop() {
	if(isEmpty()){
		printf("Stack is empty!\n");
		return;
	}
	char page[100];
	strcpy(page, stack[top]);
	top--;
	printf("Going back from: %s\n", page);
}


void peek() {
	if(isEmpty()) {
		printf("Stack is empty!\n");
		return;
	}

	printf("Current page: %s\n", stack[top]);
}


void printStack() {
	if(isEmpty()) {
		printf("Stack is empty!\n");
		return;
	}
	for(int i=top;i>=0;i--) {
		printf("%s\n", stack[i]);
    }
}

int main() {
	int choice;
	char page[100];
	
	while(1) {
			
	printf("\n==== Browser History ====\n");
	printf("1. Visit new page\n");
	printf("2. Go back\n");
	printf("3. Show current page\n");
	printf("4. Show history\n");
	printf("5. Exit\n");
	printf("Choose:\n");
	scanf("%d", &choice);
	
	switch(choice) {
		case 1:
		       printf("Enter page:\n");
		       scanf("%99s", page);
		       push(page);
		       break;
		case 2:
		       pop();
			   break;
		case 3:
			   peek();
			   break;
		case 4:
		       printStack();
			   break;
		case 5:
		       printf("Exiting...\n");
			   return 0;
		default:
		       printf("Invalid choice!\n");		
	}	
}
	return 0;
}