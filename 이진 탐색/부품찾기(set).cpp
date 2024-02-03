#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    
    unordered_set<int> part;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        part.insert(a);
    }

    int m;
    cin>>m;

    for(int i=0; i<m; i++){
        int a;
        cin>>a;

        if(part.find(a)!=part.end())
            cout<<"yes"<<" ";
        else
            cout<<"no"<<" ";
    }
}

