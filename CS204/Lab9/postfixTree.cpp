#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        char val;
        node* leftChild;
        node* rightChild;

    node(char v){
        val = v;
    }
};


void prefix(struct node*p)
{
    if(p==NULL)
    return;
    cout<<p->val;
    prefix(p->leftChild);
    prefix(p->rightChild);
}


node* treeBuild(string s, char ch,string s2)
{
    
    string a="" ,b="",a2="",b2="";
    node * obj = new node(ch);
    if(s.length()==1)
    {
        obj->leftChild=NULL;
        obj->rightChild=NULL;
        return obj;
    }
    int i=0;
    while (s[i]!=ch)
    {
        a+=s[i];
        i++;
    }
    while (i<s.length())
    {
        b+=s[i];
        i++;
    }
    i=0;
    while (s2[i]!=b[b.length()-1])
    {
        a2+=s2[i];
        i++;
    }
    while (s2[i]!=ch)
    {
        b2+=s2[i];
        i++;
    }
    obj->leftChild=treeBuild(a,a2[a2.length()-1],a2);
    obj->rightChild=treeBuild(b,b2[b2.length()-1],b2);
    return obj;
}


int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    struct node* p = treeBuild(s1,s2[s2.length()-1],s2);
    prefix(p);
    cout<<endl;
    
}