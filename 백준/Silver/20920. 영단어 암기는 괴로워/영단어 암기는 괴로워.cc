#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
using namespace std;

int main() {
  fastio;
  int n, m;
  string s;
  vector<string> tmp;
  cin >> n >> m;
  while (n--) {
    cin >> s;
    if (si(s) < m) continue;
    tmp.pb(s);
  }
  sort(all(tmp), [](string& a, string& b) {
    if (si(a) == si(b)) return a < b;
    return si(a) > si(b);
  });
  vector<pair<int, int>> ans;
  for (int i = 0; i < si(tmp); ++i) {
    int num = 0;
    string s = tmp[i];
    while (i < si(tmp) - 1 && s == tmp[i + 1]) {
      i++;
      num++;
    }
    ans.pb({-num, i});
  }
  sort(all(ans));
  for (auto& [_, i] : ans) cout << tmp[i] << "\n";
}