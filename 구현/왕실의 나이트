/*왕실의 나이트
체스판은 8*8 좌표 평면이다. 나이트는 말을 타고 있기 때문에 L자 형태로만 이동할 수 있으며 정원 밖으로는 나갈 수 없다.
나이트는 특정한 위치에서 다음과 같은 2가지 경우로 이동할 수 있다.
1. 수평으로 두 칸 이동한 뒤에 수직으로 한 칸 이동하기
2. 수직으로 두 칸 이동한 뒤에 수평으로 한 칸 이동하기
좌표 평면상에서 나이트의 위치가 주어졌을 때 나이트가 이동할 수 있는 경우의 수를 출력하는 프로그램을 작성하시오.
행의 위치는 1부터 8로 표현하고 열 위치는 a부터 h로 표한한다.
첫째 줄에 8*8 좌표 평면상에서 현재 나이트가 위치한 곳의 좌표를 나타내는 두 문자로 구성된 문자열이 입력된다.
입력 문자는 a1처럼 열과 행으로 이루어진다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  cin >> s;
  int cnt = 0;
  int row = s[1] - '0';
  int col = s[0] - 'a' + 1;

  for (int i = 0; i < 8; i++)
  {
    int nextrow = row + dy[i];
    int nextcol = col + dx[i];
    if (nextrow >= 1 && nextrow <= 8 && nextcol >= 1 && nextcol <= 8)
      cnt += 1;
  }
  cout << cnt << endl;
}
