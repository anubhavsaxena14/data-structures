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
node *findkey(node *curr, int key)
{
	int x;
	if(curr == NULL)
	{
		printf("Empty List\n");	
	}
	if(curr->data == key)
	{
		x = curr->data;
		printf("Key found is %d\n",x);

	}
	else
	{
		return findkey(curr->next, key);
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
	printf("\nEnter key to find\n");
	scanf("%d",&key);
	findkey(head, key);
}