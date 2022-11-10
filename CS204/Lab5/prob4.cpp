#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,x,c=0,z;
    cin>>n>>m;
    int a[n],b[m];
    for (int i = 0; i <n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i <m; i++)
    {
        cin>>b[i];
    }
    int s[n];
    for (int i = 0; i < n; i++)
    {
        s[i]=0;
    }
    for (int i = 0; i < n; i++)
    {
        if(a[n-i-1]<0)
        {
            a[n-i-1]+=10;
            a[n-i-2]--;
        }
        if(m-i-1<0)
        {
            z = a[n-i-1];
        }
        else
        {
            z = a[n-i-1]-b[m-i-1];
            if(z<0)
            {
                z+=10;
                a[n-i-2]--;
            }
        }
        s[n-i-1] = z;
    }
    for (int i = 0; i < n; i++)
    {
        if(s[i]!=0)
        c=1;
        if(c)
        cout<<s[i];
    }
}