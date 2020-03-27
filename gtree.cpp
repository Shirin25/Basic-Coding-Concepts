#include<iostream>
#include<vector>
#include<stack>
#include <queue>
using namespace std;

class Node{
    public:
    int data=0;
    vector <Node*> childs;

    Node(int data)
    {
        this->data=data;
    }

};

int size(Node* root)
{
     int s=0;
     for(Node* child:root->childs)
     {
         s+=size(child);
     }

     return s+1;
}


int height(Node* root)
{
     int h=-1;
     for(Node* child:root->childs)
     {
         h=max(h,height(child));
     }

     return h+1;
}


bool find(Node * root, int data)
{
    if(root->data==data)
    return true;

    bool res=false;
    for(Node*child:root->childs)
    {
    res=res||find(child,data);
    }

    return res;
}

Node*createTree(vector<int> &arr)
{
    stack<Node*>st;
    for(int i=0;i<arr.size()-1;i++)
    {
        if(arr[i]==-1)
        {
            Node*node=st.top();st.pop();
            st.top()->childs.push_back(node);
        }

        else
        {
            st.push(new Node(arr[i]));
        }
    }

    return st.top();
}


void display(Node * node)
{   
    

    cout<<node->data<<"->";
    for(Node*child:node->childs)
    {
    cout<<child->data<<",";

    }

    
    cout<<endl;
    for(Node*child:node->childs)
    {
    display(child);
    }

    

    
}


vector<Node*> roottoNodepath(Node* node,int data)
{
    if(node->data==data)
    {    vector<Node*> base;
        base.push_back(node);
        return base;
    }
    for(Node*child:node->childs)
    {
        
        vector<Node*> childlist=roottoNodepath(child,data);
        if(childlist.size()!=0)
        {
        childlist.push_back(node);
        return childlist;
        }

        
    }
    vector<Node*>ans;
        return ans;
}

int lca(Node* node,int data1,int data2)
{
    vector<Node*>list1=roottoNodepath(node,data1);
    vector<Node*>list2=roottoNodepath(node,data2);

    int lca01=-1;

    int i=list1.size()-1;
    int j=list2.size()-1;

    while(i>=0&&j>=0)
    {
        if(list1[i]->data!=list2[j]->data)
        {
            break;
        }
        lca01=list1[i]->data;

        i--;
        j--;

    }

    return lca01;
}

void kaway(Node *node, Node *avoid, int level)
{
    if (node == avoid)
        return;

    if (level == 0)
    {
        cout << node->data << " ";
        return;
    }

    for (Node *child : node->childs)
    {
        kaway(child, avoid, level - 1);
    }
}

void kfar(Node *node, int k, int data)
{
    vector<Node *> list = roottoNodepath(node, data);
    Node *avoid = nullptr;

    for (int i = 0; i < list.size(); i++)
    {
        kaway(list[i], avoid, k - i);
        avoid = list[i];
    }
}

void levelOrderLineWise(Node *node)
{
    queue<Node *> que;
    que.push(node);
    int level = 0;

    while (que.size() != 0)
    {
        int size = que.size();

        cout << "Level: " << level << " -> ";
        while (size-- > 0)
        {
            Node *rnode = que.front();
            que.pop();
            cout << rnode->data << ", ";
            for (Node *child : rnode->childs)
            {
                que.push(child);
            }
        }

        level++;
        cout << endl;
    }
    cout << endl;
}

bool isSymmetricTree_(Node *node1, Node *node2)
{
    if (node1->childs.size() != node2->childs.size() || node1->data != node2->data)
        return false;

    for (int i = 0, j = node1->childs.size() - 1; i <= j; i++, j--)
    {
        Node *child1 = node1->childs[i];
        Node *child2 = node2->childs[j];

        if (!isSymmetricTree_(child1, child2))
            return false;
    }

    return true;
}

void isSymmetricTree(Node *node)
{
    cout << isSymmetricTree_(node, node) << endl;
}

bool isMirror(Node *node1, Node *node2)
{

    if (node1->childs.size() != node2->childs.size() || node1->data != node2->data)
        return false;

    for (int i = 0, j = node1->childs.size() - 1; j >= 0; i++, j--)
    {
        Node *child1 = node1->childs[i];
        Node *child2 = node2->childs[j];

        if (!isMirror(child1, child2))
            return false;
    }

    return true;
}

Node* gettail(Node*node)
{
    if(node->childs.size()==0) return node;

    return gettail(node->childs[0]);
}

void linearise(Node* node)
{
    for(Node*child:node->childs)
    {
        linearise(child);
    }

    for(int i=node->childs.size()-2;i>=0;i--)
    {
        Node*tail=gettail(node->childs[i]);
        tail->childs.push_back(node->childs[i+1]);
        node->childs.pop_back();
    }
}


Node* linearise_01(Node* node)
{
    if(node->childs.size()==0)return node;

    int n=node->childs.size();
    Node* Otail=linearise_01(node->childs[n-1]);

    for(int i=n-2;i>=0;i--)
    {
        Node* tail=linearise_01(node->childs[i]);
        tail->childs.push_back(node->childs[i+1]);
        node->childs.pop_back();
    }

    return Otail;




}

Node* removeleaf(Node* node)
{
    vector<Node*> nchilds;

    for(Node*child:node->childs)
    {
        if(child->childs.size()!=0)
        {
            nchilds.push_back(child);
        }
    }
    node->childs=nchilds;

    for(Node*child:node->childs)
    {
        removeleaf(child);
    }
}

void solve()
{
     vector<int> arr{10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 100, -1, 110, -1, -1, 90, -1, -1, 40, -1, -1};
    // vector<int> arr{10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 100, -1, 110, -1, -1, 90, -1, -1, 40,50,-1,60,-1, -1, -1};
    vector<int> arr1{10, 40, -1, 30, 90, -1, 80, 110, -1, 100, -1,-1, 70, -1, -1, 20, 60, -1, 50, -1, -1, -1};

    Node *node = createTree(arr);
    //display(node);
    // vector<Node*>result=roottoNodepath(node,80);

    // for(Node*ans:result)
    // {
    //     cout<<ans->data<<" ";
    // }
    // cout<<endl;

    // kfar(node, 2, 30);
     //cout<<lca(node,80,90);
    // // levelOrderLineWise(node);
    // // isSymmetricTree(node);

    // cout << isMirror(createTree(arr), createTree(arr1))<<endl;
    //linearise(node);
    //linearise_01(node);
    removeleaf(node);
    display(node);
}

int main()
{

solve();
return 0;



}


