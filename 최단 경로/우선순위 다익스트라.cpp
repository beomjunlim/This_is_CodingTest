#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define INF 1e9

int n, m, start;
vector<pair<int,int>> graph[100001];
int dist[100001];

void dijkstra(int start){
    priority_queue<pair<int,int>> pq;

    pq.push({0,start});
    dist[start] = 0;

    while(!pq.empty()){
        int d = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dist[now] < d) continue;

        for(int i=0; i<graph[now].size(); i++){
            int cost = d + graph[now][i].second;

            if(cost < dist[graph[now][i].first]){
                dist[graph[now][i].first] = cost;
                pq.push({-cost, graph[now][i].first});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
    cin>>n>>m>>start;

    // 총 간선
    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c; // a에서 b로 갈 때 c의 비용이 든다.
        graph[a].push_back({b,c});
    }    

    fill(dist, dist + 100001, INF);

    dijkstra(start);

    // 총 노드
    for(int i=1; i<=n; i++){
        if(dist[i]==INF)
            cout<<"INFINITY"<<'\n';
        else
            cout<<dist[i]<<'\n';
    }
}
