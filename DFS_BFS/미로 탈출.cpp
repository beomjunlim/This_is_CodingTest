/*미로 탈출
N*M 크기의 직사각형 형태의 미로에 갇혀 있다. 미로에는 여러 마리의 괴물이 있어 이를 피해 탈출해야 한다.
주인공의 위치는 (1,1)이고 출구는(N,M)의 위치에 존재하며 한번에 한 칸씩 이동할 수 있다.
이 때 괴물이 있는 부분은 0으로, 괴물이 없는 부분은 1로 표시되어 있다.
이 때 주인공이 탈출하기 위해 움직여야 하는 최소 칸의 개수를 구하시오.
첫째 줄에 두 정수 N,M(4<=N,M<=200)이 주어집니다. 다음 N개의 줄엥는 각각 M개의 정수(0,1)로 미로의 정보가 주어진다.
각각의 수들은 공백 없이 붙어서 입력으로 제시된다. 또한 시작 칸과 마지막 칸은 항상 1이다.
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define MAX 200
int n,m;
int arr[MAX][MAX];
int cnt[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

int bfs(int i, int j){
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    visited[i][j] = true;
    cnt[i][j] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(InRange(nx,ny)&&arr[nx][ny]==1&&!visited[nx][ny]){
                cnt[nx][ny] = cnt[x][y] + 1;
                visited[nx][ny] = true;
                q.push(make_pair(nx,ny));
            }            
        }
    }
    return cnt[n-1][m-1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &arr[i][j]);
        }
    }

    cout<<bfs(0,0);
}


