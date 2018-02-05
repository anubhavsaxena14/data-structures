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
void sortedInsert(node *head, int key)
{
	node *curr = head, *temp = NULL;
	if(head == NULL || head->data >= key)
	{
		printf("List is Empty\n");
		head->data = key;
		head->next = NULL;
	}
	else
	{
		while(curr->next!=NULL && curr->next->data < key)
		{
			curr = curr->next;
		}
		temp = (node*)malloc(sizeof(node));
		temp->data = key;
		temp->next = curr->next;
		curr->next = temp;
	}
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
int main()
{
	int i = 0, n = 0, key;
	node *head;
	printf("Enter elements of list\n");
	for (i = 0;  ; i++)
	{	
		scanf("%d",&n);
		head = createlist(head,n);
		if(n == -9999)
		{
			break;
		}
	}
	printf("Enter Key\n");
	scanf("%d",&key);
	sortedInsert(head, key);
	showlist(head);
}