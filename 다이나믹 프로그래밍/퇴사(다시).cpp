#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

#define MAX 15
int day[MAX];
int pay[MAX];
int dp[MAX+1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>day[i]>>pay[i];
    }

    int ans = 0;
    for(int i=n-1; i>=0; i--){
        if(n>=i+day[i])
            dp[i] = max(dp[i+1], dp[i+day[i]] + pay[i]);
        else
            dp[i] = dp[i+1];
        ans = max(ans, dp[i]);
    }

    cout<<ans;
}
