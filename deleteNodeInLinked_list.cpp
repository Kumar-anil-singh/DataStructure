Node* deleteNode(Node *head,int x)
{
    //Your code here
    if(head == NULL)
        return head;
    Node *temp = head;
    Node *prev = NULL;
    if(x == 1)
    {
        head=temp->next;
        free(temp);
        return head;
    }
    for(int i=1; i<x-1 && temp != NULL; i++)
    {
        Node *prev = temp;
        temp = temp->next;
    }
    if(temp->next == NULL)
    {
        prev->next = NULL;
        free(temp);
    }
    else
    {
        Node *next = temp->next->next;
        free(temp->next);
        temp->next = next;
    }
    return head;
}
