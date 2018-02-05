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
int detectloop(node *head)
{
	node *slow_ptr = head, *fast_ptr = head;
	while(slow_ptr && fast_ptr && fast_ptr->next)
	{
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
		if(slow_ptr == fast_ptr)
		{
			printf("Loop Exists\n");
			return 1;
		}
	}
	return 0;
}
int main()
{
	int i = 0, n = 0;
	int key;
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
	//create a loop for testing
	head->next->next->next->next = head;
	detectloop(head);
}