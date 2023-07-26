/*모험가 길드
모험가 N명이 있다. N명의 모험가를 대상으로 공포도를 측정했는데 공포도가 높은 모험가는 쉽게 공포를 느껴 상황대처 능력이 떨어진다.
따라서 공포도가 X인 모험가는 반드시 X명 이상으로 구성한 모험가 그룹에 참여해야 여행을 떠날 수 있도록 규정하였다.
N명의 모험가 정보가 주어졌을 때, 여행을 떠날 수 있는 그룹 수의 최댓값을 구하는 프로그램을 작성하시오
첫째 줄에 모험가의 수 N이 주어진다. (1<=N<=100,000)
둘째 줄에 각 모험가의 공포도의 값을 N이하의 자연수로 주어지며, 각 자연수는 공백으로 구분한다.
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
  int cnt = 0;
  vector<int> v;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    v.push_back(a);
  }

  sort(v.begin(), v.end());

  int num = 0;
  for (int i = 0; i < n; i++)
  {
    num += 1;
    if (num >= v[i])
    {
      cnt += 1;
      num = 0;
    }
  }

  cout << cnt << endl;
}
