#include <bits/stdc++.h>
using namespace std;
void valid(string s)
{
    int count = 0;
    stack<char> c;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{')
        {
            c.push(s[i]);
        }
        else if (s[i] == '}' || s[i] == ')')
        {
            char top = c.top();
            if (c.empty())
            {
                cout << "Invalid";
            }
            if (s[i] == ')' && top == '(' || s[i] == '}' && top == '{')
            {
                count += 1;
                c.pop();
            }
            else
            {
                cout << "Invalid";
            }
        }
    }
    if (!c.empty())
    {
        cout << "Invalid";
    }
    cout << "Valid:" << count * 2;
}
int main()
{
    string s = "((()()";
    valid(s);
    return 0;
}