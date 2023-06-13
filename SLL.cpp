#include <iostream>
using namespace std;
struct node
{
    int data;
    node* link;
};
node * head=NULL;
void addnote(int d)
{
    node * newnode=new node;
    newnode->data=d;
    newnode->link=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        if(d<head->data)
        {
            newnode->link=head;
            head=newnode;
        }
        else
        {
        node* pre=NULL;
        node * cur=head;
        while(cur!=NULL && cur->data<d)
        {
            
            pre=cur;
            cur=cur->link;
            
        }
        newnode->link=cur;
        pre->link=newnode; }
    }
}
void delete_node(int d)
{
    node * pre=NULL;
    node * cur=head;
    
    while(cur!=NULL && cur->data!=d)
    {
        pre=cur;
        cur=cur->link;
    }
    if(cur==NULL)
    {
        cout<<"element not found";
    }
    else
    {
  if(cur==head)
  {
      head=head->link;
      cur->link=NULL;
      delete cur;
  }
  else
  {
    pre->link=cur->link;
    cur->link=NULL;
    delete cur; }}
}
void display_list()
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->link;
    }
}
void reverse_list()
{
    node *pre=NULL;
    node *cur=head;
    node *next=NULL;
    while(cur!=NULL)
    {
        next=cur->link;
        cur->link=pre;
        pre=cur;
        cur=next;
    }
    head=pre;
}
int main()
{
    addnote(12);
    addnote(25);
     addnote(23);
     addnote(7);
     addnote(97);
     addnote(63);
     addnote(56);
      display_list();
      cout<<"\n";
      reverse_list();
    display_list();
    reverse_list();
    cout<<"\n";
    display_list();
}
