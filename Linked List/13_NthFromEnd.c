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
void printNthfromEnd(node *head, int index)
{
	node *main_ptr = head, *ref_ptr = head;
	int count = 0;
	while(count!=index)
	{
		ref_ptr = ref_ptr->next;
		count++;
	}
	while(ref_ptr->next!=NULL)
	{
		main_ptr = main_ptr->next;
		ref_ptr = ref_ptr->next;	
	}
	printf("%d\n",main_ptr->data);
}
int main()
{
	int i = 0, n = 0;
	int index;
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
	printf("Enter values of n\n");
	scanf("%d",&index);
	printNthfromEnd(head,index);
}