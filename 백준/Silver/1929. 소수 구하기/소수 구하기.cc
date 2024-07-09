#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
using namespace std;

vector<bool> d(1000005, true);
void sieve(int n) {
  d[1] = false;
  for (int i = 2; i * i <= n; ++i) {
    if (!d[i]) continue;
    for (int j = i * i; j <= n; j += i) d[j] = false;
  }
}
int main() {
  fastio;
  int m, n;
  cin >> m >> n;
  sieve(n);
  for (int i = m; i <= n; ++i)
    if (d[i]) cout << i << "\n";
}