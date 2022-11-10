#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,c,x,f;
    cin>>n;
    char t;
    int a[n];
    int b[n][n];
    for (int i = 0; i < n;i++)
    {
        for(int j =0;j<n;j++)
        b[i][j]=0;
    }
    
    for (int i = 0; i < n;i++)
    {
        c=0;
        cin>>t;
        while(t!='#')
        {
            x=t -'0';
            if(i!=x)
            {
                c++;
                b[i][x]=1;
            }
            cin>>t;
        }
        a[i]=c;
    }
    c=0;
    for(int i =0;i<n;i++)
    {
        if(a[i]%2==1)
        {
            c++;
            f=1;
            for(int j=0;j<n;j++ )
            {
                if(i!=j && a[j]%2==1 && b[i][j]==0)
                {
                    f=0;
                }
            }
            if(f)
            {
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    int z = c/2;
    cout<<z<<endl;
}