#include <bits/stdc++.h>
using namespace std;


void add(int *a,int *b,int n,int m, int *s)
{
    int x,c=0,z,f =0;
    x = max(n,m);
    for (int i = 0; i < x; i++)
    {
        s[i]=0;
    }
    for (int i = 0; i < x; i++)
    {
        z = a[n-i-1]+b[m-i-1]+c;
        c = z/10;
        z = z%10;
        s[x-i-1] = z;
    }
    s[0]=c;
}

int main()
{
    int n,m,x,c1=0,c2=0,z,c=0,f =0;
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
    x= n+m+1;
    int s[x],temp[x],ans1[x];
    for (int i = 0; i <x; i++)
    {
        s[i]=0;
    }
    for (int i = 0; i < m; i++)
    {
        c1=0;
        for (int k = 0; k < x; k++)
        {
            temp[k]=0;
        }
        for (int j = 0; j < n; j++)
        {
            z = a[n-j-1]*b[m-i-1]+c1;
            c1 = z/10;
            z = z%10;
            temp[x-j-1-i]= z;
        }
        temp[x-n-1-i]=c1;
        add(temp,s,x,x,ans1);
        for (int k = 0; k < x; k++)
        {
            s[k]=ans1[k];
        }
    }
    for (int i = 0; i < x; i++)
    {
        if(s[i]!=0)
        f=1;
        if(f)
        cout<<s[i];
    }
    cout<<endl;
}