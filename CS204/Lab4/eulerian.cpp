#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,c,t,f=1;
    cin>>n;
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>a[i][j];
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        c=0;
        for (int j = 0; j < n; j++)
        {
            if(a[i][j]==1&& i!=j)
            c++;
        }
        if(c%2==1)
        {
            cout<<"false"<<endl;
            return 0;
        }
    }
    cout<<"true"<<endl;
}