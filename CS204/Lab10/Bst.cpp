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
        leftChild = NULL;
        rightChild = NULL;
    }
};

void prefix(struct node*p)
{
    if(p==NULL)
    return;
    cout<<p->val<<" ";
    prefix(p->leftChild);
    prefix(p->rightChild);
}

void inorder(struct node *p)
{
    if(p==NULL)
    return;
   
    inorder(p->leftChild);
    cout<<p->val<<" ";
    inorder(p->rightChild);
}

void postfix(struct node*p)
{
    if(p==NULL)
    return;
    postfix(p->leftChild);
    postfix(p->rightChild);
    cout<<p->val<<" ";
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

void insert(struct node *p,int x)
{
    node* obj = new node(x);
    while (1)
    {
        if(x>p->val)
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
        }
        else
        {
            if(p->parent->leftChild==p)
            p->parent->leftChild = p->rightChild;
            else
            p->parent->rightChild = p->rightChild;
        }
        free(p);
    }
}


int main()
{
    int n,x;
    struct node *root = NULL;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>x;
        if(i==0)
        {
            node* obj = new node(x);
            obj->parent = NULL;
            root = obj;
        }
        else
        {
            struct node *p = search(root,x);
            if(p==NULL)
            insert(root,x);
        }
    }
    inorder(root);
    cin>>x;
    struct node *p = search(root,x);
    if(p==NULL)
    cout<<"NOT FOUND"<<endl;
    else
    cout<<"FOUND"<<endl;
    cin>>x;
    struct node* loc = search(root,x);
    del(loc);
    inorder(root);
    cin>>x>>n;
    loc = search(root,n);
    if(loc==NULL)
    {
        loc = search(root,x);
        if(loc == NULL)
        cout<<"NO such element"<<endl;
        else
        {
            del(loc);
            insert(root,n);
        }
    }
    inorder(root);
}