#include<bits/stdc++.h>
using namespace std;
class Node
{
    public :
        int val;
        Node* next;

        Node(int val)
        {
            this->val=val;
            this->next=NULL;
        }

};

void insert_at_tail(Node* &head,int v)
{
    Node* newnode= new Node(v);
    Node* tmp=head;
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    while(tmp->next!=NULL)
    {
    tmp=tmp->next;
    }
    tmp->next=newnode;

}
void duplicate(Node* head)
{
    if(head==NULL) return ;
    Node * tmp= head;
    while(tmp->next!= NULL)
    {
        if(tmp->val == tmp->next->val)
        {
            tmp->next= tmp->next->next;
        }
        if(tmp->next== NULL) break;
        else if(tmp->val != tmp->next->val)
        {
            tmp=tmp->next;
        }
    }
    
}

void  print_list(Node*head)
{
    Node* tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->val<<" ";
        tmp=tmp->next;
    }
    
}

int main()
{
    int val;
    Node* head=NULL;
    while(true)
    {
        cin>>val;
        if(val==-1)break;
        insert_at_tail(head,val);
    }
    
    Node* tmp=head;
    for(Node* i=tmp;i->next!=NULL;i=i->next)
    {
        for(Node* j=i->next;j!=NULL;j=j->next)
        {
            if(i->val > j->val)
            {
                swap(i->val , j->val);
            }
        }

    }
    duplicate(head);
    print_list(head);
    
      
    return 0;
}