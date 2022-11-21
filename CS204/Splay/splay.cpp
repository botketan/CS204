#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int val;
        node* leftChild;
        node* rightChild;
        node* parent;

    node(int v){
        val = v;
        leftChild= NULL;
        rightChild = NULL;
    }
};

struct node* root = NULL;

void prefix(struct node*p)
{
    if(p==NULL)
    return;
    cout<<p->val<<" ";
    prefix(p->leftChild);
    prefix(p->rightChild);
}

void infix(struct node*p)
{
    if(p==NULL)
    return;
    infix(p->leftChild);
    cout<<p->val<<" ";
    infix(p->rightChild);
}

void Leftrotate(struct node*p)
{
    struct node* pa = p->parent;
    struct node * g = p->parent->parent;
    if(g!=NULL)
    {
        if(pa == g->leftChild)
        g->leftChild = p;
        else
        g->rightChild =p;
    }
    p->parent = g;
    pa->parent =p;
    if(p->leftChild!=NULL)
    p->leftChild->parent = pa; 
    pa->rightChild = p->leftChild;
    p->leftChild = pa;

    if(g==NULL)
    root = p;
}

void Rightrotate(struct node*p)
{
    struct node* pa = p->parent;
    struct node * g = p->parent->parent;
    if(g!=NULL)
    {
        if(pa == g->leftChild)
        g->leftChild = p;
        else
        g->rightChild =p;
    }
    p->parent = g;
    pa->parent =p;
    if(p->rightChild!=NULL)
    p->rightChild->parent = pa; 
    pa->leftChild = p->rightChild;
    p->rightChild = pa;

    if(g==NULL)
    root = p;
}

void Check(struct node*p)
{
    if(p==NULL)
    return;
    struct node *pa = p->parent;
    if(pa==NULL)
    return;
    struct node *g = pa->parent;
    if(g==NULL)
    {
        if(p==pa->leftChild)
        Rightrotate(p);
        else
        Leftrotate(p);
    }
    else
    {
        if(pa==g->leftChild)
        {
            if(p==pa->rightChild)
            Leftrotate(p);
            else
            Rightrotate(pa);
            Rightrotate(p);
            Check(p);
        }
        else
        {
            if(p==pa->leftChild)
            Rightrotate(p);
            else
            Leftrotate(pa);
            Leftrotate(p);
            Check(p);
        }
    }
}

struct node * search(struct node*p,int x)
{
    if(p==NULL)
    return NULL;
    if(x==p->val)
    {
        struct node*temp = p;
        Check(p);
        return temp;
    }
    if(x>p->val)
    search(p->rightChild,x);
    else
    search(p->leftChild,x);
}






void insert( struct node*p,int v)
{
    node* obj = new node(v);
    if(p==NULL)
    {
        obj->parent = NULL;
        root = obj;
    }
    while(1)
    {
        if(v>p->val)
        {
            if(p->rightChild==NULL)
            {
                obj->parent = p;
                p->rightChild = obj;
                break;
            }
            else
            p = p->rightChild;
        }
        else
        {
            if(p->leftChild==NULL)
            {
                obj->parent = p;
                p->leftChild = obj;
                break;
            }
            else
            p = p->leftChild;
        }
    }
    cout<<"Inserted\n";
    Check(obj);
}


void del(struct node *p)
{
    
    if(p == NULL)
    {
        cout<<"No such element"<<endl;
        return;
    }
    if(p->leftChild!=NULL && p->rightChild!=NULL)
    {
        struct node *pt = p->leftChild;
        struct node *rightT = p->rightChild;
        root = p->leftChild;
        while(pt->rightChild!=NULL)
        {
            pt= pt->rightChild;
        }
        Check(pt);
        root->rightChild = rightT;
    }
    else
    {
        if(p->leftChild!=NULL)
                root = p->leftChild;
        else
                root = p->rightChild;
        if(root!=NULL)
            root->parent = NULL;
        free(p);
    }
}


int main()
{
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
            node* obj = new node(a[i]);
            obj->parent = NULL;
            root = obj;
        }
        else
        insert(root,a[i]);
        cout<<i<<endl;
    }
    prefix(root);
    cin>>n;
    struct node *p = search(root,n);
    prefix(root);
    cin>>n;
    del(search(root,n));
    infix(root);
    cout<<"\n";
    prefix(root);
}
