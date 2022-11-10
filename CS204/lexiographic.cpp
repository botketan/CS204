#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int n,i,j;
    cin>>n;
    int a[n];
    for ( i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int t=0;
    for ( i = n-1; i >=0 ; i--)
        { 
            if(a[i]>a[i-1])
                 {
                    j=i;
                    t=1;
                    break;
                 }
        }
    if(t==1)
    {
        for ( i = n-1; i >=j ; i--)
        {
            if(a[j-1]<a[i])
                {
                    swap(a[j-1],a[i]);
                    break;
                }
        }
        reverse(a+j,a+n);
        for(i=0;i<n;i++)
        {
            cout << a[i] <<endl;
        }
    }
else
    {
    cout << "-1";
    } 
}