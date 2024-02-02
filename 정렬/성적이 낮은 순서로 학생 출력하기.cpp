#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<string,int> a, pair<string, int> b){
    return a.second<b.second;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;

    vector<pair<string,int>> v;

    for(int i=0; i<n; i++){
        string s;
        int a;
        cin>>s>>a;
        v.push_back({s,a});
    }

    sort(v.begin(), v.end(), cmp);

    for(int i=0; i<n; i++){
        cout<<v[i].first<<" ";
    }
}
