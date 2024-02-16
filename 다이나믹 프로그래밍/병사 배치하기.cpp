#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

#define MAX 2000
int arr[MAX];
int dp[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    fill(dp, dp+n, 1);
    
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j]>arr[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int ans = 0;

    for(int i=0; i<n; i++){
        ans = max(ans, dp[i]);
    }

    cout<<n-ans;
}
