#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};
typedef struct node Node;
Node *head=NULL;

void createList() {
	int count;
	Node *cur;
	printf("How many elements do you want to add?\n");
	scanf("%d", &count);
	
	for(int i=0;i<count;i++) {
		Node *newNode=(Node*)malloc(sizeof(Node));
		printf("Enter the %d. number:\n", i+1);
		scanf("%d", &newNode->data);
		newNode->next=NULL;
		if(head==NULL) head=newNode;
		else {
			cur=head;
			while(cur->next!=NULL) {
			   cur=cur->next;
			}
			cur->next=newNode;
		}
	}
}


void display() {
	Node *cur;
	cur=head;
	
	while(cur!=NULL){
		printf("%d\n", cur->data);
		cur=cur->next;
	}
}

void insertAtBeginning(int _data) {
	Node *newNode=(Node*)malloc(sizeof(Node));
	newNode->data=_data;
	newNode->next=head;
	head=newNode;
}

void insertAtEnd(int _data) {
	Node *newNode=(Node*)malloc(sizeof(Node));
	newNode->data=_data;
	newNode->next=NULL;
	Node *cur;
	cur=head;
	if(head==NULL) {
		head=newNode;
		return;
	}
	
	while(cur->next!=NULL) {
		cur=cur->next;
	}
	cur->next=newNode;
}

void insertAtPosition(int _data, int position) {
	Node *newNode=(Node*)malloc(sizeof(Node));
	newNode->data=_data;
	newNode->next=NULL;
	
	if(head==NULL) {
		if(position==1) {
			head=newNode;
		}else {
			printf("Invalid position!\n");
			free(newNode);
		}
		return;
	}
	
	if(position<=0) {
    printf("Invalid position!\n");
    return;
}
	// insert at beginning
	if(position==1) {
		newNode->next=head;
		head=newNode;
		return;
	}
	Node *prev=NULL;
	Node *cur=head;
	// find the position
	for(int i=0;i<position-1;i++) {
		prev=cur;
		cur=cur->next;
		if(cur==NULL) {
			printf("Invalid position!\n");
			free(newNode);
			return;
		}
	}
	// insert between prev and cur
	prev->next=newNode;
	newNode->next=cur;
	
}

void deleteFromBeginning() {
	if(head==NULL) return;
	Node *temp;
	temp=head;
	head=head->next;
	free(temp);
}

void deleteFromEnd() {
	if(head==NULL) return;
	Node *temp=head;
	Node *prev=NULL;
	
	if(temp->next==NULL) {
		head=NULL;
		free(temp);
		return;
	}
	
	while(temp->next!=NULL) {
		prev=temp;
		temp=temp->next;
	}
	prev->next=NULL;
	free(temp);
	
}

void deleteAtPosition(int position) {
	Node *temp=head;
	Node *prev=NULL;
	
	if(head==NULL) return;
	
	if(position<=0) {
		printf("Invalid position!\n");
		return;
	}
	
	if(position==1) {
		head=head->next;
		free(temp);
		return;
	}
	
	// find the position 
	for(int i=0;i<position-1;i++) {
		prev=temp;
		temp=temp->next;
		if(temp==NULL) {
			printf("Invalid position!\n");
			return;
		}
	}
	
	prev->next=temp->next;
	free(temp);
}

void search(int _data) {
	Node *cur=head;
	if(head==NULL) return;
	
	while(cur!=NULL){
		if(cur->data==_data) {
			printf("Data is found.\n");
			return;
		} 
		cur=cur->next;
	}
	printf("Data is not found!\n");
}

void menu() {
    printf("\n===== LINKED LIST MENU =====\n");
    printf("1. Display List\n");
    printf("2. Insert at Beginning\n");
    printf("3. Insert at Position\n");
    printf("4. Insert at End\n");
    printf("5. Delete from Beginning\n");
    printf("6. Delete at Position\n");
    printf("7. Delete from End\n");
    printf("8. Search\n");
    printf("9. Exit\n");
    printf("============================\n");
}

int main() {
    int choice;
    int data;
    int position;

    createList();

    do {
        menu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                display();
                break;

            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);

                insertAtBeginning(data);
                break;

            case 3:
                printf("Enter the data: ");
                scanf("%d", &data);

                printf("Enter the position: ");
                scanf("%d", &position);

                insertAtPosition(data, position);
                break;

            case 4:
                printf("Enter the data: ");
                scanf("%d", &data);

                insertAtEnd(data);
                break;

            case 5:
                deleteFromBeginning();
                break;

            case 6:
                printf("Enter the position: ");
                scanf("%d", &position);

                deleteAtPosition(position);
                break;

            case 7:
                deleteFromEnd();
                break;

            case 8:
                printf("Enter the data to search: ");
                scanf("%d", &data);

                search(data);
                break;

            case 9:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 9);

    return 0;
}



