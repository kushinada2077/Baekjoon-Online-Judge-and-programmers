#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <numeric>
#include <queue>
#include <tuple>
#include <unordered_map>
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

bool f(const string& a, const string& b) { return a < b; }
bool chk(const string& a, const string& b) {
  for (int i = 0; i < si(b); ++i)
    if (a[i] != b[i]) return false;
  return true;
}
int main() {
  fastio;
  int n, m, ans = 0;
  string s;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(all(a));
  for (int i = 0; i < m; ++i) {
    cin >> s;
    int lo = -1, hi = n - 1;
    while (lo + 1 < hi) {
      int mid = (lo + hi) / 2;
      if (f(a[mid], s)) lo = mid;
      else hi = mid;
    }
    ans += chk(a[hi], s);
  }
  cout << ans << "\n";
}