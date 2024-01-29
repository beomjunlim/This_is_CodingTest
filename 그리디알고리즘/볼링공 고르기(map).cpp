#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>
#include<climits>
#include<unordered_map>
using namespace std;

#define MAX 1000
int arr[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,k;
    unordered_map<int,int> m;
    cin>>n>>k;

    for(int i=0; i<n; i++){
        cin>>arr[i];
        m[arr[i]]++;
    }

    int cnt = 0;
    for(auto num : m){
        n -= num.second;
        cnt += num.second*n;
    }
    
    cout<<cnt;
}
