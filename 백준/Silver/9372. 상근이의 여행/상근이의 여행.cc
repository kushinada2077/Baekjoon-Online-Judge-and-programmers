#define TUPLE tuple<int, int, int>
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int T, n, m, a, b, ans, p[1001];

int find(int v) {
  if (p[v] < 0) return v;
  return p[v] = find(p[v]);
}

bool is_diff_group(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return 0;
  if (p[a] == p[b]) p[a]--;
  if (p[a] > p[b])
    p[a] = b;
  else
    p[b] = a;

  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;

  while (T--) {
    cin >> n >> m;
    vector<pair<int, int>> edge;
    fill(p, p + 1 + n, -1);
    for (int i = 0; i < m; i++) {
      cin >> a >> b;
      edge.push_back({a, b});
    }

    for (int i = 0; i < m; i++) {
      auto [a, b] = edge[i];
      if (!is_diff_group(a, b)) continue;
      ans++;
      if (ans == n - 1) break;
    }

    cout << ans << "\n";
    ans = 0;
  }
}