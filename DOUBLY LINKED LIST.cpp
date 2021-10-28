#include<iostream>
using namespace std;
class node
{
public:node * prev;
  int data;
  node *next;
    node (int value)
  {
    data = value;
    prev = NULL;
    prev = NULL;
}};

void
tail (node * &head, int value)
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
  n->prev = temp;
}

void
ihead (node * &head, int value)
{
  node *n = new node (value);
  if (head == NULL)
    {
      head = n;
      return;
    }
  node *temp = head;
  temp->prev = n;
  n->next = temp;
  head = n;
}

void
delhead (node * &head)
{
  node *temp;
  node *todelete = head;
  temp = head->next;
  head = temp;
  temp->prev = NULL;
  delete todelete;
}

void
deltail (node * head)
{
  node *temp = head;
  while (temp->next != NULL)
    {
      temp = temp->next;
    }
  temp->prev->next = NULL;
  node *todelete = temp;
  delete todelete;
}

void
del (node * &head, int pos)
{
  if (pos == 1)
    {
      delhead (head);
      return;
    }
  node *temp = head;
  int count = 1;
  while (count != pos)
    {
      temp = temp->next;
      count++;
    }
  if (temp->next == NULL)
    {
      deltail (head);
      return;
    }
  node *todelete = temp;
  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;
  delete todelete;
}

void
prints (node * head)
{
  node *temp = head;
  while (temp != NULL)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
}

void
printr (node * head)
{
  node *temp = head;
  while (temp->next != NULL)
    {
      temp = temp->next;
    }
  while (temp != NULL)
    {
      cout << temp->data << " ";
      temp = temp->prev;
    }
}

int
main ()
{
  node *head = NULL;
  for (int i = 3; i > 0; i--)
    {
      tail (head, i);
  } for (int i = 4; i < 7; i++)
    {
      ihead (head, i);
    }
  prints (head);
  cout << endl;
  printr (head);
  cout << endl;
  del (head, 6);
  del (head, 1);
  del (head, 3);
  prints (head);
  cout << endl;
  printr (head);
}