#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,x,c=0,z,f =0;
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
    x = max(n,m);
    int s[x+1];
    for (int i = 0; i < x; i++)
    {
        s[i]=0;
    }
    for (int i = 0; i < x; i++)
    {
        if(n-i-1<0 && m-i-1<0)
        break;
        else if(n-i-1<0)
        {
            z = b[m-i-1]+c;
            c=z/10;
            z = z%10;
        }
        else if(m-i-1<0)
        {
            z = a[n-i-1]+c;
            c=z/10;
            z = z%10;
        }
        else
        {
            z = a[n-i-1]+b[m-i-1]+c;
            c = z/10;
            z = z%10;
        }
        s[x-i] = z;
    }
    s[0]=c;
    for (int i = 0; i < x+1; i++)
    {
        if(s[i]!=0)
        f=1;
        if(f)
        cout<<s[i];
    }
}