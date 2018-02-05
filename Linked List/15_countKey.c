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
void countkey(node *head, int key)
{
	int count = 0;
	node *curr = head;
	while(curr)
	{
		if(curr->data == key)
		{
			count++;
		}
		curr = curr->next;
	}
	printf("%d occured %d times\n",key,count);
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
	printf("Enter key\n");
	scanf("%d",&key);
	countkey(head, key);
}