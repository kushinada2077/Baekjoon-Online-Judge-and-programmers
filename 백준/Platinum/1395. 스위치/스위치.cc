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

const int _size = 1 << 17;
int seg[_size << 1];
bool lazy[_size << 1];

void propagate(int node, int st, int en) {
  if (lazy[node]) {
    if (node < _size) {
      lazy[node << 1] = !lazy[node << 1];
      lazy[node << 1 | 1] = !lazy[node << 1 | 1];
    }
    seg[node] = (en - st) - seg[node];
    lazy[node] = 0;
  }
}
int sum(int node, int st, int en, int l, int r) {
  propagate(node, st, en);
  if (en <= l || r <= st) return 0;
  if (l <= st && en <= r) return seg[node];
  int mid = (st + en) / 2;
  return sum(node << 1, st, mid, l, r) + sum(node << 1 | 1, mid, en, l, r);
}
void update(int node, int st, int en, int l, int r) {
  propagate(node, st, en);
  if (en <= l || r <= st) return;
  if (l <= st && en <= r) {
    lazy[node] = !lazy[node];
    propagate(node, st, en);
    return;
  }
  int mid = (st + en) / 2;
  update(node << 1, st, mid, l, r);
  update(node << 1 | 1, mid, en, l, r);
  seg[node] = seg[node << 1] + seg[node << 1 | 1];
}
int main() {
  fastio;
  int n, m, o, s, t;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> o >> s >> t;
    if (s > t) swap(s, t);
    if (o) {
      cout << sum(ROOT, 0, _size, s - 1, t) << "\n";
    } else {
      update(ROOT, 0, _size, s - 1, t);
    }
  }
}