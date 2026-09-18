#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};
typedef struct node Node;

Node *top=NULL; // top = head (beginning of the list)

void push(int _data) {
	Node *newNode=(Node*)malloc(sizeof(Node));
	if(newNode==NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	newNode->data=_data;
	newNode->next=top;
	top=newNode;
}


int pop() {
	if(top==NULL) {
		printf("Stack is empty!\n");
		return -1;
	}
	Node *temp=top;
	int data=temp->data;
	top=top->next;
	free(temp);
	return data;
}


int peek() {
	if(top==NULL) {
		printf("Stack is empty!\n");
		return -1;
	}
	return top->data;
}


void printStack(){
	Node *cur=top;
	while(cur!=NULL){
		printf("%d\n", cur->data);
		cur=cur->next;
	}
}


int main() {
	push(10);
	push(20);
	push(30);
	printStack();
	printf("--------------\n");
	printf("%d\n", peek());
	printf("--------------\n");
	pop();
	printStack();
	
	return 0;
}