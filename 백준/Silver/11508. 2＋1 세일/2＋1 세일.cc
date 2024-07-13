#include <algorithm>
#include <iostream>
#include <set>
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

int f(int n) {
  int ret = n;
  while (n > 0) {
    ret += n % 10;
    n /= 10;
  }
  return ret;
}
int main() {
  fastio;
  int n;
  cin >> n;
  vector<int> a(n);
  ll ans = 0;
  for (auto& i : a) {
    cin >> i;
    ans += i;
  }
  sort(all(a), greater<>());
  for (int i = 0; i + 2 < n; i += 3) {
    ans -= a[i + 2];
  }
  cout << ans << "\n";
}