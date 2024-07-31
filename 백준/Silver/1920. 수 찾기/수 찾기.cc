#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_set>
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

int main() {
  fastio;
  int n, m, x;
  cin >> n;
  vector<int> a(n);
  for (auto& i : a) cin >> i;
  sort(all(a));
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> x;
    int lo = 0, hi = n;
    while (lo + 1 < hi) {
      int mid = (lo + hi) / 2;
      if (a[mid] > x) hi = mid;
      else lo = mid;
    }
    if (a[lo] == x) cout << "1\n";
    else cout << "0\n";
  }
}