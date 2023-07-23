#include<bits/stdc++.h>
using namespace std;
class Node
{
    public :
        string val;
        Node* next;
        Node* prev;

        Node(string val)
        {
            this->val=val;
            this->next=NULL;
            this->prev=NULL;
        }

};

void website(Node* & head,Node*&tail,string s)
{
    Node* newNode = new Node(s);
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


Node* find(Node* head, string sites) 
{
    Node* tmp = head;
   
    while (tmp != NULL) 
    {
        if (tmp->val == sites) 
        {
            cout << tmp->val << endl;
            return tmp;
        }
        //previousNode = tmp->prev;  
        tmp = tmp->next;
    }
    cout << "Not Available" << endl;
   
   return NULL;
}

void previous(Node* head, Node*& current) 
{
    
    if (current == NULL || current->prev == NULL) 
    {
        cout << "Not Available" << endl;
        return;
    }
    current = current->prev;
    cout << current->val << endl;
}

void next(Node* head, Node*& current) 
{
    
    if (current == NULL || current->next == NULL) 
    {
        cout << "Not Available" << endl;
        return;
    }
    current = current->next;
    cout << current->val << endl;
    
}



int main() 
{
    Node* head = NULL;
    Node* tail = NULL;
    while (true) 
    {
        string s;
        cin >> s;
        if (s == "end") break;
        website(head, tail, s);
    }
    int Q;
    cin >> Q;
    
    Node* current = NULL;
    while (Q--) 
    {
        string command;
        cin >> command;
        if (command == "visit") 
        {
            string sites;
            cin >> sites;
            Node* findit = find(head, sites);
            if(findit!=NULL)
            {
                current=findit;
            }
           
            
        } 
       
        else if (command == "prev") 
        {
           
            
            previous(head, current);
            
        } 
        
        else if (command == "next") 
        {
          
            next(head, current);
        }
     
        
      
        
        
    } 
    
    
   
    return 0;
}


















