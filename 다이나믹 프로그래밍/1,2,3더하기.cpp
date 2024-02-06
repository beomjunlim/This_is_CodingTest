#include <iostream>
using namespace std;

#define MAX 100000000

int dp[MAX];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;

  while (n > 0)
  {
    int num;
    cin >> num;

    for (int i = 4; i <= num; i++)
    {
      dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    cout << dp[num] << '\n';
    n--;
  }
}
