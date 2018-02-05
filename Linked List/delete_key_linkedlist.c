#include<stdio.h>
#include<stdlib.h>
struct linked_list
{
	int data; 
	struct linked_list *next;
};
typedef struct linked_list node;
node *createlist(node *head, int data)
{
	node *temp, *start = head;
	if(head == NULL)
	{
		head = (node*)malloc(sizeof(node));
		head->data = data;
		head->next = NULL;	
	}
	else
	{
		while(start->next)
		{
			start = start->next;
		}
			temp = (node*)malloc(sizeof(node));
			temp->data = data;
			temp->next = NULL;
			start->next = temp;
	}
	return head;
}
void showlist(node *head)
{
	node *temp = head;
	int x = 0;
	printf("Here is the list\n");
	while(temp)
	{
		x = temp->data;
		printf("%d\t",x);
		temp = temp->next;
	}
}
void deletekey(node *curr, int key)
{
	node *temp2;
	if(curr == NULL)
	{
		printf("Empty List\n");	
	}
	else
	{
		while((curr->next!=NULL)&&(curr->next->data!=key))
		{
			curr = curr->next;
		}
		if(curr->next->data == key)
		{
			printf("Key found is %d\n",curr->next->data);
			temp2 = curr->next;
			curr->next = temp2->next;
			temp2->next = NULL;
			free(temp2);
		}
		else if(curr->next == NULL)
		{
			printf("Key not found");	
		}
	}
}
int main()
{
	int i = 0, n = 0, key;
	node *head;
	printf("Enter elements of list\n");
	for (i = 0;  ; i++)
	{	
		scanf("%d",&n);
		if(n == -9999)
		{
			break;
		}
		else
		{
			head = createlist(head,n);
		}
	}
	showlist(head);
	printf("\nEnter key to be deleted\n");
	scanf("%d",&key);
	deletekey(head, key);
	printf("\nNew List:\n");
	showlist(head);
}