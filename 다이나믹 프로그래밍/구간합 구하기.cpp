#include <iostream>
using namespace std;

#define MAX 100000
int arr[MAX + 1];
int dp[MAX + 1];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  dp[0] = 0;

  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
    dp[i] = dp[i - 1] + arr[i];
  }

  while (m > 0)
  {
    int a, b;
    cin >> a >> b;
    cout << dp[b] - dp[a] + arr[a] << '\n';
    m--;
  }
}
