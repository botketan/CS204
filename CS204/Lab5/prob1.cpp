#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,c,x,f=1;
    cin>>n;
    for (int i = 0; i < n;i++)
    {
        c=0;
        for(int j =0;j<n;j++)
        {
            cin>>x;
            if(x==1)
            c++;
        }
        if(c%2==1)
        {
            cout<<i<<endl;
            f=0;
        }
    }
    
    if(f)
    cout<<-1<<endl;
}