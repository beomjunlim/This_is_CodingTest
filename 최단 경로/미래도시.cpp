#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define INF 1e9
#define MAX 100

int n, m;
int company[MAX+1][MAX+1];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    for(int i=0; i<101; i++){
        fill(company[i], company[i] + 101, INF);
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) company[i][j] = 0;
        }
    }

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        company[a][b] = 1;
        company[b][a] = 1;
    }

    int x, y;
    cin>>x>>y;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                company[j][k] = min(company[j][k], company[j][i] + company[i][k]);
            }
        }
    }

    int distance = company[1][y] + company[y][x];

    if(distance >= INF)
        cout<<"-1"<<'\n';
    else
        cout<<distance<<'\n';
}
