#include <iostream>
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
}

void
ihead (node * &head, int value)
{
  node *n = new node (value);
  if (head == NULL)
    {
      head = n;
      return;;
    }
  n->next = head;
  head = n;
}

node *
sknts (node * &head, int pos)
{
  node *temp = head;
  int count = 1;
  node *after;
  while (count != pos)
    {
      temp = temp->next;
      if (temp->next == NULL)
	{
	  return head;
	}
      count++;
    }
  after = temp->next;
  temp->next = NULL;
  node *atemp = after;
  while (atemp->next != NULL)
    {
      atemp = atemp->next;
    }
  atemp->next = head;
  return after;
}

void
print (node * head)
{
  node *temp = head;
  while (temp != NULL)
    {
      cout << temp->data << "->";
      temp = temp->next;
    }
  cout << "NULL";
}

int
main ()
{
  node *head = NULL;
  for (int i = 3; i >= 1; i--)
    {
      ihead (head, i);
    }
  for (int i = 4; i <= 6; i++)
    {
      tail (head, i);
    } cout << "LINKED LIST IS: ";
  print (head);
  int k = 1;
  node *temp = head;
  while (temp->next != NULL)
    {
      temp = temp->next;
      k++;
    }
  cout << endl;
  node *newhead = head;
  for (int i = 1; i <= k; i++)
    {
      newhead = sknts (newhead, 1);
      cout << "IF POSITION IS " << i << " : ";
      print (newhead);
      cout << endl;
    }
}
