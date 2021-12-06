#include<iostream>
using namespace std;

struct Node
{
	Node *next;
	int data;
};

Node* insert(Node *head, int data)
{
	Node *newnode = new Node();
	newnode->data = data;
	newnode->next = nullptr;
	if(head == nullptr)
	{
		head = newnode;
	}
	else
	{
		Node *temp = head;
		while(temp->next)
		temp=temp->next;
		temp->next = newnode;
	}
	return head;
}

void display(Node *head)
{
	while(head != nullptr)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}

Node* merge(Node *head1, Node *head2)
{
	Node *dummy = new Node;
	Node *p1, *p2, *p3;
	p1 = head1;
	p2 = head2;
	p3 = dummy;

	while(p1 != nullptr && p2 != nullptr)
	{
	if(p1->data < p2->data)
	{
		p3->next = p1;
		p1 = p1->next;
	}
	else
	{
		p3->next = p2;
		p2 = p2->next;
	}
	p3 = p3->next;
	}
	while(p1 != nullptr)
	{
		p3->next = p1;
		p1 = p1->next;
		p3 = p3->next;
	}
	while(p2 != nullptr)
	{
		p3->next = p2;
		p2 = p2->next;
		p3 = p3->next;
	}
	
	return dummy->next;

}

Node* reverseRecursively(Node *head)
{
	if(head == nullptr || head->next == nullptr)
		return head;
	Node *newhead = reverseRecursively(head->next);
	head->next->next = head;
	head->next = nullptr;
	return newhead;
}

Node* reverse(Node *head)
{
	if(head == nullptr)
		return head;
	Node *current, *next, *prev;
	current = head;
	next = prev = nullptr;
	while(current != nullptr)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;	
	
}

int main()
{
	int arr1[] = {1, 3, 5, 7, 9};
	int arr2[] = {2, 4, 6, 8, 10};
	Node *head1 = nullptr;
	Node *head2 = nullptr;
	for(int i=0; i<5; i++)
	{
		head1 = insert(head1, arr1[i]);
	}
	for(int i=0; i<5; i++)
	{
		head2 = insert(head2, arr2[i]);
	}
	display(head1);
	cout<<endl;
	display(head2);
	Node *newhead = merge(head1, head2);
	cout<<endl;
	display(newhead);
}
