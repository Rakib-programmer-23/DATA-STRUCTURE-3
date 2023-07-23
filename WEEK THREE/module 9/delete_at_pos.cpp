#include<bits/stdc++.h>
using namespace std;
class Node
{
    public :
        int val;
        Node* next;
        Node* prev;

        Node(int val)
        {
            this->val=val;
            this->next=NULL;
            this->prev=NULL;
        }

};
void print_normal(Node* head)
{
    Node* tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->val<<" ";
        tmp=tmp->next;
    }
    cout<<endl;
}
void print_reverse(Node* tail)
{
    Node* tmp=tail;
    while(tmp!=NULL)
    {
        cout<<tmp->val<<" ";
        tmp=tmp->prev;
    }
    cout<<endl;
}
void insert_at_pos(Node*head,int pos,int val)
{
    Node* newNode = new Node(val);
    Node* tmp = head;
     for(int i=1;i<pos-1;i++)
     {
        tmp=tmp->next;
     }
    newNode->next=tmp->next;
    tmp->next=newNode;
    newNode->next->prev=newNode;
    newNode->prev=tmp;

}
void insert_at_head(Node* &head,Node* &tail,int val)
{
    Node* newNode = new Node(val);
    if(head==NULL)
    {
        head=newNode;
        tail=newNode;
        return;
    }
    newNode->next=head;
    head->prev=newNode;
    head=newNode;

}
void insert_at_tail(Node* & head,Node*&tail,int val)
{
    Node* newNode = new Node(val);
    if(tail==NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next =newNode;
    newNode->prev= tail;
    tail = tail->next;
}
int size(Node* head)
{
    Node*tmp= head;
    int cnt=0;
    while(tmp!=NULL)
    {
        cnt++;
        tmp=tmp->next;
    }
    return cnt;
}
void delete_at_pos(Node* head,int pos)
{
    Node* tmp = head;

    for(int i=1; i<pos-1;i++)
    {
        tmp=tmp->next;
    }
    Node* deletenode= tmp->next;
    tmp->next=tmp->next->next;
    tmp->next->prev=tmp;
    delete deletenode;

}
void delete_at_tail(Node* tail)
{
    Node* deletenode = tail;
    tail = tail->prev;
    delete deletenode;
    tail->next = NULL;


}

int main()
{
    //Node* head= NULL; //head and tail both will be updated and same if they were NUll
    //Node* tail= NULL;

    Node*head= new Node(10);
    Node* a= new Node(20);
    Node* b= new Node(30);
    Node* c= new Node(40);
    Node* tail=c;
    
   

    //connection
    head->next=a;
    a->prev=head;
    a->next=b;
    b->prev=a;
    b->next=c;
    c->prev=b;

    int pos,val;
    cin>>pos;
    cin>>val;
    

    //delete_at_tail(tail);
    delete_at_pos(head,pos);
   

    print_normal(head);
    print_reverse(tail);
      
    return 0;
}