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

const int MX = 1000 * 1000 + 5;
int n, x, unused = 2, nxt[MX][2], cnt;
bool f = false;
vector<bool> chk(MX, false);
vector<string> ans(1001);
string s = "";
void dfs(int cur, int dep, int len, int idx) {
  if (dep == len) {
    ans[idx] = s;
    chk[cur] = true;
    cnt++;
    f = true;
    return;
  }
  for (int i = 0; i < 2; ++i) {
    if (!nxt[cur][i]) {
      nxt[cur][i] = unused++;
      s += i + '0';
      dfs(nxt[cur][i], dep + 1, len, idx);
      s.pop_back();
      break;
    }
    if (!chk[nxt[cur][i]]) {
      s += i + '0';
      dfs(nxt[cur][i], dep + 1, len, idx);
      s.pop_back();
      if (f) return;
    }
  }
}
int main() {
  fastio;
  cin >> n;
  vector<pair<int, int>> l;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    l.pb({x, i});
  }
  sort(all(l));
  for (auto& [i, _] : l) {
    f = false;
    dfs(ROOT, 0, i, _);
  }
  if (cnt == n) {
    cout << "1\n";
    for (int i = 0; i < n; ++i) cout << ans[i] << "\n";
  } else cout << "-1\n";
}