#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int val;
        int color;
        node* leftChild;
        node* rightChild;
        node* parent;

    void flipcolor()
    {
        color=(color+1)%2;
    }
    node(int v,int c){
        val = v;
        leftChild= NULL;
        rightChild = NULL;
        color = c;
    }
};

void infix(struct node*p)
{
    if(p==NULL)
    return;
    infix(p->leftChild);
    cout<<p->val;
    infix(p->rightChild);
}

void Leftrotate(struct node*p)
{
    struct node* temp = p->parent;
    p->parent = temp->parent;
    temp->leftChild = p->rightChild;
    p->rightChild = temp;
    if(p->parent->leftChild==temp)
    p->parent->leftChild = p;
    else
    p->parent->rightChild = p;
}

void Rightrotate(struct node*p)
{
    struct node* temp = p->parent;
    p->parent = temp->parent;
    temp->rightChild = p->leftChild;
    p->leftChild = temp;
    if(p->parent->leftChild==temp)
    p->parent->leftChild = p;
    else
    p->parent->rightChild = p;
}

void insertCheck(struct node* p)
{
    if(p->parent==NULL)
    {
        if(p->color=1)
        p->flipcolor();
        return;
    }
    if(p->parent->color=0)
    return;
    else
    {
        struct node * pa;
        struct node * g;
        pa = p->parent;
        g = p->parent->parent;
       
        if(pa==g->leftChild)
        {
            if(p==pa->rightChild)
            {
                Leftrotate(p);
            }
            if(g->rightChild->color=1)
            {
                pa->flipcolor();
                g->flipcolor();
                g->rightChild->flipcolor();
                insertCheck(g);
            }
            else
            {
                pa->flipcolor();
                g->flipcolor();
                Rightrotate(pa);
            }
        }
        else
        {
            if(p==pa->leftChild)
            {
                Rightrotate(p);
            }
            if(g->leftChild->color=1)
            {
                pa->flipcolor();
                g->flipcolor();
                g->leftChild->flipcolor();
                insertCheck(g);
            }
            else
            {
                pa->flipcolor();
                g->flipcolor();
                Leftrotate(pa);
            }
        }
    }

}

void insert( struct node**root,int v)
{
    cout<<"inserting \n";
    struct node *p = *root;
    while(1)
    {
        if(v>p->val)
        {
            if(p->rightChild==NULL)
            break;
            p = p->rightChild;
        }
        
        else
        {
            if(p->leftChild==NULL)
            break;
            p = p->leftChild;
        }
        
    }
    node* obj = new node(v,1);
    obj->parent = p;
    if(v>p->val)
    p->rightChild=obj;
    else
    p->leftChild = obj;
    insertCheck(obj);
}




int main()
{
    struct node* root = NULL;
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if(root==NULL)
        {
            node* obj = new node(a[i],0);
            obj->parent = NULL;
            root = obj;
        }
        else
        insert(&root,a[i]);
        cout<<i;
    }
    infix(root);
}
