#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool chkpair(char v, char u)
{
    if (v == '(' && u == ')' || v == '{' && u == '}' || v == '[' && u == ']')
    {
        return true;
    }
    return false;
}
bool bal(string s)
{
    stack<char> c;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            c.push(s[i]);
        }
        else
        {
            if (s.empty())
            {
                return false;
            }
            else if (chkpair(c.top(), s[i]))
            {
                c.pop();
                continue;
            }
            return false;
        }
    }
    return c.empty();
}
int main()
{
    string s = "{([]]}";
    (bal(s)) ? cout << "Balanced" : cout << "Not Balanced";
    return 0;
}