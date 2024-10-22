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

int sqrtN;

struct QueryNode {
  int s, e, n;
  QueryNode(int s1, int e1, int n1) : s(s1), e(e1), n(n1) {}
  bool operator<(const QueryNode &O) const {
    if (s / sqrtN != O.s / sqrtN) return (s / sqrtN < O.s / sqrtN);
    return e < O.e;
  }
};

int main() {
  fastio;
  int n, m;
  cin >> n >> m;
  sqrtN = sqrt(n);
  vector<int> a(n);
  vector<QueryNode> q;
  for (auto &i : a) cin >> i;
  for (int i, j, k{}; k < m; ++k) {
    cin >> i >> j;
    q.pb(QueryNode(i - 1, j, k));
  }
  sort(all(q));

  ll sum = 0, result[100000];
  int s = q[0].s, e = q[0].e;
  for (int i = s; i < e; ++i) sum += a[i];
  result[q[0].n] = sum;
  for (int i = 1; i < m; ++i) {
    while (q[i].s < s) sum += a[--s];
    while (e < q[i].e) sum += a[e++];
    while (q[i].s > s) sum -= a[s++];
    while (q[i].e < e) sum -= a[--e];
    result[q[i].n] = sum;
  }

  for (int i = 0; i < m; ++i) cout << result[i] << "\n";
}