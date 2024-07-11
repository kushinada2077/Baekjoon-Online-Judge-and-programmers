#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using namespace std;

int main() {
  fastio;
  int n, m;
  pair<int, int> ans = {0, 0};
  cin >> n >> m;
  vector<int> a(m);
  for (auto& i : a) cin >> i;
  sort(all(a), greater<>());
  for (int i = 0; i < n; ++i) {
    int p = a[i < m ? i : m - 1];
    int tot = p * (i + 1);
    if (tot > ans.Y) ans = {p, tot};
  }
  cout << ans.X << " " << ans.Y << "\n";
}