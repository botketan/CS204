#include <bits/stdc++.h>
using namespace std;

void bfs(int x,int n ,int a[][],bool*b,bool* v)
{
        for (int i = 0; i < n; i++)
        {
            if(a[x][i]==1)
            {
                if(v[i]==false)
                {
                    cout<<i<<" ";
                    v[i]= true;
                }
            }
        }
    for (int i = 0; i < n; i++)
        {
            if(a[x][i]==1 && b[i]==false)
            {            
                b[i]=true;     
                bfs(i,n,a,b,v);
            }
        }
    
}

int main()
{
    int n,c=0,x;
    cin>>n;
    char t;
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j]=0;
        }
        
    }
    for (int i = 0; i < n;i++)
    {
        cin>>t;
        while(t!='#')
        {
            x=t -'0';           
            a[i][x]=1;
            cin>>t;
        }
    }
    bool b[n],vist[n];
    for (int i = 0; i < n; i++)
    {
        b[i]=false;
        vist[i]=false;   
    }
    while (c<n)
    {
        if(b[c]==false)
        {
            b[c]=true;
            vist[c]=true;
            cout<<c<<" ";
            bfs(c,n,a,b,vist);
        }
        c++;
    }
    
    
    
}