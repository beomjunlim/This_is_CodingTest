#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 50

int n,m;
int arr[MAX][MAX];
bool visited[MAX][MAX];


int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    int x,y,dir;
    cin>>x>>y>>dir;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    int cnt = 0;
    int sum = 0;
    visited[x][y] = true;
    
    while(1){
        if(cnt==4){
            dir = (dir+2)%4;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(InRange(nx,ny)&&arr[nx][ny]==0){
                x = nx;
                y = ny;
                visited[x][y] = true;
                sum++;
                cnt = 0;
                dir = (dir+2)%4;
            }
            else{
                break;
            }
        }

        dir = (dir+3)%4;
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(InRange(nx,ny)&&arr[nx][ny]==0&&!visited[nx][ny]){
            sum++;
            cnt = 0;
            x = nx;
            y = ny;
            visited[x][y] = true;
        }
        else{
            cnt++;
        }
    }
    cout<<sum;
}
