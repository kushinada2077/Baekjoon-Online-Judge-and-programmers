#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using TP = tuple<int, int, int>;
using P = pair<int, int>;

int n, k, q, m, pref[5005];
bool sleepy[5005], checked[5005];
int main() {
  fastio;
  cin >> n >> k >> q >> m;
  for (int v, i = 0; i < k; ++i) {
    cin >> v;
    sleepy[v] = true;
  }
  for (int v, i = 0; i < q; ++i) {
    cin >> v;
    if (sleepy[v]) continue;
    for (int j = v; j < n + 3; j += v) {
      if (sleepy[j]) continue;
      checked[j] = true;
    }
  }
  for (int i = 3; i < n + 3; ++i) pref[i + 1] = pref[i] + checked[i];
  for (int l, r, i = 0; i < m; ++i) {
    cin >> l >> r;
    cout << r - l + 1 - pref[r + 1] + pref[l] << "\n";
  }
}