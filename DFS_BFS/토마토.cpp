#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1000
int n, m;
int arr[MAX][MAX];
int cnt[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool InRange(int x, int y)
{
  return 0 <= x && x < m && 0 <= y && y < n;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  queue<pair<int, int>> tomato;
  cin >> n >> m;
  int sum = 0;
  int answer = 0;

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> arr[i][j];
      if (arr[i][j] == 1)
      {
        visited[i][j] = true;
        tomato.push({i, j});
      }
      if (arr[i][j] == 0)
        sum++;
    }
  }

  while (!tomato.empty())
  {
    int x = tomato.front().first;
    int y = tomato.front().second;
    tomato.pop();

    for (int i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (InRange(nx, ny) && arr[nx][ny] == 0 && !visited[nx][ny])
      {
        sum--;
        visited[nx][ny] = true;
        cnt[nx][ny] = cnt[x][y] + 1;
        tomato.push({nx, ny});
        answer = cnt[nx][ny];
      }
    }
  }

  if (sum != 0)
    cout << -1 << '\n';
  else
    cout << answer << '\n';
}
