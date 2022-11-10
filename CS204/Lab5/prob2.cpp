#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,c,x,f=1;
    cin>>n;
    char t;
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
            }
            cin>>t;
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