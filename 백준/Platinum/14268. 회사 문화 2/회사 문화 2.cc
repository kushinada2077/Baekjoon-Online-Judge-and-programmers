#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using ll = long long;
using namespace std;

vector<int> adj[100005];
pair<int, int> section[100005];
int idx = 0;
void pre(int cur) {
  section[cur].X = idx++;
  for (auto nxt : adj[cur]) pre(nxt);
  section[cur].Y = idx;
}
const int _size = 1 << 17;
int seg[_size << 1], lazy[_size << 1];
void propagate(int node, int st, int en) {
  if (lazy[node]) {
    if (node < _size) {
      lazy[node << 1] += lazy[node];
      lazy[node << 1 | 1] += lazy[node];
    }
    seg[node] += (en - st) * lazy[node];
    lazy[node] = 0;
  }
}
void update(int node, int st, int en, int l, int r, int x) {
  propagate(node, st, en);
  if (en <= l || r <= st) return;
  if (l <= st && en <= r) {
    lazy[node] += x;
    propagate(node, st, en);
    return;
  }
  int mid = (st + en) / 2;
  update(node << 1, st, mid, l, r, x);
  update(node << 1 | 1, mid, en, l, r, x);
}
int sum(int node, int st, int en, int l, int r) {
  propagate(node, st, en);
  if (en <= l || r <= st) return 0;
  if (l <= st && en <= r) return seg[node];
  int mid = (st + en) / 2;
  return sum(node << 1, st, mid, l, r) + sum(node << 1 | 1, mid, en, l, r);
}
int main() {
  fastio;
  int n, m, x, q, a, b;
  cin >> n >> m >> x;
  for (int i = 2; i <= n; ++i) {
    cin >> x;
    adj[x].pb(i);
  }
  pre(1);
  for (int i = 0; i < m; ++i) {
    cin >> q >> a;
    auto [l, r] = section[a];
    if (q == 1) {
      cin >> b;
      update(ROOT, 0, _size, l, r, b);
    } else cout << sum(ROOT, 0, _size, l, l + 1) << "\n";
  }
}