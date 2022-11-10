#include<bits/stdc++.h>
using namespace std;



int main()
{
    string s;
    cin>>s;
    int a,b;
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        int x = s[i]-'0';
        if(x<10&&x>=0)
        {              
            st.push(x);
        }
        else
        {
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            switch(s[i])
            {
                case '+':
                b = a+b;
                break;
                case '-':
                b = b-a;
                break;
                case '*':
                b= b*a;
                break;
                case '/':
                b= b/a;
                break;
                default:
                break;
            }
            st.push(b);
        }
    }
    cout<<st.top()<<endl;
    
}