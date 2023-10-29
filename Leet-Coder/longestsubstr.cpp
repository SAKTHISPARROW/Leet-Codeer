#include<iostream>
#include<vector>
using namespace std;
int lenofsub(string s) {
    int n = s.length();
    int maxLength = 0;
    vector<int> charIndex(128, -1);
    cout<<charIndex[100];
    int left = 0;
    
    for (int right = 0; right < n; right++) {
        if (charIndex[s[right]] >= left) {
            cout<<charIndex[s[right]];
            left = charIndex[s[right]] + 1;
        }
        charIndex[s[right]] = right;
        maxLength = max(maxLength, right - left + 1);
    }
    
    return maxLength;
}
int main(){
    char s[]="bbbbbbb";
    int ans = lenofsub(s);
    cout<<ans;
}