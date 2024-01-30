#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<char> v;
    string s;
    cin>>s;

    int sum = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i]-'0'>=0&&s[i]-'0'<10){
            sum += s[i]-'0';
        }
        else{
            v.push_back(s[i]);
        }
    }

    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        cout<<v[i];
    }
    cout<<sum<<'\n';
}
