#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class LRU
{
    list<int> ll;
    unordered_map<int,char>map;
    int defaultSize=4;

    void set(int key,char val)
    {
        if(map.find(key)==map.end())
        {
            if(ll.size==defaultSize)
            {
                int lastkey=ll.back();
                ll.pop_back();
                map.erase(lastkey);
            }

            ll.push_front(key);
            map[key]=val;
        }

        else
        {
            ll.remove(key);
            ll.push_front(key);
            map[key]=val;

        }
    }

    int get(int key)
    {
        if(map.find(key)!=map.end())
         return -1;
    
    else
    {
        ll.remove(key);
        ll.push_front(key);
        return map[key];
    }
    }


}






class LinkedList{

public:
class Node
{
    public:
    int data=0;
    
    Node* next=nullptr;
    Node(int data)
    {
        this->data=data;
    }
};



Node*head=nullptr;
Node*tail=nullptr;
int size=0;

public:
    ~LinkedList()
    {
        Node *temp = head;
        while (head != nullptr)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }


void addFirst(int data)
{
    Node* node=new Node(data);
    if(head==nullptr)
    {
        head=node;
        tail=node;
    }
    else
    {

        node->next=head;
        head=node;

    }

    size++;
}

void addLast(int data)
{
    Node*node=new Node(data);
    if(tail==nullptr)
    {
        head=node;
        tail=node;
    }

    else
    {
        tail->next=node;
        tail=node;
    }
    size++;
}

int removeFirst()
{  Node* rn=head;
    if(head!=nullptr)
    {
        if(size==1)
        {
            tail=nullptr;
        }

        rn=head;
        head=head->next;

        
    }

    int data=rn!=nullptr?rn->data:-1;
    delete rn;
    return data;
    size--;
}

Node* getNodeAt(int idx)
{
    if(idx==0)
    return head;

    Node* temp=head;

    while(idx!=0)
    {
      temp=temp->next;
      idx--;
    }

    return temp;
}

int removeLast()
{
    Node* rn=nullptr;

    if(head!=nullptr)
    {
        if(size==1)
        {
            rn=tail;
            tail=nullptr;
            head= nullptr;
        }
    }

    else
    {
        Node* temp=getNodeAt(size-2);
        rn=tail;
        temp->next=nullptr;
        tail=temp;
    }
    size--;
    int data=rn!=nullptr?rn->data:-1;
    delete rn;
    return data;
}

void Addat(int idx,int data)
{
    if(idx>size||idx<0)
    return;

    if(idx==0)
    addFirst(data);
    if(idx==size)
    addLast(data);

    else
    {
        Node* prev=getNodeAt(idx-1);
        Node*next=prev->next;

        Node* node=new Node(data);
        prev->next=node;
        node->next=next;
        
    }

    size++;
}

void removeAt(int idx)
{
    if(idx<0||idx>size)
    {
        return;
    }
    if(idx==0)
    removeFirst();

    if(idx==size)
    removeLast();

    else
    {
        Node* node=nullptr;
        Node*prev=getNodeAt(idx-1);
        Node*next=prev->next;

        
        prev->next=next->next;
        size--;
        delete next;

        
    }
}

Node* mid()
{
    Node*slow=head;
    Node*fast=head;

    while(fast!=nullptr&&fast->next!=nullptr&&fast->next->next!=nullptr)
    {
        fast=fast->next->next;
        slow=slow->next;
    }

    return slow;
}

void display()
{
    Node* curr=head;
    while(curr!=nullptr)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}


class pairReverse{
    public:
    Node* prevNode=nullptr;

};

void reversedatarec(Node* node,pairReverse*prev, int level)
{
    if(node==nullptr)
    return;

    reversedatarec(node->next,prev,level+1);
    if(level>this->size/2)
    {
        int temp=prev->prevNode->data;
        prev->prevNode->data=node->data;
        node->data=temp;
        prev->prevNode=prev->prevNode->next;

    }

}

void reverse()
{
    pairReverse* r=new pairReverse();
    r->prevNode=head;
    reversedatarec(head,r,0);
}

Node* reverseList_(Node*node)
{
    Node* prev=nullptr;
    Node* curr=node;

    while(curr!=nullptr)
    {
        Node* forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
    
}

void reverseList()
{
    Node *prev = reverseList_(head);

        tail = head;
        head = prev;
}



bool isPalindrome()
{
    Node* midNode=mid();
    Node*nhead=midNode->next;
    midNode->next=nullptr;

    Node*prev=reverseList_(nhead);

    Node*list1=prev;
    Node*list2=head;
    bool flag=true;
    

    while(list1!=nullptr&&list2!=nullptr)
    {
        if(list1->data!=list2->data)
        {
            flag=false;

        }
        list1=list1->next;
        list2=list2->next;

        prev=reverseList_(nhead);
        midNode->next=nhead;

        return flag;
    }

}

void fold()
{
    Node* midNode=mid();
    Node* nhead=midNode->next;
    midNode->next=nullptr;

Node* prev=reverseList_(nhead);

Node*list2=prev;
Node*list1=head;

while(list1!=nullptr&&list2!=nullptr)
{
    Node* temp1=list1->next;
    list1->next=list2;
    Node* temp2=list2->next;
    
    list2->next=temp1;
    list1=temp1;
    list2=temp2;
    
}
if(list2==nullptr)
{
    tail=list1;
}
else
tail=nhead;


}

Node*addFirst_(Node*node)
{
    if(head==nullptr)
    {
        head=node;tail=node;

    }

    else{
        node->next=head;
        head=node;
    }
    size++;
    return node;
}
Node*removeFirst_(Node*node)
{
    node=head;
    if(head!=nullptr)
    {
        if(size==1)
        {
            tail=nullptr;
        }
        node=head;
        head=head->next;
    }
    Node*ans=node!=nullptr?node->next:nullptr;
    delete node;
    return ans;
    size--;
}



void unfold()
{
    LinkedList l1;
    LinkedList l2;
    while(head!=nullptr)
    {
        Node*temp1=removeFirst_(head);
        l1.addFirst_(temp1);
        Node*temp2=removeFirst_(head);
        l2.addFirst_(temp2);

    }
    l1.display();
    l2.display();
}
private:
Node*deleteCycle_()
{
    Node*slow=head;
    Node*fast=head;
    while(fast!=nullptr&&fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)
        {
            return slow;
        }

        return nullptr;

    }
}
public:
bool deleteCycle()
{
   return deleteCycle_!=nullptr;

}
int intersectionPoint()
{
    Node*node1=deleteCycle_();
    if(node1!=nullptr)
    {
        Node*node2=head;
        while(node2!=slow)
        {
            node1=node1->next;
            node2=node2->next;
        }
        return slow->data;
    }
    return -1;
}
};



void solve()
{
    LinkedList ll;
    
    for(int i=1;i<=5;i++)
    {
        ll.addLast(i*10);
    }

    // for(int i=10;i>=1;i--)
    // {
    //     ll.addLast(i*10);
    // }
    //ll.removeAt(3);
    //ll.Addat(3,45);
    //ll.display();
    
    //ll.reverse();
    //ll.display();

    //ll.display();
    //ll.rverseList();
    ll.display();
    //cout<<ll.isPalindrome()<<endl;
    ll.fold();
   // ll.addLast(23);
    ll.display();
    ll.unfold();
    ll.display();
}

int main()
{
    solve();
    return 0;
}


