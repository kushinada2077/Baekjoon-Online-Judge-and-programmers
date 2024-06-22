#define ll long long
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int ERR = -0x3f3f3f3f;
int d[100005];
int n, v, num[100005];

int f(int l) {
  if (l == 0) return num[0];
  if (d[l] != ERR) return d[l];
  int mx = max(f(l - 1) + num[l], num[l]);
  d[l] = mx;
  return mx;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  fill(d, d + 100005, ERR);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> num[i];
  d[0] = num[0];
  f(n - 1);
  int ans = ERR;
  for (int i = 0; i < n; ++i) ans = max(ans, d[i]);
  cout << ans;
}