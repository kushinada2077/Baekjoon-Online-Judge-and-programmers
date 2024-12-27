#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using TP = tuple<int, int, int>;
using P = pair<int, int>;

ll n, k, ans, sum, x;
map<ll, int> cnt;
int main() {
  fastio;
  cin >> n >> k;
  cnt[0]++;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    sum += x;
    ans += cnt[sum - k];
    cnt[sum]++;
  }

  cout << ans << "\n";
}