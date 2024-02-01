#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

#define MAX 201
int n,k,s,x,y;
struct Virus{
    int x;
    int y;
    int v;
};

vector<Virus> virus;
int arr[MAX][MAX];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<x&&x<=n&&0<y&&y<=n;
}

bool cmp(Virus a, Virus b){
    return a.v < b.v;
}

void bfs(){
    int size = virus.size();
    for(int i=0; i<size; i++){
        for(int j=0; j<4; j++){
            int nx = virus[i].x + dx[j];
            int ny = virus[i].y + dy[j];
            if(InRange(nx,ny)&&arr[nx][ny]==0){
                arr[nx][ny] = virus[i].v;
                virus.push_back({nx,ny, virus[i].v});
            }
        }
    }
    virus.erase(virus.begin(), virus.begin()+size);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>k;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
            if(arr[i][j]!=0){
                virus.push_back({i,j,arr[i][j]});
            }
        }
    }

    cin>>s>>x>>y;
    sort(virus.begin(), virus.end(), cmp);

    for(int i=0; i<s; i++){
        bfs();
    }

    cout<<arr[x][y];
}
