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
void insert_at_pos(Node*& head, Node*& tail, int pos, int val, int sz)
{
    if (pos < 0 || pos > sz)
    {
        cout << "Invalid" << endl;
        return;
    }

    Node* newNode = new Node(val);
    Node* tmp = head;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else if (pos == 0)
    {
        newNode->next = tmp;
        if (tmp != NULL)
        {
            tmp->prev = newNode;
        }
        head = newNode;
    }
    else if (pos == sz)
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    else
    {
        for (int i = 1; i < pos; i++) 
        {
            tmp = tmp->next;
        }

        newNode->prev = tmp;
        newNode->next = tmp->next;
        if (tmp->next != NULL)
        {
            tmp->next->prev = newNode;
        }
        tmp->next = newNode;
    }
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

void print_from_left(Node* head)
{
    if (head == NULL)
    {
        return;
    }
    Node* tmp = head;
    cout << "L -> ";
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void print_from_right(Node* tail)
{
    if (tail == NULL)
    {
        return;
    }
    Node* tmp = tail;
    cout << "R -> ";
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}


int main()
{
    Node* head= NULL;
    Node* tail= NULL;
    int cnt=0;
    int Q;
    cin>>Q;
    while(Q--)
    {
        int pos;
        cin>>pos;

        int val;
        cin>>val;
        int sz= size(head);
        
         
        
        insert_at_pos(head,tail,pos,val,sz);
        if (pos >= 0 && pos <= sz)
        {
            print_from_left(head);
            print_from_right(tail);
        }
           
         
     
    }
    
    
    
    return 0;
}