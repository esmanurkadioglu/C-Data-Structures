#include <stdio.h>
#include <stdlib.h>

struct node	{
	int data;
	struct node *next;
};
typedef struct node Node;

Node *head=NULL; // Beginning of the list

void insert(int data) {
	Node *newItem=(Node*)malloc(sizeof(Node));
	newItem->next=head;
	newItem->data=data;
	head=newItem;
}

void del(int data) {
	Node *cur;
	Node *prev=NULL;
	
	if(head==NULL) return;
	for(cur=head;cur!=NULL;cur=cur->next){
		if(cur->data==data){
			if(cur==head) { // first item
				head=cur->next;
				free(cur);
			} else {
				prev->next=cur->next;
				free(cur);
				return;
			}
		}else prev=cur;	
	}	
}

void display(){
	Node *cur=head;
	if(head==NULL) return;
	
	while(cur!=NULL) {
		printf("%d\n", cur->data);
		cur=cur->next;
	}
}

int main() {
	insert(5);
	insert(3);
	insert(19);
	insert(15);
	insert(25);
	insert(7);
	display();
	printf("----------------\n");
	del(25);
	del(3);
	display();
	
	return 0;
}
