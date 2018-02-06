struct Node *addAfter(struct Node *last, int data, int item)
{
    if (last == NULL)
       return NULL;
 
    struct Node *temp, *p;
    p = last -> next;
 
    // Searching the item.
    do
    {
        if (p ->data == item)
        {
            // Creating a node dynamically.
            temp = (struct Node *)malloc(sizeof(struct Node));
 
            // Assigning the data.
            temp -> data = data;
 
            // Adjusting the links.
            temp -> next = p -> next;
 
            // Adding newly allocated node after p.
            p -> next = temp;
 
            // Checking for the last node.
            if (p == last)
                last = temp;
 
            return last;
        }
        p = p -> next;
    } while (p != last -> next);
 
    cout << item << " not present in the list." << endl;
    return last;
}
