#include<iostream>
#include <bits/stdc++.h>
#include<stack>
using namespace std;

int prec(char c)
{
    if(c=='^')
    {
        return 3;
    }
    else if(c=='*' || c=='/')
    {
        return 2;
    }
    else if(c=='+' || c=='-')
    {
        return 1;
    }
    else{
        return -1;
    }
}

string infixtoprefix(string s)
{
    stack<int>st;
    string res;
    for(int i=s.length()-1;i>=0;i--)
    {
        if((s[i]>='a' && s[i] <='z') || s[i]>='A' && s[i] <='Z')
        {
            res+=s[i];
        }
        else if(s[i] == ')')
        {
            st.push(s[i]);
        }
        else if(s[i]=='(')
        {
            while(!st.empty() && st.top() != ')')
            {
                res+=st.top();
                st.pop();

            }

            //pop the expressin 
            if(! st.empty())
            {
                st.pop();
            }
        }
        //last precedency check.
        else
        {
            while(!st.empty() && prec(st.top())> prec(s[i]))
            {
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }

    }
    while(!st.empty())
    {
        res+=st.top();
        st.pop();
    }

    return reverse(res.begin(),res.end());;

}

int main()
{
    cout<<infixtoprefix("(a-b/c)*(a/k-l)")<<endl;
}