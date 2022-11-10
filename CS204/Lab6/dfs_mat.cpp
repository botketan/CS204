#include <bits/stdc++.h>
using namespace std;

void dfs(int x,int n ,int*a,bool*b)
{
    if(b[x]==false)
    {
        cout<<x<<" ";
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
    int n,c=0;
    cin>>n;
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>a[i][j];
        }
        
    }
    bool b[n];
    for (int i = 0; i < n; i++)
    {
        b[i]=false;   
    }
    while (c<n)
    {
        if(b[c]==false)
        dfs(c,n,&a[0][0],b); 
        c++;
    }
    
    
    
}