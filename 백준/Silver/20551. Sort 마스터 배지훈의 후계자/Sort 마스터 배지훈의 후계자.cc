#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
using namespace std;

int main() {
  fastio;
  int n, m, x;
  cin >> n >> m;
  vector<int> a(n);
  for (auto& i : a) cin >> i;
  sort(all(a));
  while (m--) {
    cin >> x;
    int idx = lower_bound(all(a), x) - a.begin();
    if (idx == n || a[idx] != x) cout << "-1\n";
    else cout << idx << "\n";
  }
}