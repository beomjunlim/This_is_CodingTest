/*문자열 뒤집기
0과 1로만 이루어진 문자열 S를 가지고 있습니다. 이 문자열 S에 있는 모든 숫자를 전부 같게 만들려고 합니다.
S에서 연속된 하나 이상의 숫자를 잡고 모두 뒤집는 행동을 할 수 있다. 여기서 뒤집는 것은 0을 1로 바꾸는 것을 의미한다.
문자열 S가 주어졌을때, 모두 같은 숫자로 만들 수 있는 최소 횟수를 출력하시오
첫째 줄에 0과 1로만 이루어진 문자열 S가 주어진다. S의 길이는 100만보다 작다.
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

  string s;
  cin >> s;

  int cnt_a = 0;
  int cnt_b = 0;
  if (s[0] - '0' == 0)
    cnt_b += 1;
  else
    cnt_a += 1;

  for (int i = 0; i < s.length() - 1; i++)
  {
    if (s[i] - '0' != s[i + 1] - '0')
    {
      if (s[i] - '0' == 1)
        cnt_b += 1;
      else
        cnt_a += 1;
    }
  }

  cout << min(cnt_a, cnt_b) << endl;
}
