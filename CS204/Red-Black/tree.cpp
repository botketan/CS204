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

struct node* root = NULL;

int color(struct node*p)
{
    if (p== NULL)
    return 0;
    else
    return p->color;
}


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


void insertCheck(struct node* p)
{
    if(p->parent==NULL)
    {
        if(p->color==1)
        p->flipcolor();
        return;
    }
    if(p->parent->color==0)
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
            if(color(g->rightChild)==1)
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
                pa= p;
                p = p->rightChild;
            }
            if(g->leftChild!=NULL)
            {
                if(color(g->leftChild)==1)
                {
                    pa->flipcolor();
                    g->flipcolor();
                    g->leftChild->flipcolor();
                    insertCheck(g);
                }
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



void insert( struct node*p,int v)
{
    node* obj = new node(v,1);
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
    insertCheck(obj);
}

void check(struct node *p)
{
    if(p->parent==NULL)
    {
        if(p->color==1)
        p->flipcolor();
        return;
    }
    if(p->color==1)
    {
        p->flipcolor();
        return;
    }
    if(p==p->parent->leftChild)
    {
        struct node * y = p->parent->rightChild;
        if(y->color==1)
        {
            y->parent->flipcolor();
            Leftrotate(y);
            check(p);
        }
        else
        {
            if(color(y->leftChild)==0 && color(y->rightChild)==0)
            {
                y->flipcolor();
                check(y->parent);
            }
            else if (color(y->leftChild)==1 && color(y->rightChild)==0)
            {
                y->flipcolor();
                y->leftChild->flipcolor();
                Rightrotate(y->leftChild);
                check(p);
            }
            else if(color(y->rightChild)==1)
            {
                y->color = p->parent->color;
                p->parent->color =0;
                y->rightChild->flipcolor();
                Rightrotate(y);
            }
        }
    }
    else
    {
        struct node * y = p->parent->leftChild;
        if(color(y)==1)
        {
            y->parent->flipcolor();
            Rightrotate(y);
            check(p);
        }
        else
        {
            if(color(y->leftChild)==0 && color(y->rightChild)==0)
            {
                y->flipcolor();
                check(y->parent);
            }
            else if (color(y->leftChild)==0 && color(y->rightChild)==1)
            {
                y->flipcolor();
                y->rightChild->flipcolor();
                Leftrotate(y->leftChild);
                check(p);
            }
            else if(color(y->leftChild)==1)
            {
                y->color = p->parent->color;
                p->parent->color =0;
                y->leftChild->flipcolor();
                Leftrotate(y);
            }
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
            node* obj = new node(a[i],0);
            obj->parent = NULL;
            root = obj;
        }
        else
        insert(root,a[i]);
        cout<<i<<endl;
    }
    infix(root);
    cin>>n;
    del(search(root,n));
    infix(root);
}
