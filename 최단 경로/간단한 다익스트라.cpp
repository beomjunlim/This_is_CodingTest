#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> graph[10001];
bool visited[10001];
int dis[10001];
int n, m, start;

int getSmallestNode()
{
  int index = 0;
  int min_num = INT_MAX;
  for (int i = 1; i <= n; i++)
  {
    if (dis[i] < min_num && !visited[i])
    {
      min_num = dis[i];
      index = i;
    }
  }
  return index;
}

void dijkstra(int start)
{
  dis[start] = 0;
  visited[start] = true;

  for (int i = 0; i < graph[start].size(); i++)
  {
    dis[graph[start][i].first] = graph[start][i].second;
  }

  for (int i = 0; i < n - 1; i++)
  {
    int next = getSmallestNode();
    visited[next] = true;
    for (int j = 0; j < graph[next].size(); j++)
    {
      int cost = dis[next] + graph[next][j].second;
      if (cost < dis[graph[next][j].first])
        dis[graph[next][j].first] = cost;
    }
  }
}

int main()
{
  cin >> n >> m >> start;

  for (int i = 0; i < m; i++)
  {
    int a, b, num;
    cin >> a >> b >> num;
    graph[a].push_back({b, num});
  }
  fill_n(dis, 10001, INT_MAX);
  dijkstra(1);

  for (int i = 1; i <= n; i++)
  {
    if (dis[i] == INT_MAX)
      cout << "도달 불가" << '\n';
    else
      cout << dis[i] << '\n';
  }
}
