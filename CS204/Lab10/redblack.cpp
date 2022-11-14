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
    struct node* pa = p->parent;
    struct node * g = p->parent->parent;
    if(pa == g->leftChild)
    g->leftChild = p;
    else
    g->rightChild =p;
    p->parent = g;
    pa->parent =p;
    if(p->leftChild!=NULL)
    p->leftChild->parent = pa; 
    pa->rightChild = p->leftChild;
    p->leftChild = pa;
}

void Rightrotate(struct node*p)
{
    struct node* pa = p->parent;
    struct node * g = p->parent->parent;
    if(pa == g->leftChild)
    g->leftChild = p;
    else
    g->rightChild =p;
    p->parent = g;
    pa->parent =p;
    if(p->rightChild!=NULL)
    p->rightChild->parent = pa; 
    pa->leftChild = p->rightChild;
    p->rightChild = pa;
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
            if(g->rightChild->color==1)
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
                if(g->leftChild->color==1)
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
        if(p->color==1)
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
        insert(root,a[i]);
        cout<<i<<endl;
    }
    infix(root);
}