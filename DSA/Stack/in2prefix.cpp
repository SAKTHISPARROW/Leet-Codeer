#include <iostream>
#include <stack>
#include <string.h>

using namespace std;
// A utility function to check if the given character is operand
int checkIfOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// Fucntion to compare precedence
// If we return larger value means higher precedence
int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}

// The driver function for infix to postfix conversion
int getPostfix(char *expression)
{
    int i, j;
    stack<char> s;

    for (i = 0, j = -1; expression[i]; ++i)
    {
        // Here we are checking is the character we scanned is operand or not
        // and this adding to to output.
        if (checkIfOperand(expression[i]))
            expression[++j] = expression[i];

        // Here, if we scan the character ‘(‘, we need to push it to the stack.
        else if (expression[i] == '(')
            s.push(expression[i]);

        // Here, if we scan character is an ‘)’, we need to pop and print from the stack
        // do this until an ‘(‘ is encountered in the stack.
        else if (expression[i] == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                expression[++j] = s.top();
                s.pop();
            }
            if (!s.empty() && s.top() != '(')
                return -1; // invalid expression
            else
                s.pop();
        }
        else // if an opertor
        {
            while (!s.empty() && precedence(expression[i]) <= precedence(s.top()))
            {
                expression[++j] = s.top();
                s.pop();
            }
            s.push(expression[i]);
        }
    }

    // Once all inital expression characters are traversed
    // adding all left elements from stack to exp
    while (!s.empty())
    {
        expression[++j] = s.top();
        s.pop();
    }

    expression[++j] = '\0';
    return 0;
}

void reverse(char *exp)
{

    int size = strlen(exp);
    int j = size, i = 0;
    char temp[size];

    temp[j--] = '\0';
    while (exp[i] != '\0')
    {
        temp[j] = exp[i];
        j--;
        i++;
    }
    strcpy(exp, temp);
}
void brackets(char *exp)
{
    int i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
        i++;
    }
}
void InfixtoPrefix(char *exp)
{

    // reverse string
    reverse(exp);
    // change brackets
    brackets(exp);
    // get postfix
    getPostfix(exp);
    // reverse string again
    reverse(exp);

    cout << exp;
}

int main()
{
    char expression[] = "a+b*(c^d-e)^(f+g*h)-i";
    InfixtoPrefix(expression);
    return 0;
}