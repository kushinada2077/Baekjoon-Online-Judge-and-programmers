#include <algorithm>
#include <bitset>
#include <deque>
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

string v2s(vector<bool>& a) {
  string ret = "";
  for (auto i : a) ret += i ? "1" : "0";
  return ret;
}
int main() {
  fastio;
  int n, m, o, a, b, ans = 0;
  set<string> s;
  cin >> n >> m;
  bitset<20> t[n];
  while (m--) {
    cin >> o;
    if (o == 1) {
      cin >> a >> b;
      t[a - 1].set(b - 1);
    } else if (o == 2) {
      cin >> a >> b;
      t[a - 1].reset(b - 1);
    } else if (o == 3) {
      cin >> a;
      for (int i = 19; i != 0; --i) t[a - 1][i] = t[a - 1][i - 1];
      t[a - 1].reset(0);
    } else {
      cin >> a;
      for (int i = 0; i < 19; ++i) t[a - 1][i] = t[a - 1][i + 1];
      t[a - 1].reset(19);
    }
  }
  for (int i = 0; i < n; ++i) {
    string tt = t[i].to_string();
    if (s.find(tt) != s.end()) continue;
    s.insert(tt);
    ans++;
  }
  cout << ans << "\n";
}