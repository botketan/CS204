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

int evaluate(struct node *p)
{
   if(p==NULL)
   return 0;
   string a = p->val;
   if(a=="+")
   {
     return evaluate(p->leftChild)+evaluate(p->rightChild);
   }
    else if(a=="-")
    {
        return evaluate(p->leftChild)-evaluate(p->rightChild);
    }
    else if(a=="*")
    {
        return evaluate(p->leftChild)*evaluate(p->rightChild);
    }
    else if(a=="/")
    {
        return evaluate(p->leftChild)/evaluate(p->rightChild);
    }
    else
    return stoi(a);
}


void prefix(struct node*p)
{
    if(p==NULL)
    return;
    cout<<p->val;
    prefix(p->leftChild);
    prefix(p->rightChild);
}

void postfix(struct node*p)
{
    if(p==NULL)
    return;
    postfix(p->leftChild);
    postfix(p->rightChild);
    cout<<p->val;
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
    cout<<evaluate(st.top())<<endl;
    
}