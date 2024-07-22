#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <tuple>
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
  int n, ns, p;
  cin >> n >> ns >> p;
  vector<int> scb(n);
  for (auto& i : scb) {
    cin >> i;
    i *= -1;
  }
  if (n == p && -scb[n - 1] >= ns) {
    cout << "-1\n";
    return 0;
  }

  cout << lower_bound(all(scb), -ns) - scb.begin() + 1 << "\n";
}