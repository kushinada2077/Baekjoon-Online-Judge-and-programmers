#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using TP = tuple<int, int, int>;
using P = pair<int, int>;

int n, A[100005], pref[100005];
int main() {
  fastio;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
    pref[i + 1] = pref[i] + A[i];
  }

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += 1ll * A[i] * (pref[n] - pref[i + 1]);
  }

  cout << ans << "\n";
}