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

vector<int> failure(const string& s) {
  vector<int> f(si(s));
  int j = 0;
  for (int i = 1; i < si(s); ++i) {
    while (j && s[i] != s[j]) j = f[j - 1];
    if (s[i] == s[j]) f[i] = ++j;
  }
  return f;
}
vector<int> kmp(const string& s, const string& p) {
  vector<int> f = failure(p);
  vector<int> ret;
  int j = 0;
  for (int i = 0; i < si(s); ++i) {
    while (j && s[i] != p[j]) j = f[j - 1];
    if (s[i] == p[j]) j++;
    if (j == si(p)) {
      ret.pb(i - si(p) + 2);
      j = f[j - 1];
    }
  }
  return ret;
}
int main() {
  fastio;
  string s, p;
  getline(cin, s);
  getline(cin, p);
  vector<int> ans = kmp(s, p);
  cout << si(ans) << "\n";
  for (auto& i : ans) cout << i << " ";
}