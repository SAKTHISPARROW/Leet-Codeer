#include <iostream>
#include <vector>
using namespace std;
/*void merge(vector<int> &p, int low, int mid, int high)
{
    vector<int> temp;
    int le = low;
    int re = mid + 1;
    while (le <= mid && re <= high)
    {
        if (p[le] <= p[re])
        {
            temp.push_back(p[le]);
            le++;
        }
        else
        {
            temp.push_back(p[re]);
            re++;
        }
    }
    while (le <= mid)
    {
        temp.push_back(p[le]);
        le++;
    }
    while (re = high)
    {
        temp.push_back(p[re]);
        re++;
    }
    for (int i = low; i <= high; i++)
    {
        p[i] = temp[i - low];
    }
}
int countpair(vector<int> &p, int low, int mid, int high)
{
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && p[i] > p[right] * 2)
        {
            right++;
            cnt += (right - (mid + 1));
        }
    }
    return cnt;
}
int mergesort(vector<int> &p, int low, int high)
{
    int cnt = 0;
    if (low >= high)
    {
        return cnt;
    }
    int mid = (low + high) / 2;
    cnt += mergesort(p, low, mid);
    cnt += mergesort(p, mid + 1, high);
    cnt += countpair(p, low, mid, high);
    merge(p, low, mid, high);
    return cnt;
}
int team(vector<int> &skill, int n)
{
    return mergesort(skill, 0, n - 1);
}
int main()
{
    vector<int> p = {2, 4, 3, 5, 1};
    int n = p.size();
    // int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (p[i] < p[j])
            {
                continue;
            }
            else if (p[i] > p[j] * 2)
            {
                cout << i << j << endl;
                count++;
            }
        }
    }
    int cnt = team(p, n);
    cout << cnt;
}*/

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr

    // storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > 2 * arr[right])
            right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);        // left half
    cnt += mergeSort(arr, mid + 1, high);   // right half
    cnt += countPairs(arr, low, mid, high); // Modification
    merge(arr, low, mid, high);             // merging sorted halves
    return cnt;
}

int team(vector<int> &skill, int n)
{
    return mergeSort(skill, 0, n - 1);
}

int main()
{
    vector<int> a = {4, 1, 2, 3, 1};
    int n = 5;
    int cnt = team(a, n);
    cout << "The number of reverse pair is: "
         << cnt << endl;
    return 0;
}