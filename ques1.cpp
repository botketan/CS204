#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> a;

void heapify(int i,int n)
{
    pair<int,int> t;
    double d1,d2,d3;
    int c= floor(n/2);
    while (i<=c-1)
    {
        d1 = sqrt((a[i].first*a[i].first)+(a[i].second*a[i].second));
        d2 = sqrt((a[2*i+1].first*a[2*i+1].first)+(a[2*i+1].second*a[2*i+1].second));
        if(2*i+2>=n)
        d3 = INT32_MAX;
        else
        d3 = sqrt(a[2*i+2].first*a[2*i+2].first+a[2*i+2].second*a[2*i+2].second);
        if(d1<=d2 && d1<=d3)
        break;
        else if(d2<d3)
        {
            t = a[i];
            a[i]= a[2*i+1];
            a[2*i+1]=t;
            i= 2*i+1;
        }
        else
        {
            t = a[i];
            a[i]= a[2*i+2];
            a[2*i+2]=t;
            i= 2*i+2;
        }
    }
    
}

int main()
{
    int n,x,y;
    cin>>n;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin>>x>>y;
        a[i].first=x;a[i].second=y ;
    }
    int c= floor(n/2)-1;
    for(int i =c;i>=0;i--)
    {
        heapify(i,n);
    }
    pair<int,int> t;
    for (int i = 0; i <n; i++)
    {
        cout<<a[0].first<<" "<<a[0].second<<endl;
        t = a[0];
        a[0]= a[n-i-1];
        a[n-i-1]=t;
        heapify(0,n-i-1);
    }
}