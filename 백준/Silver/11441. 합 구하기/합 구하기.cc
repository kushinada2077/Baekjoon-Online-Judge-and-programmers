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
  int n, m, p, q, tot = 0;
  cin >> n;
  vector<int> a(n + 1, 0);
  for (int i = 1; i < n + 1; ++i) {
    cin >> m;
    tot += m;
    a[i] = tot;
  }
  cin >> m;
  while (m--) {
    cin >> p >> q;
    cout << a[q] - a[p - 1] << "\n";
  }
}