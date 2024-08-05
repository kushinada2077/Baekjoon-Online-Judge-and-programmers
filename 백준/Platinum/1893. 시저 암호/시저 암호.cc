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

string a, w, s;
vector<int> f;
unordered_map<char, int> c2i;
char shift(char c, int d) { return a[(c2i[c] + d) % si(a)]; }
vector<int> failure(const string& s) {
  vector<int> f(si(s));
  int j = 0;
  for (int i = 1; i < si(s); ++i) {
    while (j && s[i] != s[j]) j = f[j - 1];
    if (s[i] == s[j]) f[i] = ++j;
  }
  return f;
}
bool kmp(const string& s, const string& p, int d) {
  int cnt = 0, j = 0;
  for (int i = 0; i < si(s); ++i) {
    while (j && s[i] != shift(p[j], d)) j = f[j - 1];
    if (s[i] == shift(p[j], d)) ++j;
    if (j == si(p)) {
      cnt++;
      j = f[j - 1];
    }
    if (cnt > 1) return false;
  }
  return cnt == 1;
}
int main() {
  fastio;
  int t;
  cin >> t;
  while (t--) {
    cin >> a >> w >> s;
    c2i.clear();
    for (int i = 0; i < si(a); ++i) c2i[a[i]] = i;
    f = failure(w);
    vector<int> res;
    for (int d = 0; d < si(a); ++d)
      if (kmp(s, w, d)) res.pb(d);
    if (si(res) == 0) cout << "no solution\n";
    else if (si(res) == 1) cout << "unique: " << res[0] << "\n";
    else {
      sort(all(res));
      cout << "ambiguous: ";
      for (auto& i : res) cout << i << " ";
      cout << "\n";
    }
  }
}