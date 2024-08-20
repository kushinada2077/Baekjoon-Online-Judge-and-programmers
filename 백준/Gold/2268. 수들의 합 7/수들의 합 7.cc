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

int n, m, a, b, c;
ll x;
vector<ll> arr(1000005);

ll sum(int idx) {
  ll ret = 0;
  while (idx) {
    ret += arr[idx];
    idx -= idx & -idx;
  }
  return ret;
}
void modify(int idx, ll val) {
  while (idx <= n) {
    arr[idx] += val;
    idx += idx & -idx;
  }
}
int main() {
  fastio;
  cin >> n >> m;
  vector<int> ori(n + 1);
  while (m--) {
    cin >> a >> b >> c;
    if (a == 0) {
      if (b > c) swap(b, c);
      cout << sum(c) - sum(b - 1) << "\n";
    } else {
      modify(b, c - ori[b]);
      ori[b] = c;
    }
  }
}