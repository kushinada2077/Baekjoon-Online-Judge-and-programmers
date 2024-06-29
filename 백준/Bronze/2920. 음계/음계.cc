#define ll long long
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int pre, cur;
  cin >> pre;
  for (int i = 0; i < 7; ++i) {
    cin >> cur;
    if (abs(cur - pre) != 1) {
      cout << "mixed";
      exit(0);
    }
    if (i != 6) pre = cur;
  }
  if (pre < cur)
    cout << "ascending";
  else
    cout << "descending";
}