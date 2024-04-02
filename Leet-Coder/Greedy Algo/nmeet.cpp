#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct meeting
{
    int start;
    int end;
    int pos;
};
class nmet
{
public:
    bool static comp(struct meeting m1, struct meeting m2)
    {
        if (m1.end < m2.end)
            return true;
        else if (m1.end > m2.end)
            return false;
        else if (m1.pos < m2.pos)
            return true;
        return false;
    }
    void maxmet(int s[], int e[], int n)
    {
        struct meeting meet[n];
        for (int i = 0; i < n; i++)
        {
            meet[i].start = s[i];
            meet[i].end = e[i];
            meet[i].pos = i + 1;
        }
        sort(meet, meet + n, comp);
        vector<int> m;
        int limit = meet[0].end;
        m.push_back(meet[0].pos);
        for (int j = 1; j < n; j++)
        {
            if (meet[j].start > limit)
            {
                limit = meet[j].end;
                m.push_back(meet[j].pos);
            }
        }
        for (int k = 0; k < m.size(); k++)
        {
            cout << m[k] << " ";
        }
    }
};
int main()
{
    nmet obj;
    int s[] = {1, 3, 0, 5, 8, 5};
    int e[] = {2, 4, 6, 7, 9, 9};
    int n = 6;
    obj.maxmet(s, e, n);
    return 0;
}