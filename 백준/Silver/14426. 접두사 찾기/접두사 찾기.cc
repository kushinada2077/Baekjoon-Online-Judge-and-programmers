#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <tuple>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
using ll = long long;
using namespace std;

bool f(const string& a, const string& s) {
  for (int i = 0; i < si(s); ++i) {
    if (a[i] != s[i]) return false;
  }
  return true;
}
int main() {
  fastio;
  int n, m, ans = 0;
  cin >> n >> m;
  vector<string> dic(n);
  string s;
  for (auto& s : dic) cin >> s;
  sort(all(dic));
  while (m--) {
    cin >> s;
    auto it = lower_bound(all(dic), s);
    if (it == dic.end()) continue;
    ans += f(*it, s);
  }
  cout << ans << "\n";
}