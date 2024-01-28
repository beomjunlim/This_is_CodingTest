#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
#include<queue>
#include<stack>
#include<climits>
using namespace std;

#define MAX 100001
bool visited[MAX];
int ans[MAX];

void bfs(int i, int k){
    queue<int> q;
    visited[i] = true;
    ans[i] = 0;    
    q.push(i);

    while(!q.empty()){
        int x = q.front();
        q.pop();
        visited[x] = true;
        if(x==1){
            cout<<ans[1];
            return;
        }
        
        if(x%k==0&&!visited[x/k]){
            ans[x/k] = ans[x] + 1;
            q.push(x/k);
        }
        if(!visited[x-1]){
            ans[x-1] = ans[x] +1;
            q.push(x-1);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,k;
    cin>>n>>k;

    bfs(n,k);

}
