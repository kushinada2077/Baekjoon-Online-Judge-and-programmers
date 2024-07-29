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

int main() {
  fastio;
  int n;
  cin >> n;
  vector<int> cx(n), cy(n);
  for (int i = 0; i < n; ++i) cin >> cx[i] >> cy[i];
  sort(all(cx));
  sort(all(cy));
  int bx = cx[(n - 1) / 2], by = cy[(n - 1) / 2];
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    int x = cx[i], y = cy[i];
    ans += abs(bx - x) + abs(by - y);
  }
  cout << ans << "\n";
}