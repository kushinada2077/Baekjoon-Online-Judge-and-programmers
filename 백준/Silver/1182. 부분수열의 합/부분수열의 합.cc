#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using ll = long long;
using namespace std;

int main() {
  fastio;
  int n, s, ans = 0;
  cin >> n >> s;
  vector<int> a(n);
  for (auto& i : a) cin >> i;

  for (int i = 1; i < (1 << n); ++i) {
    int sum = 0;
    for (int j = 0; j < n; ++j)
      if (i & (1 << j)) sum += a[j];
    if (sum == s) ans++;
  }
  cout << ans << "\n";
}