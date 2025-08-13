#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node*next;
};

struct node*head=NULL;

void insertfront(int data) {
	
    node* newnode = (node*)malloc(sizeof(node));
    
    if (!newnode) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode -> data = data;
    newnode -> next = head;
    head = newnode;
    printf("Inserted %d of the front\n", data);
}

void insertend(int data) {
	
    node* newnode = (node*)malloc(sizeof(node));
    
    if (!newnode) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode -> data = data;
    newnode -> next = head;
    if(head==NULL)
    {
    	head = newnode;
	}
	else
	{
    	node*temp=head;
    	while(temp -> next)temp=temp -> next;
    	temp -> next =  newnode;
    }
    printf("Inserted %d of the end\n", data);
}

void insertmiddle(int data, int pos) {
	if(pos<1)
	{
		printf("Position should be >= 1\n");
        return;
	}
	if(pos==1)
	{
		insertfront(data);
        return;
	}
    node* newnode = (node*)malloc(sizeof(node));
    
    if (!newnode) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode -> data = data;
    node* temp = head;
    for(int i = 1; i<pos-1 && temp!=NULL;i++)
    {
    	temp= temp -> next;
	}
    if(temp==NULL)
    {
    	printf("Position out of bound\n");
    	free(newnode);
    	return;
	}
	newnode -> next = temp -> next; 
   	temp -> next =  newnode;
    printf("Inserted %d at position\n", data,pos);
}

int main() 
{
	int choice,data,pos;
	
	while(1){
		printf("1. Insert at front\n");
		printf("2. Insert at end\n");
		printf("3. Insert at middle\n");
		printf("4. Exit\n");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:  
			printf("Enter the data to insert at front\n");
			scanf("%d", &data);
			insertfront(data);
			break;
            case 2:
            printf("Enter the data to insert at end\n");
			scanf("%d", &data);
			insertend(data);
			break;
			case 3:
			printf("Enter the data to insert\n");
			scanf("%d", &data);
			printf("Enter the position\n");
			scanf("%d", &pos);
			insertmiddle(data,pos);
			break;
			case 4:
			exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

