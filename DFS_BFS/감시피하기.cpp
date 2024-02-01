#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

#define MAX 6
int n;
char arr[MAX][MAX];
char cmp[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int,int>> space;
queue<pair<int,int>> teacher;
bool ans = false;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

bool fun(int x, int y, int dir){
    int nx = x;
    int ny = y;

    while(InRange(nx,ny)){
        if(cmp[nx][ny]=='O')
            break;
        if(cmp[nx][ny]=='S')
            return true;       
        nx = nx + dx[dir];
        ny = ny + dy[dir];
    }
    return false;
}

void bfs(){
    queue<pair<int,int>> q = teacher;
    bool sw = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int dir=0; dir<4; dir++){
            if(fun(x,y,dir))
                sw = false;
        }
    }
    
    if(sw)
        ans = true;
    else
        ans = false;
}

void myFunction(int num, int index){
    if(num==3){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cmp[i][j] = arr[i][j];
                if(visited[i][j])
                    cmp[i][j] = 'O';
            }
        }
        bfs();
        if(ans){
            cout<<"YES";
            exit(0);
        }
            return;
    }

    for(int i=index; i<space.size(); i++){
        int x = space[i].first;
        int y = space[i].second;
        if(!visited[x][y]){
            visited[x][y] = true;
            myFunction(num+1, i);
            visited[x][y] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j]=='X'){
                space.push_back({i,j});
            }
            if(arr[i][j]=='T'){
                teacher.push({i,j});
            }
        }
    }

    myFunction(0,0);
    cout<<"NO";
}
