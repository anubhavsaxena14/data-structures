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
node* SortedMerge(node* a, node* b, node *result)
{	
	if(a==NULL)
	{
		return b;
	}
	else if(b==NULL)
	{
		return a;
	}

	if(a->data <= b->data)
	{
		result = a;
		SortedMerge(a->next, b, result);
	}
	else 
	{
		result = b;
		SortedMerge(a, b->next, result);
	}
	return result;
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
	int i = 0, n = 0;
	int key;
	node *result = NULL;
	node *headA = NULL, *headB = NULL;
	printf("Enter elements of List 1: \n");
	for (i = 0;  ; i++)
	{	
		scanf("%d",&n);
		if(n == -9999)
		{
			break;
		}
		else
		{
			headA = createlist(headA,n);
		}
	}
	printf("Enter elements of List 2: \n");
	for (i = 0;  ; i++)
	{	
		scanf("%d",&n);
		if(n == -9999)
		{
			break;
		}
		else
		{
			headB = createlist(headB,n);
		}
	}
	SortedMerge(headA, headB, result);
	showlist(result);
}