#include <bits/stdc++.h>
using namespace std;

/*void prevGreater(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        bool flag = false;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > arr[i])
            {
                cout << arr[j] << " ";
                flag = true;
                break;
            }
        }
        if (flag == false)
            cout << "- ";
    }
}*/
// stack approach
void prevGreater(int arr[], int size)
{
    stack<int> s;
    s.push(arr[0]);
    cout << "-";
    for (int i = 1; i < size; i++)
    {
        while (!s.empty() && s.top() <= arr[i])
        {
            s.pop();
        }
        if (s.empty())
            cout << "-";
        else
            cout << s.top() << " ";
        s.push(arr[i]);
    }
}

int main()
{
    int arr[] = {30, 50, 20, 15, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    prevGreater(arr, size);
    return 0;
}