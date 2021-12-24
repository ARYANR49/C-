#include<iostream>
using namespace std;
class node
{
public:int data;
  node *next;
    node (int value)
  {
    data = value;
    next = NULL;
}};

void
itail (node * &head, int value)
{
  node *n = new node (value);
  if (head == NULL)
    {
      head = n;
      return;
    }
  node *temp = head;
  while (temp->next != NULL)
    {
      temp = temp->next;
    }
  temp->next = n;
}

void
ihead (node * &head, int value)
{
  node *n = new node (value);
  n->next = head;
  head = n;
}

void
search (node * head, int value)
{
  node *temp = head;
  while (temp != NULL)
    {
      if (temp->data == value)
	{
	  cout << "ELEMENT FOUND: " << value << endl;
	  return;
	}
      else
	{
	  temp = temp->next;
	}
    }
  cout << "ELEMENT NOT FOUND: " << value << "\n";
}

void
irandom (node * &head, int value, int k)
{
  node *n = new node (value);
  int current = 1;
  if (k == 1)
    {
      ihead (head, value);
      return;
    }
 node* temp = head;
  while (temp->next != NULL & current < k - 1)
    {
      temp = temp->next;
      current++;
    }
  node *nextptr = temp->next;
  temp->next = n;
  n->next = nextptr;
  return;
}

node *
reverse (node * &head)
{
  node *prevptr = NULL;
  node *currptr = head;
  node *nextptr;
  while (currptr != NULL)
    {
      nextptr = currptr->next;
      currptr->next = prevptr;
      prevptr = currptr;
      currptr = nextptr;
    }
  head = prevptr;
  return prevptr;
}

node *
reversebyrec (node * &head)
{				// REVERSE LINKED LIST BY RECURSION...
  if (head->next == NULL)
    {
      return head;
    }
  node *newhead = reversebyrec (head->next);
  head->next->next = head;
  head->next = NULL;
  return newhead;
}

node *
reverseknodes (node * &head, int k)
{
  int curr = 0;
  node *prevptr = NULL;
  node *currptr = head;
  node *nextptr;
  while (currptr != NULL && curr < k)
    {
      nextptr = currptr->next;
      currptr->next = prevptr;
      prevptr = currptr;
      currptr = nextptr;
      curr++;
    }
  if (currptr != NULL)
    {
      head->next = reverseknodes (currptr, k);
    }
  return prevptr;
}

void
delhead (node * &head)
{
  if (head == NULL)
    {
      return;
    }
  node *temp = head;
  head = head->next;
  delete temp;
}

void
del (node * &head, int value)
{
  if (head == NULL)
    {
      return;
    }
  if (head->data == value)
    {
      delhead (head);
      return;
    }
  node *temp = head;
  while (temp->next->data != value)
    {
      temp = temp->next;
    }
  node *n = temp->next;
  temp->next = temp->next->next;
  delete n;
}

void
print (node * head)
{
  node *temp = head;
  if (temp == NULL)
    {
      cout << "LIST IS EMPTY\n";
      return;
    }
  while (temp != NULL)
    {
      cout << temp->data << "->";
      temp = temp->next;
    }
  cout << "NULL" << endl;
  return;
}

int
main ()
{
  node *head = NULL;
  for (int i = 1; i < 6; i++)
    {
      irandom (head, i, i);
    }
    irandom(head,6,6);
  print (head);
  node *headnew = reversebyrec (head);
  print (headnew);
  head = reversebyrec (headnew);
  search (head, 9);
  search (head, 4);
  del (head, 4);
  print (head);
  headnew = reversebyrec (head);
  print (headnew);
  head = reversebyrec (headnew);
  del (head, 1);
  print (head);
  headnew = reverse (head);
  print (headnew);
  headnew = reverse (head);
  print (headnew);
  irandom (head, 1, 1);
  irandom (head, 4, 4);
  print (head);
  headnew = reverseknodes (head, 3);
  print (headnew);
  headnew = reverseknodes (headnew, 3);
  print (headnew);
}
