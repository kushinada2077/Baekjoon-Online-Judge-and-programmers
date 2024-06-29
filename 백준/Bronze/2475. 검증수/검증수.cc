#define ll long long
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> a(5);
  int ans = 0;
  for (int i = 0; i < 5; ++i) cin >> a[i];
  for (auto n : a) ans += n * n;
  cout << ans % 10;
}