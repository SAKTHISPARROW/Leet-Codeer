#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    vector<pair<int, string>> romens = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
    for (int i = 0; i < romens.size(); i++)
    {
        while (n >= romens[i].first)
        {
            s += romens[i].second;
            n -= romens[i].first;
        }
    }
    cout << s;
    return 0;
}