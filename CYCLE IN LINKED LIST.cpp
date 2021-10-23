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
makecycle (node * &head, int pos)
{
  int count = 1;
  node *temp = head;
  node *start;
  while (temp->next != NULL)
    {
      if (count == pos)
	{
	  start = temp;
	}
      count++;
      temp = temp->next;
    }
  temp->next = start;
}

void
detectcycle (node * head)
{
  node *slow = head;
  node *fast = head;
  while (fast != NULL && fast->next != NULL)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (fast == slow)
	{
	  cout << "CYCLE IS PRESENT IN LINKED LIST";
	  return;
	}
    }
  cout << "THERE IS NO CYCLE IN LINKED LIST";
}

void
removecycle (node * &head)
{
  node *slow = head;
  node *fast = head;
  while (1)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (fast == slow)
	{
	  break;
	}
    }
  fast = head;
  while (fast != slow)
    {
      fast = fast->next;
      slow = slow->next;
    }
  slow->next = NULL;
}

// FLOYD'S ALGORITHM...
void
print (node * head)
{
  node *temp = head;
  while (temp != NULL)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
}

int
main ()
{
  node *head = NULL;
  for (int i = 1; i <= 6; i++)
    {
      tail (head, i);
    }
  print (head);
  cout << endl;
  makecycle (head, 1);
  detectcycle (head);
  cout << endl;
  removecycle (head);
  detectcycle (head);
}
