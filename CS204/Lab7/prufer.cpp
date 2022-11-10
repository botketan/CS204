#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a1,a2,c;
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
    while (1)
    {
        cin>>temp;
        if(temp[0]=='$')
        break;
        a1 = stoi(temp);
        cin>>a2;
        a[a1-1][a2-1]=1;
        a[a2-1][a1-1]=1;
    }
    int t=n-2;
    while (t)
    {
        for (int i = 0; i < n; i++)
        {
            c=0;
            for (int j = 0; j < n; j++)
            {
                if(a[i][j]==1)
                {
                    c++;
                    a1=j;
                }
            }
            if(c==1)
            {
                a[i][a1]=0;
                a[a1][i]=0;
                cout<<a1+1<<" ";
                break;
            }
        }
        t--;
    }
    
}