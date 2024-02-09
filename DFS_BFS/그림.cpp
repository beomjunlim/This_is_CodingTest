#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 500
int n, m;
int arr[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool InRange(int x, int y)
{
  return 0 <= x && x < n && 0 <= y && y < m;
}

int bfs(int a, int b)
{
  queue<pair<int, int>> q;
  q.push({a, b});
  visited[a][b] = true;
  int photo = 1;

  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (InRange(nx, ny) && arr[nx][ny] == 1 && !visited[nx][ny])
      {
        photo++;
        visited[nx][ny] = true;
        q.push({nx, ny});
      }
    }
  }
  return photo;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }

  int sum = 0;
  int ans = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (arr[i][j] == 1 && !visited[i][j])
      {
        sum++;
        ans = max(ans, bfs(i, j));
      }
    }
  }

  cout << sum << '\n';
  cout << ans << '\n';
}
