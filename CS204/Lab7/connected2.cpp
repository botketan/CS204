#include <bits/stdc++.h>
using namespace std;

void dfs(int x,int n ,int * a,bool*b)
{
    if(b[x]==false)
    {
        b[x]=true;
        for (int i = 0; i < n; i++)
        {
            if(*(a+x*n+i)==1)
            {
                if(b[i]==false)
                {
                    dfs(i,n,a,b);
                }
            }
        }
    }
    
    
}

int main()
{
    int n,a1,a2,c,result;
    cin>>n;
    string temp;
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j]=0;
        }
    }
    bool b[n];
    result=n;
    while (1)
    {
        for (int i = 0; i < n; i++)
        {
            b[i]=false;   
        }
        cin>>temp;
        if(temp[0]=='$')
        break;
        a1 = stoi(temp);
        cin>>a2;
        dfs(a1-1,n,&a[0][0],b);
        if(b[a2-1]==false)
        result--;
        cout<<result<<endl;
        a[a1-1][a2-1]=1;
        a[a2-1][a1-1]=1;
    }
    
}