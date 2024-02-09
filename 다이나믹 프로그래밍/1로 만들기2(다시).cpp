#include <iostream>
#include <queue>
using namespace std;

#define MAX 1000000
int parent[MAX + 1];
int dp[MAX + 1];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  for (int i = 2; i <= n; i++)
  {
    dp[i] = dp[i - 1] + 1;
    parent[i] = i - 1;
    if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
    {
      dp[i] = dp[i / 2] + 1;
      parent[i] = i / 2;
    }
    if (i % 3 == 0 && dp[i] > dp[i / 3] + 1)
    {
      dp[i] = dp[i / 3] + 1;
      parent[i] = i / 3;
    }
  }

  cout << dp[n] << '\n';

  while (1)
  {
    cout << n << " ";
    if (n == 1)
      break;
    n = parent[n];
  }
}
