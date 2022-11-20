#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int val;
        int height;
        node* leftChild;
        node* rightChild;
        node* parent;

    node(int v,int c){
        val = v;
        leftChild= NULL;
        rightChild = NULL;
        height = c;
    }
};

struct node* root = NULL;

void infix(struct node*p)
{
    if(p==NULL)
    return;
    infix(p->leftChild);
    cout<<p->val;
    infix(p->rightChild);
}

void prefix(struct node*p)
{
    if(p==NULL)
    return;
    cout<<p->val<<" ";
    prefix(p->leftChild);
    prefix(p->rightChild);
}


int height(struct node*p)
{
    if(p==NULL)
    return 0;
    else
    return p->height;
}

int getBalance(node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->leftChild) - 
           height(N->rightChild); 
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

    pa->height = 1+ max(height(pa->leftChild),height(pa->rightChild));
    p->height = 1+ max(height(p->leftChild),height(p->rightChild));
    if(g!=NULL)
    g->height = 1+ max(height(g->leftChild),height(g->rightChild));
    else
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

    pa->height = 1+ max(height(pa->leftChild),height(pa->rightChild));
    p->height = 1+ max(height(p->leftChild),height(p->rightChild));
    if(g!=NULL)
    g->height = 1+ max(height(g->leftChild),height(g->rightChild));
    else
    root = p;
}


void check(struct node *p)
{
    while(p!=NULL)
    {
        p->height = 1+max(height(p->leftChild),height(p->rightChild));
        int c = getBalance(p);
        if(c>1)
        {
            if(getBalance(p->leftChild)>=0)
            Leftrotate(p->leftChild->rightChild);
            Rightrotate(p->leftChild);
        }
        else if(c<-1)
        {
            if(getBalance(p->rightChild)>0)
            Rightrotate(p->rightChild->leftChild);
            Leftrotate(p->rightChild);
        }  
        p= p->parent;
    }

}


void insert( struct node**root, int v)
{
    struct node *p = *root;
    if(v>p->val)
    {
        if(p->rightChild==NULL)
        {
            node* obj = new node(v,1);
            obj->parent = p;
            p->rightChild=obj;
        }
        else
        {
            insert(&p->rightChild,v);
        }
    }  
    else
    {
        if(p->leftChild==NULL)
        {
            node* obj = new node(v,1);
            obj->parent = p;
            p->leftChild=obj;
        }
        else
        {
            insert(&p->leftChild,v);
        }
    }
    p->height = 1+max(height(p->leftChild),height(p->rightChild));
    int c = height(p->leftChild)-height(p->rightChild);
    if(c>1)
    {
        if(v>p->leftChild->val)
        Leftrotate(p->leftChild->rightChild);
        Rightrotate(p->leftChild);
    }
    if(c<-1)
    {
        if(v<p->rightChild->val)
        Rightrotate(p->rightChild->leftChild);
        Leftrotate(p->rightChild);
    }  
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
        while(pt->rightChild!=NULL)
        {
            pt= pt->rightChild;
        }
        swap(pt->val,p->val);
        del(pt);
    }
    else
    {
        if(p->leftChild!=NULL)
        {
            if(p->parent->leftChild==p)
            p->parent->leftChild = p->leftChild;
            else
            p->parent->rightChild = p->leftChild;
            p->leftChild->parent = p->parent;
        }
        else
        {
            if(p->parent->leftChild==p)
            p->parent->leftChild = p->rightChild;
            else
            p->parent->rightChild = p->rightChild;
            if(p->rightChild!=NULL)
            p->rightChild->parent = p->parent;
        }
        check(p->parent);
        free(p);
    }
}

struct node * search(struct node*p,int x)
{
    if(p==NULL)
    return NULL;
    if(x==p->val)
    return p;
    if(x>p->val)
    search(p->rightChild,x);
    else
    search(p->leftChild,x);
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
            node* obj = new node(a[i],1);
            obj->parent = NULL;
            root = obj;
        }
        else
        insert(&root, a[i]);
    }
    // infix(root);
    prefix(root);
    cin>>n;
    del(search(root,n));
    prefix(root);
}