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

int t, n, l;
int main() {
  fastio;

  cin >> t;
  while (t--) {
    int mn = -1, mx = -1;
    cin >> l >> n;
    vector<int> a(n);
    for (auto& i : a) {
      cin >> i;
      mn = max(mn, min(i, l - i));
      mx = max(mx, max(i, l - i));
    }
    cout << mn << " " << mx << "\n";
  }
}