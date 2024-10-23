#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
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

const int MX = 100010;
const int sqrtN = 300;
const int sz = MX / sqrtN + 10;
struct Query {
  int s, e, n;
  Query(int s1, int e1, int n1) : s(s1), e(e1), n(n1) {}
  bool operator<(const Query& O) const {
    if (s / sqrtN != O.s / sqrtN) return s < O.s;
    return e < O.e;
  }
};

int n, m, k, arr[MX], cntNode[sz], cntLeaf[MX];
list<int> dqArr[MX];
vector<Query> Q;

void update(int x, int d) {
  cntNode[x / sqrtN] += d;
  cntLeaf[x] += d;
}

int find_mx() {
  int ret = 0;
  for (int i = sz - 1; i >= 0; --i) {
    if (cntNode[i]) {
      for (int j = (i + 1) * sqrtN - 1; j >= i * sqrtN; --j) {
        if (cntLeaf[j]) return j;
      }
    }
  }
  return ret;
}

int main() {
  fastio;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> arr[i];
  cin >> m;
  for (int l, r, i{}; i < m; ++i) {
    cin >> l >> r;
    Q.pb(Query(l - 1, r, i));
  }
  sort(all(Q));

  int st = Q[0].s, en = Q[0].e, res[MX]{};
  for (int i = st; i < en; ++i) {
    auto& dq = dqArr[arr[i]];
    if (!dq.empty()) {
      int pre = dq.back() - dq.front();
      update(pre, -1);
    }
    dq.pb(i);
    update(dq.back() - dq.front(), 1);
  }
  res[Q[0].n] = find_mx();

  for (int i = 1; i < m; ++i) {
    while (st > Q[i].s) {
      --st;
      auto& dq = dqArr[arr[st]];
      if (!dq.empty()) {
        int pre = dq.back() - dq.front();
        update(pre, -1);
      }
      dq.push_front(st);
      update(dq.back() - dq.front(), 1);
    }
    while (en < Q[i].e) {
      auto& dq = dqArr[arr[en]];
      if (!dq.empty()) {
        int pre = dq.back() - dq.front();
        update(pre, -1);
      }
      dq.push_back(en);
      update(dq.back() - dq.front(), 1);
      ++en;
    }
    while (st < Q[i].s) {
      auto& dq = dqArr[arr[st]];
      update(dq.back() - dq.front(), -1);
      dq.pop_front();
      if (!dq.empty()) {
        int now = dq.back() - dq.front();
        update(now, 1);
      }
      ++st;
    }
    while (en > Q[i].e) {
      --en;
      auto& dq = dqArr[arr[en]];
      update(dq.back() - dq.front(), -1);
      dq.pop_back();
      if (!dq.empty()) {
        int now = dq.back() - dq.front();
        update(now, 1);
      }
    }

    res[Q[i].n] = find_mx();
  }

  for (int i = 0; i < m; ++i) cout << res[i] << "\n";
}