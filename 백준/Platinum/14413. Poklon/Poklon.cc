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

const int MX = 500001;
int sqrtN;

struct Query {
  int s, e, n;
  Query(int s, int e, int n) : s(s), e(e), n(n) {}
  bool operator<(const Query& O) const {
    if (s / sqrtN != O.s / sqrtN) return s < O.s;
    return e < O.e;
  }
};

int n, m, arr[MX], cnt[MX];
vector<int> sorted;

int main() {
  fastio;
  cin >> n >> m;
  sqrtN = sqrt(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    sorted.pb(arr[i]);
  }
  sort(all(sorted));
  sorted.erase(unique(all(sorted)), sorted.end());
  for (int i = 0; i < n; ++i) {
    arr[i] = lower_bound(all(sorted), arr[i]) - sorted.begin();
  }

  vector<Query> Q;
  for (int a, b, i{}; i < m; ++i) {
    cin >> a >> b;
    Q.pb(Query(a - 1, b, i));
  }
  sort(all(Q));

  int st = Q[0].s, en = Q[0].e, ans = 0, res[MX]{};
  for (int i = st; i < en; ++i) {
    if (++cnt[arr[i]] == 2) ans++;
    else if (cnt[arr[i]] == 3) ans--;
  }
  res[Q[0].n] = ans;

  for (int i = 1; i < m; ++i) {
    while (Q[i].s < st) {
      --st;
      if (++cnt[arr[st]] == 2) ans++;
      else if (cnt[arr[st]] == 3) ans--;
    }
    while (Q[i].e > en) {
      if (++cnt[arr[en]] == 2) ans++;
      else if (cnt[arr[en]] == 3) ans--;
      en++;
    }
    while (Q[i].s > st) {
      if (--cnt[arr[st]] == 2) ans++;
      else if (cnt[arr[st]] == 1) ans--;
      st++;
    }
    while (Q[i].e < en) {
      en--;
      if (--cnt[arr[en]] == 2) ans++;
      else if (cnt[arr[en]] == 1) ans--;
    }

    res[Q[i].n] = ans;
  }

  for (int i = 0; i < m; ++i) cout << res[i] << "\n";
}