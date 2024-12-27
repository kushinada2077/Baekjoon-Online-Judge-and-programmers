#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using TP = tuple<int, int, int>;
using P = pair<int, int>;

int n, A[100005];
ll sum, ans;
int main() {
  fastio;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> A[i];
  for (int i = n - 1; i != 0; --i) {
    sum += A[i];
    ans += sum * A[i - 1];
  }

  cout << ans << "\n";
}