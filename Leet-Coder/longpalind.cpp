#include<iostream>
#include<string>
using namespace std;

void islong(string s,int i,int j){
    string ans=s.substr(i,j);
    cout<<ans;
    cout<<"\n";
}
int main(){
    string s="cbbd";
    //cout<<s.size();
    if(s.size()<=1){
        cout<<s;
    }
    for(int i=0;i<s.size()-1;i++){
        for(int j=i+1;j<s.size();j++){
            if(s[i]==s[j]) islong(s,i,j);
        }
    }
}