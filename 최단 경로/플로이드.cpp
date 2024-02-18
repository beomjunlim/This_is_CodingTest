#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define INF 1e9

int graph[501][501];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;

    for(int i=0; i<501; i++){
        fill(graph[i], graph[i]+501, INF);
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) graph[i][j] = 0;
        }
    }

    for(int i=0; i<m; i++){
        int a, b, c; // a에서 b로 가는 비용 c
        cin>>a>>b>>c;
        graph[a][b] = c;
    }

    // 플로이드 워셜 알고리즘
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(graph[i][j]==INF)
                cout<<"INFINITY"<<" ";
            else
                cout<<graph[i][j]<<" ";
        }
        cout<<'\n';
    }
}
