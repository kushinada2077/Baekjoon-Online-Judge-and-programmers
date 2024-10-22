#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>
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

const int MX = 100000;
int sqrtN, cnt[1000001];

struct Query {
  int s, e, n;
  Query(int s1, int e1, int n1) : s(s1), e(e1), n(n1) {}
  bool operator<(const Query& O) const {
    if (s / sqrtN == O.s / sqrtN) return e < O.e;
    return (s / sqrtN < O.s / sqrtN);
  }
};

int main() {
  fastio;
  int n, m;
  cin >> n;
  sqrtN = sqrt(n);
  vector<int> a(n);
  vector<Query> Q;
  for (auto& i : a) cin >> i;
  cin >> m;
  for (int i, j, k{}; k < m; ++k) {
    cin >> i >> j;
    Q.pb({i - 1, j, k});
  }
  sort(all(Q));

  int s = Q[0].s, e = Q[0].e, sum = 0, result[MX]{};
  for (int i = s; i < e; ++i) {
    if (cnt[a[i]]++ == 0) sum++;
  }
  result[Q[0].n] = sum;

  for (int i = 1; i < m; ++i) {
    while (Q[i].s < s)
      if (cnt[a[--s]]++ == 0) sum++;
    while (Q[i].s > s)
      if (--cnt[a[s++]] == 0) sum--;
    while (Q[i].e < e)
      if (--cnt[a[--e]] == 0) sum--;
    while (Q[i].e > e)
      if (cnt[a[e++]]++ == 0) sum++;
    result[Q[i].n] = sum;
  }

  for (int i = 0; i < m; ++i) cout << result[i] << "\n";
}