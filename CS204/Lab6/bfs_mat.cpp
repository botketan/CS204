#include <bits/stdc++.h>
using namespace std;

void bfs(int x,int n ,int*a,bool*b,bool* v)
{
        for (int i = 0; i < n; i++)
        {
            if(*(a+x*n+i)==1)
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
            if(*(a+x*n+i)==1 && b[i]==false)
            {            
                b[i]=true;     
                bfs(i,n,a,b,v);
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
            bfs(c,n,&a[0][0],b,vist);
        }
        
        c++;
    }
    
    
    
}