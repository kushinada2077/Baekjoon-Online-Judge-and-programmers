#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
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
using ll = long long;
using namespace std;

vector<int> split(const string& s, const string& sep) {
  int pos = 0;
  vector<int> ret;
  while (pos < si(s)) {
    int nxt_pos = s.find(sep, pos);
    if (nxt_pos == -1) nxt_pos = si(s);
    if (nxt_pos - pos > 0) ret.pb(stoi(s.substr(pos, nxt_pos - pos)));
    pos = nxt_pos + si(sep);
  }
  return ret;
}
int main() {
  fastio;
  int n, L;
  deque<int> q;
  cin >> n >> L;
  vector<int> a(n);
  string ans = "";
  for (auto& i : a) cin >> i;
  int l = 0;
  for (int r = 0; r < n; ++r) {
    while (!q.empty() && q.back() > a[r]) q.pop_back();
    q.push_back(a[r]);
    if (r - l + 1 > L) {
      if (q.front() == a[l]) q.pop_front();
      l++;
    }
    ans += to_string(q.front()) + " ";
  }
  cout << ans << "\n";
}