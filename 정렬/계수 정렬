#include <iostream>
using namespace std;

int main()
{
  int arr[13] = {1, 3, 2, 5, 4, 3, 3, 4, 5, 1, 1, 2, 4};
  int cnt[6] = {0};

  for (int i = 0; i < 13; i++)
  {
    cnt[arr[i]] += 1;
  }

  int index = 0;

  for (int i = 1; i <= 5; i++)
  {
    if (cnt[i] != 0)
    {
      for (int j = 0; j < cnt[i]; j++)
      {
        arr[index] = i;
        index += 1;
      }
    }
  }

  for (int i = 0; i < 13; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}
