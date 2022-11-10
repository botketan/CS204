#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,c,f=1,z;
    cin>>n;
    char t;
    for (int i = 0; i < n;i++)
    {
        c=0;
        cin>>t;
        while(t!='#')
        {
            z=t -'0';
            if(i!=z)
            c++;
            cin>>t;
        }
        if(c%2==1)
        {
            f=0;
        }
    }
    if(f)
    cout<<"true"<<endl;
    else
    cout<<"false"<<endl;
}