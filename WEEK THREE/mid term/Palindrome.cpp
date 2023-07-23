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
void insert_at_tail(Node* &head, Node* &tail, int val)
 {
        Node* newnode = new Node(val);

        if (head == NULL) {
            head = newnode;
            tail = newnode;
            return;
        }

        tail->next = newnode;
        tail = tail->next;
}

void reverse(Node* &head, Node* cur)
 {
        if (cur->next == NULL) {
            head = cur;
            return;
        }

        reverse(head, cur->next);
        cur->next->next = cur;
        cur->next = NULL;
}

bool isPalindrome(Node* head,Node* newhead)
 {
        Node* tmp = head;
        Node* tmp1 = newhead;

        while (tmp != NULL && tmp1 != NULL)
        {
            if (tmp->val != tmp1->val) {
                return false;
            }
            tmp = tmp->next;
            tmp1 = tmp1->next;
        }

        return true;
}

int main()
{
    Node* newhead=NULL;
    Node* newtail=NULL;
    Node* head = NULL;
    Node* tail= NULL;
    Node* tmp= head;
    while(true)
    {
        int val;
        cin>>val;
        if(val==-1) break;
        insert_at_tail(newhead,newtail,val);
        insert_at_tail(head,tail,val);
    }
    
    reverse(head,head);
    bool palindrome = isPalindrome(head, newhead);
    if (palindrome) 
    {
        cout << "YES";
    } else 
    {
        cout << "NO";
    }
    return 0;
}