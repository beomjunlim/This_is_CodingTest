#include <iostream>
using namespace std;
/*거스름돈
500원, 100원, 50원, 10원 동전이 무한히 존재한다.
손님에게 거슬러 줘야 할 돈이 N원일 때 거슬러줘야 할 동전의 최소 개수를 구하라
단 N은 항상 10의 배수이다.*/
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  int cnt = 0;
  int arr[4] = {500, 100, 50, 10};
  cin >> n;
  for (int a : arr)
  {
    cnt += n / a;
    n = n % a;
  }
  cout << cnt << endl;
}
