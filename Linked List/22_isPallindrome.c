#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct linked_list
{
	int data; 
	struct linked_list *next;
};
typedef struct linked_list node;
node *createlist(node *head, char data)
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
	char x;
	printf("Here is the list\n");
	while(temp)
	{
		x = temp->data;
		printf("%c",x);
		temp = temp->next;
	}
}
bool isPallindromeUtil(node **left, node *right)
{
	if(right == NULL)
	{
		return true;
	}

	// If sub-list is not palindrome then no need to check for current left and right, return false
	bool isp = isPallindromeUtil(left, right->next);
	if(isp == false)
	{
		return false;
	}
	
	//Check values at current left and right
	bool isp1 = (right->data == (*left)->data);

	//Move left to next node
	*left = (*left)->next;
	return isp1;
}
//A wrapper over isPallindromeUtil()
bool isPallindrome(node *head)
{
	isPallindromeUtil(&head, head);
} 
int main()
{
	int i = 0;
	char c;
	bool isp;
	node *head;
	printf("Enter elements of list\n");
	for (i = 0;  ; i++)
	{	
		scanf("%c",&c);
		if(c == 'n')
		{
			break;
		}
		else
		{
			head = createlist(head,c);
		}
	}
	showlist(head);
	isp = isPallindrome(head);
	if(isp == true)
	{
		printf("Is Pallindrome\n");
	}
	else
	{
		printf("Not Pallindrome\n");
	}
}