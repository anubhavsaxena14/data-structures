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
void swapnodes(node* head, int x, int y)
{
	if(x==y)
	{
		return;
	}
	node* prevX = NULL, *currX = head; 
	while(currX && currX->data!=x)
	{
		prevX = currX;
		currX = currX->next;
	}
	node* prevY = NULL, *currY = head;
	while(currY && currY->data!=y)
	{
		prevY = currY;
		currY = currY->next;
	}
	if(currX == NULL || currY == NULL)
	{
		return;
	}
		if(prevX!=NULL)
		{
			prevX->next = currY;
		}
		else
		{
			head = currY;
		}
		if(prevY!=NULL)
		{
			prevY->next = currX;
 		}
		else
		{
			head = currX;
		}

		//swap next pointers
		node* temp = currX->next;
		currX->next = currY->next;
		currY->next = temp;
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
	int x,y;
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
	printf("Enter values of x and y\n");
	scanf("%d",&x);
	scanf("%d",&y);
	swapnodes(head,x,y);
	showlist(head);
}