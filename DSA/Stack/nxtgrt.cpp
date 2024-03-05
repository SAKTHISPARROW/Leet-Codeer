#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreater(int arr[], int size)
{
    vector<int> v;
    stack<int> s;
    s.push(arr[size - 1]);
    v.push_back(INT_MIN);

    for (int i = size - 2; i >= 0; i--)
    {
        while (s.empty() == false && s.top() <= arr[i])
            s.pop();
        int res = s.empty() ? INT_MIN : s.top();
        v.push_back(res);
        s.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}

int main()
{
    int arr[] = {30, 50, 20, 15, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int x : nextGreater(arr, size))
    {
        if (x == INT_MIN)
            cout << "- ";
        else
            cout << x << " ";
    }
    return 0;
}