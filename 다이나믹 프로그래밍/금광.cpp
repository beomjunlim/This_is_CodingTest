#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

#define MAX 20
int arr[MAX+1][MAX+1];
int dp[MAX+1][MAX+1];
int dx[] = {0,-1,1};
int dy[] = {1,1,1};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;

    while(t>0){
        int n,m;
        cin>>n>>m;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cin>>arr[i][j];
            }
        }
        
        for(int i=1; i<=n; i++){
            dp[i][1] = arr[i][1];
        }

        for(int j=2; j<=m; j++){
            for(int i=1; i<=n; i++){
                if(i==1){
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j-1]) + arr[i][j];
                }
                else if(i==n){
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j-1]) + arr[i][j];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], max(dp[i+1][j-1], dp[i-1][j-1])) + arr[i][j];
                }
            }
        }
        
        int ans = 0;

        for(int i=1; i<=n; i++){
            ans = max(ans, dp[i][m]);
        }

        cout<<ans<<'\n';
        t--;
    }
}
