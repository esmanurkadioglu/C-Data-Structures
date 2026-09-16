#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};
typedef struct node Node;
Node *head=NULL;

void insert(int _data) {
	Node *cur;
	Node *newNode=(Node*)malloc(sizeof(Node));
	newNode->data=_data;
	
	if(head==NULL) { // list is empty
	   head=newNode;
	   newNode->next=newNode;
	   newNode->prev=newNode;
	} else {
		cur=head;
		if(cur->data>newNode->data) head=newNode;
		else {
			do {
				if(newNode->data <cur->data) break;
				cur=cur->next;
			}while(cur!=head);
		}
		cur->prev->next=newNode;
		newNode->next=cur;
		newNode->prev=cur->prev;
		cur->prev=newNode;
	}
}


void display() {
	Node *cur=head;
	do{
		printf("%d\n", cur->data);
		cur=cur->next;
	}while(cur!=head);
}


int main() {
	insert(5);
	insert(12);
	insert(7);
	insert(3);
	insert(8);
	insert(19);
	insert(15);
	insert(1);
	display();
	printf("\n-------------\n");
	return 0;	
}