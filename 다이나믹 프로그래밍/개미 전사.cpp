#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 100
int dp[MAX];
int arr[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    dp[0] = arr[0];
    dp[1] = max(dp[0], arr[1]);

    for(int i=2; i<n; i++){
        dp[i] = max(dp[i-1], dp[i-2] + arr[i]);
    }

    cout<<dp[n-1];
}
