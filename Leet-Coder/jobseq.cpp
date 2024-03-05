#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
int main()
{
    int n = 4;
    vector<vector<int>> v = {{1, 4, 20}, {2, 1, 10}, {3, 2, 40}, {4, 2, 30}};
    auto comparator = [](const std::vector<int> &a, const std::vector<int> &b)
    {
        // Compare the vectors based on their elements (assuming all vectors have the same length)
        if (a[2] != b[2])
        {
            return a[2] > b[2]; // Compare elements at index i
        }
        return false; // If all elements are equal, the vectors are considered equal
    };
    sort(v.begin(), v.end(), comparator);
    size_t index = 1; // Index for which you want to find the maximum element

    int maxElement = numeric_limits<int>::min(); // Initialize maxElement with the minimum possible value for an int

    // Iterate through the vectors and find the maximum element at the specified index
    for (const auto &innerVec : v)
    {
        if (index < innerVec.size())
        {                                                  // Make sure the index is within bounds for the inner vector
            maxElement = max(maxElement, innerVec[index]); // Update maxElement if a larger element is found
        }
    }
    cout << maxElement << endl;
    for (const auto &innerVec : v)
    {
        for (int elem : innerVec)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
    vector<int> vec(maxElement, 0);
    for (int i = 1; i <= maxElement; i++)
    {
        if (vec[v[i - 1][1]] == 0)
        {
            // cout << v[i - 1][1] << " " << v[i - 1][2] << endl;
            vec[v[i - 1][1]] = v[i - 1][2];
            cout << v[i - 1][1];
        }
        else if (vec[v[i - 1][1]] != 0 && vec[v[i - 1][1] - 1] == 0)
        {
            vec[v[i - 1][1] - 1] = v[i - 1][2];
        }
        else if (vec[v[i - 1][1]] != 0 && vec[v[i - 1][1] - 1] != 0)
        {
            break;
        }
    }
    for (int x : vec)
        cout << x << " ";

    return 0;
}