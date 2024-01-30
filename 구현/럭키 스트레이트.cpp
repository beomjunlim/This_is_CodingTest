/*럭키 스트레이트
특정 조건을 만족할 경우 럭키 스트레이트 기술을 사용할 수 있다.
특정 조건이란 캐릭터의 점수를 N이라고 할 때 자릿수를 기준으로 점수 N을 반으로 나누어 왼쪽 부분의 각 자릿수의 합과 오른쪽 부분의 각 자릿수의 합을 더한 값이 동일한 상황을 말한다.
현재 점수 N이 주어지면 럭키 스트레이트를 사용할 수 있는 상태인지 아닌지를 알려주는 프로그램을 작성하시오.
첫째 줄에 점수 N이 정수로 주어집니다. (10<=N<=99,999,999) 단, 점수 N의 자릿수는 항상 짝수 형태로만 주어집니다.
예를 들어 자릿수가 5인 12,345와 같은 수는 입력으로 들어오지 않습니다.
사용할 수 있다면 LUCKY 사용할 수 없다면 READY를 출력한다.
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

  string n;
  cin >> n;
  int len = n.length() / 2;
  
  int sum_f = 0;
  int sum_b = 0;
  for (int i = 0; i < len; i++)
  {
    sum_f += (n[i] - '0');
    sum_b += (n[i + len] - '0');
  }
  if (sum_f == sum_b)
    cout << "LUCKY" << endl;
  else
    cout << "READY" << endl;
}
