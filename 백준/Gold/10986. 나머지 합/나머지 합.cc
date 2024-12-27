#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using TP = tuple<int, int, int>;
using P = pair<int, int>;

int n, k, cnt[1001];
ll ans, sum;
int main() {
  fastio;
  cin >> n >> k;
  cnt[0]++;
  for (int x, i = 0; i < n; ++i) {
    cin >> x;
    sum = (sum + x) % k;
    ans += cnt[sum];
    cnt[sum]++;
  }

  cout << ans << "\n";
}