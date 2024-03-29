#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define INF 1e9
#define MAX 101

int city[MAX][MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) 
                city[i][j] = 0;
            else 
                city[i][j] = INF;
        }
    }

    for(int i=0; i<m; i++){
        int a,b, c;
        cin>>a>>b>>c;
        city[a][b] = min(city[a][b], c);
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(city[i][j]== INF)
                cout<<0<<" ";
            else
                cout<<city[i][j]<<" ";
        }
        cout<<'\n';
    }
}
