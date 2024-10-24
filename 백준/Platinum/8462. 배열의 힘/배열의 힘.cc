#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define L_PATH "input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define rep(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using T = tuple<int, int, int>;
using P = pair<int, int>;

const int MX = 100001;
int sqrtN;

struct Query {
  int s, e, n;
  Query(int s, int e, int n) : s(s), e(e), n(n) {}
  bool operator<(const Query& O) const {
    if (O.s / sqrtN != s / sqrtN) return s < O.s;
    return e < O.e;
  }
};

int n, m, arr[MX];
int freq[1000001];

int main() {
  fastio;
  cin >> n >> m;
  sqrtN = sqrt(n);
  for (int i = 0; i < n; ++i) cin >> arr[i];
  vector<Query> Q;
  for (int a, b, i{}; i < m; ++i) {
    cin >> a >> b;
    Q.pb(Query(a - 1, b, i));
  }
  sort(all(Q));

  int s = Q[0].s, e = Q[0].e;
  ll ans = 0, res[MX];

  for (int i = s; i < e; ++i) {
    int& cnt = freq[arr[i]];
    ans -= 1ll * cnt * cnt * arr[i];
    cnt++;
    ans += 1ll * cnt * cnt * arr[i];
  }

  res[Q[0].n] = ans;

  for (int i = 1; i < m; ++i) {
    while (s < Q[i].s) {
      int& cnt = freq[arr[s]];
      ans -= 1ll * cnt * cnt * arr[s];
      cnt--;
      ans += 1ll * cnt * cnt * arr[s];
      s++;
    }

    while (Q[i].s < s) {
      s--;
      int& cnt = freq[arr[s]];
      ans -= 1ll * cnt * cnt * arr[s];
      cnt++;
      ans += 1ll * cnt * cnt * arr[s];
    }

    while (Q[i].e < e) {
      e--;
      int& cnt = freq[arr[e]];
      ans -= 1ll * cnt * cnt * arr[e];
      cnt--;
      ans += 1ll * cnt * cnt * arr[e];
    }

    while (e < Q[i].e) {
      int& cnt = freq[arr[e]];
      ans -= 1ll * cnt * cnt * arr[e];
      cnt++;
      ans += 1ll * cnt * cnt * arr[e];
      e++;
    }

    res[Q[i].n] = ans;
  }

  for (int i = 0; i < m; ++i) cout << res[i] << "\n";
}