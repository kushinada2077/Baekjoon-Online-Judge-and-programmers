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
using ll = long long;
using namespace std;

const int _size = 1 << 21;
int seg[_size << 1];

void update(int idx, int x) {
  idx += _size;
  seg[idx] += x;
  while (idx > 1) {
    idx >>= 1;
    seg[idx] = seg[idx << 1] + seg[idx << 1 | 1];
  }
}
int find(int node, int st, int en, int k) {
  if (st + 1 == en) return st;
  int mid = (st + en) / 2;
  if (seg[node << 1] >= k) return find(node << 1, st, mid, k);
  else return find(node << 1 | 1, mid, en, k - seg[node << 1]);
}
int main() {
  fastio;
  int n, t, x;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> t >> x;
    if (t == 1) update(x, 1);
    else {
      int num = find(1, 0, _size, x);
      cout << num << "\n";
      update(num, -1);
    }
  }
}