#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

#define MAX_N 100
#define MAX_M 10000
int dp[MAX_M+1];
int arr[MAX_N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr, arr+n);

    fill(dp, dp+m+1, 99999);
    dp[0] = 0;

    for(int i=1; i<=m; i++){
        for(int j=0; j<n; j++){
            if(i>=arr[j]){
                dp[i] = min(dp[i], dp[i-arr[j]] + 1);
            }
        }
    }

    if(dp[m]==99999)
        cout<<-1;
    else
        cout<<dp[m];

}
