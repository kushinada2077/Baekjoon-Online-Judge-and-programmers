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

vector<bool> state(1005, true);
void sieve(int n) {
  state[1] = false;
  for (int i = 2; i * i <= n; ++i) {
    if (!state[i]) continue;
    for (int j = i * i; j <= n; j += i) state[j] = false;
  }
}
int main() {
  fastio;
  sieve(1000);
  int ans = 0, n, x;
  cin >> n;
  for_in(n) {
    cin >> x;
    ans += state[x];
  }
  cout << ans << "\n";
}