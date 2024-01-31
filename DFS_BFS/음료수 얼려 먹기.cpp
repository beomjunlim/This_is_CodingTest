/*음료수 얼려 먹기
N*M 크기의 얼음 틀이 있다. 구멍이 뚫려 있는 부분은 0, 칸막이가 존재하는 부분은 1로 표시된다.
구멍이 뚫려 있는 부분끼리 상, 하, 좌, 우로 붙어 있는 경우 서로 연결되어 있는 것으로 간주한다.
이때 얼음 틀의 모양이 주어졌을 때 생성되는 총 아이스크림의 개수를 구한느 프로그램을 작성하시오.
첫 번째 줄에 얼음 틀의 세로 길이 N과 가로 길이 M이 주어진다. (1<=N,M<=1,000)
두 번째 줄부터 N+1번째 줄까지 얼음 틀의 형태가 주어진다.
이때 구멍이 뚫려있는 부분은 0, 그렇지 않은 부분은 1이다.
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define MAX 1000
int n,m;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

void bfs(int i, int j){
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    visited[i][j] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(InRange(nx,ny)&&arr[nx][ny]==0&&!visited[nx][ny]){
                visited[nx][ny] = true;
                q.push(make_pair(nx,ny));
            }            
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int cnt = 0;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &arr[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]==0&&!visited[i][j]){
                cnt++;
                bfs(i,j);
            }
        }
    }
    cout<<cnt;
}

