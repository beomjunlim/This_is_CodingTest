/*상하좌우
N*N 크기의 정사각형 공간 위에 서 있다. 가장 왼쪽 위 좌표는 (1,1)이며 가장 오른쪽 아래 좌표는 (N,N)에 해당한다.
L, R, U, D 이 적혀 있는 계획서가 있다.
계획서가 주어졌을 때 여행가 A가 최종적으로 도착할 지점의 좌표를 출력하는 프로그램을 작성하시오.
첫째 줄에 공간의 크기를 나타내는 N이 주어진다. (1<=N<=100)
둘째 줄에 여행가 A가 이동할 계획서 내용이 주어진다. (1<=이동 횟수<=100)
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
  string s;
  cin.ignore();
  getline(cin, s);
  int x = 1;
  int y = 1;

  for (int i = 0; i < s.length(); i++)
  {
    char plan = s[i];
    if (plan == 'L')
    {
      x -= 1;
      if (x < 1)
        x += 1;
    }
    if (plan == 'R')
    {
      x += 1;
      if (x > n)
        x -= 1;
    }
    if (plan == 'U')
    {
      y -= 1;
      if (y < 1)
        y += 1;
    }
    if (plan == 'D')
    {
      y += 1;
      if (y > n)
        y -= 1;
    }
  }
  cout << y << " " << x << endl;
}
