#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define MAX 300001
int n,m,k,x;
vector<int> arr[MAX];
int cnt[MAX];
bool visited[MAX];
vector<int> v;


void bfs(){
    queue<int> q;
    q.push(x);
    visited[x] = true;
    cnt[x] = 0;

    while(!q.empty()){
        int num = q.front();
        q.pop();

        if(cnt[num]==k)
            v.push_back(num);

        for(int i=0; i<arr[num].size(); i++){
            if(!visited[arr[num][i]]){
                visited[arr[num][i]] = true;
                cnt[arr[num][i]] = cnt[num] + 1;
                q.push(arr[num][i]);
            }
        }

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m>>k>>x;
    

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        arr[a].push_back(b);
    }

    bfs();

    if(v.empty())
        cout<<-1;

    else{
        sort(v.begin(), v.end());
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<'\n';
        }
    }

}
