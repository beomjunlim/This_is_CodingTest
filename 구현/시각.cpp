/*시각
정수 N이 입력되면 00시 00분 00초부터 N시 59분 59초까지의 모든 시각 중에서 3이 하나라도 포함되는 모든 경우의 수를 구하는 프로그램을 작성하시오.
첫째 줄에 정수 N이 입력된다. (0<=N<=23)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  int cnt = 0;

  for (int i = 0; i <= n; i++)
  {
    if (i != 3 && i != 13 && i != 23)
      cnt += 1575;
    else
      cnt += 3600;
  }
  cout << cnt << endl;
}
