#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        string val;
        node* leftChild;
        node* rightChild;

    node(string v){
        val = v;
    }
};


void prefix(node*p)
{
    stack<node*> st;
    st.push(p);
    struct  node *pt;
    
    while (!st.empty())
    {
        pt = st.top();
        st.pop();
        cout<<pt->val;
        if(pt->leftChild!=NULL)
        {
            st.push(pt->rightChild);
            st.push(pt->leftChild);
        }
    }
    
}

void postfix(node*p)
{
    stack<node*> st;
    st.push(p);
    struct  node *pt;
    stack<string> ot;
    while (!st.empty())
    {
        pt = st.top();
        st.pop();
        ot.push(pt->val);
        if(pt->leftChild!=NULL)
        {
            st.push(pt->leftChild);
            st.push(pt->rightChild);
        }
    }
    while (!ot.empty())
    {
        cout<<ot.top();
        ot.pop();
    }
}

int main()
{
    string s;
    cin>>s;
    stack <node*> st;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]=='(')
        continue;
        if(s[i]==')')
        {
            struct node *p1;
            struct node *p2;
            struct node *p3;
            p1= st.top();
            st.pop();
            p2= st.top();
            st.pop();
            p3= st.top();
            st.pop();
            p2->leftChild=p3;
            p2->rightChild=p1;
            st.push(p2);
        }
        
        else{
            string a="";
            if(s[i]-'0'<10&&s[i]-'0'>=0)
            {
                while (s[i]-'0'<10&&s[i]-'0'>=0)
                {
                    a+=s[i];
                    i++;
                }
                i--;
            }
            else
            {
                a=s[i];
            }
            node* obj = new node(a);
            obj->leftChild=NULL;
            obj->rightChild=NULL;
            st.push(obj);
        }
    }
    prefix(st.top());
    cout<<endl;
    postfix(st.top());
    cout<<endl;
    
    
}