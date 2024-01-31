#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

#define MAX 8
int n,m;
int arr[MAX][MAX];
int tmp[MAX][MAX];
bool visited[MAX][MAX];
bool wall[MAX][MAX];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
vector<pair<int,int>> space;
vector<int> infection;
queue<pair<int,int>> virus;

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

int bfs(){
    queue<pair<int,int>> q = virus;
    int cnt = 3;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(InRange(nx,ny)&&tmp[nx][ny]==0&&!visited[nx][ny]){
                cnt++;
                visited[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }
    return cnt;
}


void MakeWall(int cnt, int index){
    if(cnt==3){
        memset(visited, false, sizeof(visited));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                tmp[i][j] = arr[i][j];
                if(wall[i][j])
                    tmp[i][j] = 1;
            }
        }

        infection.push_back(bfs());
        return;
    }

    for(int i=index; i<space.size(); i++){
        int x = space[i].first;
        int y = space[i].second;
        if(!wall[x][y]){
            wall[x][y] = true;
            MakeWall(cnt+1, i);
            wall[x][y] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    int sum = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(arr[i][j]==2){
                virus.push({i,j});
            }
            else if(arr[i][j]==0){
                sum++;
                space.push_back({i,j});
            } 
        }
    }
    
    MakeWall(0,0);
    sort(infection.begin(), infection.end());
    cout<<sum-infection[0];
}
