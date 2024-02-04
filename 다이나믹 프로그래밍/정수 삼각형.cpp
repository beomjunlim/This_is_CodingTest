#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 500
int arr[MAX][MAX];
int dp[MAX][MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n; 

    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cin>>arr[i][j];
        }
    }

    dp[0][0] = arr[0][0];

    for(int i=1; i<n; i++){
        for(int j=0; j<i+1; j++){
            if(j==0)
                dp[i][j] = dp[i-1][j] + arr[i][j];

            else if(j==i)
                dp[i][j] = dp[i-1][j-1] + arr[i][j];
            
            else
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];
        }
    }

    int ans = 0;
    
    for(int i=0; i<n; i++){
        ans = max(ans, dp[n-1][i]);
    }

    cout<<ans;

}
