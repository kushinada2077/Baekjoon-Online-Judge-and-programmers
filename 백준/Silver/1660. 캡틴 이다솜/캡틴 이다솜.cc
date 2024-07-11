#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using namespace std;

int n, d[300005];
const int INF = 0x3f3f3f3f;
vector<int> s(1, 0);
int f(int k) {
  if (k == 0) return 0;
  if (d[k] != INF) return d[k];

  int ret = 0x3f3f3f3f;
  for (int i = 1; i < si(s); ++i)
    if (k - s[i] >= 0) ret = min(ret, f(k - s[i]) + 1);
  d[k] = ret;
  return ret;
}
int main() {
  fastio;
  cin >> n;
  fill(d, d + 300005, INF);
  s.pb(1);
  for (int i = 1; s[i] <= 300000; ++i) s.pb(s[i] + (i + 2) * (i + 1) / 2);
  cout << f(n);
}