#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};
typedef struct node Node;
Node *head=NULL;


void insertAtEnd(int _data) {
	Node *newNode=(Node*)malloc(sizeof(Node));
	if(newNode==NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	newNode->data=_data;
	newNode->next=NULL;
	Node *cur=head;
	
	if(head==NULL) {
		head=newNode;
		return;
	}
	while(cur->next!=NULL) {
		cur=cur->next;
	}
	cur->next=newNode;
}


void display() {
	Node *cur=head;
	while(cur!=NULL) {
		printf("%d\n", cur->data);
		cur=cur->next;
	} 
}


void reverseList() {
	Node *cur=head;
	Node *prev=NULL;
	Node *next;
	
	while(cur!=NULL) {
		next=cur->next;
		cur->next=prev;
		prev=cur;
		cur=next;	
	}
	head=prev;
}


int main() {
	insertAtEnd(10);
	insertAtEnd(20);
	insertAtEnd(30);
	insertAtEnd(40);
	display();
	printf("-------------\n");
	reverseList();
	display();
	return 0;
}