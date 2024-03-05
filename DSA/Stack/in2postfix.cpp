#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
int ch(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int prec(char s)
{
    switch (s)
    {
    case '+':
    case '-':
        return 1;
    case '/':
    case '*':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}
int covertInfixToPostfix(char *expression)
{
    stack<char> s;
    int i, j;
    for (i = 0, j = -1; expression[i]; ++i)
    {
        if (ch(expression[i]))
            expression[++j] = expression[i];
        else if (expression[i] == '(')
        {
            s.push(expression[i]);
        }
        else if (expression[i] == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                expression[++j] = s.top();
                s.pop();
            }
            if (!s.empty() && s.top() != '(')
                return -1;
            else
                s.pop();
        }
        else
        {
            while (!s.empty() && prec(expression[i]) <= prec(s.top()))
            {
                expression[++j] = s.top();
                s.pop();
            }
            s.push(expression[i]);
        }
    }
    while (!s.empty())
    {
        expression[++j] = s.top();
        s.pop();
    }

    expression[++j] = '\0';
    printf("%s", expression);
    return 0;
}
int main()
{
    char expression[] = "a+b*(c^d-e)^(f+g*h)-i";
    covertInfixToPostfix(expression);
    return 0;
}