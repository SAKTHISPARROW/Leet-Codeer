#include <iostream>
using namespace std;
int main()
{
    string s;
    double num = 0;
    cin >> s;
    int i = 0;
    while (s[i] == ' ')
    {
        i++;
    }
    bool pos = s[i] == '+';
    bool neg = s[i] == '-';
    pos == true ? i++ : i;
    neg == true ? i++ : i;
    while (i < s.length() && s[i] >= '0' && s[i] <= '9')
    {
        num = num * 10 + (s[i] - '0');
        i++;
    }
    num == neg ? -num : num;
    cout << num << endl;
    num = (num > INT_MAX) ? INT_MAX : num;
    num = (num < INT_MIN) ? INT_MIN : num;
    cout << num << endl;
}