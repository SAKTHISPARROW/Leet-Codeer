#include <iostream>
using namespace std;
int main()
{
    int arr[] = {3, 2, 1};
    int m = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (arr[i] > arr[j])
            {
                m++;
            }
        }
    }
    cout << m;
}