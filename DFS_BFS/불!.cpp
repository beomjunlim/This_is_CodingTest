#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define MAX 1000

int n,m;
char arr[MAX][MAX];
int fire_cnt[MAX][MAX];
int jihun_cnt[MAX][MAX];
bool jihun_visited[MAX][MAX];
bool fire_visited[MAX][MAX];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    queue<pair<int,int>> fire;
    queue<pair<int,int>> jihun;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(arr[i][j]=='F'){
                fire_visited[i][j] = true;
                fire.push({i,j});
            }
            if(arr[i][j]=='J'){
                jihun_visited[i][j] = true;
                jihun.push({i,j});
            }
        }
    }

    while(!fire.empty()){
        int x = fire.front().first;
        int y = fire.front().second;
        fire.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(InRange(nx,ny)&&arr[nx][ny]!='#'&&!fire_visited[nx][ny]){
                fire_cnt[nx][ny] = fire_cnt[x][y] + 1;
                fire.push({nx,ny});
                fire_visited[nx][ny] = true;
            }
        }
    }

    while(!jihun.empty()){
        int x = jihun.front().first;
        int y = jihun.front().second;
        jihun.pop();

        if(x==n-1||x==0||y==m-1||y==0){
            cout<<jihun_cnt[x][y] + 1<<'\n';
            return 0;
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!InRange(nx,ny)||arr[nx][ny]!='.'||jihun_visited[nx][ny]) continue;
            if(fire_visited[nx][ny]&&jihun_cnt[x][y] + 1 >= fire_cnt[nx][ny]) continue;

            jihun_cnt[nx][ny] = jihun_cnt[x][y] + 1;
            jihun.push({nx,ny});
            jihun_visited[nx][ny] = true;
        }
    }

    cout<<"IMPOSSIBLE"<<'\n';
}
