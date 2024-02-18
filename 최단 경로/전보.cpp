#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define INF 1e9
#define MAX 30001

vector<pair<int,int>> city[MAX];
int dist[MAX];

void dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()){
        int distance = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dist[now] < distance) continue;

        for(int i=0; i<city[now].size(); i++){
            int cost = distance + city[now][i].second;
            if(cost < dist[city[now][i].first]){
                dist[city[now][i].first] = cost;
                pq.push({-cost, city[now][i].first});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,c;
    cin>>n>>m>>c;

    for(int i=0; i<m; i++){
        int x,y,z;
        cin>>x>>y>>z;
        city[x].push_back({y,z});
    }

    fill(dist, dist+ MAX, INF);

    dijkstra(c);

    int count = 0;
    int maxDistance = 0;

    for(int i=1; i<=n; i++){
        if(dist[i] != INF){
            count += 1;
            maxDistance = max(maxDistance, dist[i]);
        }
    }

    cout<<count-1<<" "<<maxDistance<<'\n';
}
