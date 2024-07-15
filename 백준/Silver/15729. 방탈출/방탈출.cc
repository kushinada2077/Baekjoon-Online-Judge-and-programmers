#include <algorithm>
#include <iostream>
#include <queue>
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

int main() {
  fastio;
  int n, ans = 0;
  bool state = false;
  cin >> n;
  vector<int> a(n);
  vector<bool> c(n, false);
  for (auto& i : a) cin >> i;
  for (int i = 0; i < n; ++i) {
    if (c[i]) state = !state;
    int cur = a[i] ^ state;
    if (cur) {
      if (i + 3 < n) c[i + 3] = true;
      state = !state;
      ans++;
    }
  }
  cout << ans << "\n";
}