#include <algorithm>
#include <iostream>
#include <set>
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

int d[1005];
int f(vector<int>& a, int k) {
  if (k == 0) return 0;
  if (k < 0) return -0x3f3f3f3f;
  if (d[k]) return d[k];
  int ret = 0;
  for (int i = 0; i < si(a); ++i) ret = max(ret, a[i] + f(a, k - i - 1));
  d[k] = ret;
  return ret;
}
int main() {
  fastio;
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& i : a) cin >> i;
  cout << f(a, n) << "\n";
}