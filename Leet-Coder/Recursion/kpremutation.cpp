#include <bits/stdc++.h>
using namespace std;
/*string getper(int n, int k)
{
    vector<int> num;
    int fact = 1;
    for (int i = 1; i < n; i++)
    {
        fact = fact * i;
        num.push_back(i);
    }
    cout << fact << endl;
    num.push_back(n);
    string a = "";
    k = k - 1;
    while (true)
    {
        a = a + to_string(num[k / fact]);
        num.erase(num.begin() + k / fact);
        if (num.size() == 0)
            break;
        k = k % fact;
        fact = fact / num.size();
    }
    return a;
}*/
void permutationHelper(string &s, int index, vector<string> &res)
{
    if (index == s.size())
    {
        cout << "inloop" << s << endl;
        res.push_back(s);
        return;
    }
    cout << "before " << s << endl;
    for (int i = index; i < s.size(); i++)
    {
        cout << "after " << s << endl;
        swap(s[i], s[index]);
        permutationHelper(s, index + 1, res);
        swap(s[i], s[index]);
    }
}

string getPermutation(int n, int k)
{
    string s;
    vector<string> res;
    // create string
    for (int i = 1; i <= n; i++)
    {
        s.push_back(i + '0');
    }
    permutationHelper(s, 0, res);
    // sort the generated permutations
    sort(res.begin(), res.end());
    // make k 0-based indexed to point to kth sequence
    auto it = res.begin() + (k - 1);
    return *it;
}
int main()
{
    int n = 3, k = 3;
    string ans = getPermutation(n, k);
    cout << ans;
    return 0;
}