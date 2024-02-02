#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;

    vector<int> v;
    
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        v.push_back(num);
    }

    sort(v.begin(), v.end(), greater<>());

    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
}
