/*곱하기 혹은 더하기
각 자리가 숫자로만 이루어진 문자열 S가 주어졌을 때, 왼쪽부터 오른쪽으로 하나씩 숫자를 확인하며
숫자 사이에 * 혹은 + 연산자를 넣어 결과적으로 만들어질 수 있는 가장 큰 수를 구하는 프로그램을 작성하세요.
단 일반적인 방식과 달리 모든 연산은 왼쪽에서부터 순서대로 이루어진다고 가정한다.
첫째 줄에 여러 개의 숫자로 구성된 하나의 문자열 S가 주어집니다. (1<=S의 길이<=20)
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
  long long result = s[0] - '0';
  for (int i = 1; i < s.length(); i++)
  {
    int num = s[i] - '0';
    if (result <= 1 || num <= 1)
      result = result + num;
    else
      result = result * num;
  }
  cout << result << endl;
}
