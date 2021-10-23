#include<iostream>
using namespace std;

class node {
public: 
int data;
node *next;
node (int value) { data=value;next=NULL;}
};

void tail(node *&head,int value) { 
node *n=new node(value);
if(head==NULL) { head=n;return;}
node *temp=head;
while(temp->next!=NULL) { temp=temp->next;}
temp->next=n;
return;}

node* reverseknodes(node *&head,int k)
{
node *prev=NULL;
node *curr=head; node* nextptr;
int count=0;
while(curr!=NULL && count<k) { nextptr=curr->next;curr->next=prev;
prev=curr;
curr=nextptr;
count++;
}
if(curr!=NULL) { head->next=reverseknodes(nextptr,k);}
return prev;
}

void print(node *head) {
node *temp=head;
while(temp!=NULL) { cout<<temp->data<<" ";temp=temp->next;}
}

int main()
{
node *head=NULL;
for(int i=1;i<=6;i++) { tail(head,i);}
print(head); cout<<endl;
node *newhead=reverseknodes(head,2);
print(newhead);
}