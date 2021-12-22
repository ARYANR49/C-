#include<iostream>
using namespace std;

class node { 
    public:
    int data;
    node *next;
    node(int value) { data=value;next=NULL;}
};

void itail(node *&head,int value) {
node *n= new node(value);
if(head==NULL) { head=n; return;}
node *temp=head;
while(temp->next!=NULL) {
    temp=temp->next;
}
temp->next=n;
}

void ihead(node *&head,int value) {
node *n=new node(value);
n->next=head;
head=n;
}

void search(node *head,int value) {
node *temp=head;
while(temp!=NULL) { if(temp->data==value) {cout<<"ELEMENT FOUND: "<<value<<endl;return;} else{ temp=temp->next;}}
cout<<"ELEMENT NOT FOUND: "<<value<<"\n";
}

void delhead(node *&head) {
if(head==NULL) { return;}
node *temp=head;
head=head->next;
delete temp;
}

void del(node *&head,int value) {
if(head==NULL) { return;}
if(head->data==value) { delhead(head);return;} 
node *temp=head;
while(temp->next->data!=value) { temp=temp->next;}
node *n=temp->next;
temp->next=temp->next->next;
delete n;
}

void print(node *head) {
node* temp=head;
if(temp==NULL) { cout<<"LIST IS EMPTY\n";return;}
while(temp!=NULL) { cout<<temp->data<<"->"; temp=temp->next;}
cout<<"NULL"<<endl;
return;
}

int main() {
node *head=NULL;
print(head);
ihead(head,3);
ihead(head,2);
ihead(head,1);
itail(head,4);
itail(head,5);
itail(head,6);
print(head);
search(head,9);
search(head,4);
del(head,4);
print(head);
del(head,1);
print(head);
}