#include <iostream>
using namespace std;

#define MAX 300

int arr[MAX + 1];
int dp[MAX + 1][3];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }

  dp[1][1] = arr[1];
  dp[1][0] = 0;

  for (int i = 2; i <= n; i++)
  {
    dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
    dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + arr[i];
    dp[i][2] = dp[i - 1][1] + arr[i];
  }

  cout << max(dp[n][1], dp[n][2]);
}
