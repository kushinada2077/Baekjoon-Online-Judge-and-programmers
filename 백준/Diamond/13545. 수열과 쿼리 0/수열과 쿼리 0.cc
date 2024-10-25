#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
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

const int MX = 200010;
const int sq = 400;
const int sz = MX / sq + 10;

struct Query {
  int s, e, n;
  Query(int s, int e, int n) : s(s), e(e), n(n) {}
  bool operator<(const Query& O) const {
    if (s / sq != O.s / sq) return s < O.s;
    return e < O.e;
  }
};

int n, m, arr[MX], preSum[MX], freq[MX], freqBucket[sz];
list<int> dqArr[MX << 1];

void update(int x, int d) {
  freq[x] += d;
  freqBucket[x / sq] += d;
}

int findMx() {
  for (int i = sz - 1; i >= 0; --i) {
    if (freqBucket[i]) {
      for (int j = (i + 1) * sq - 1; j >= i * sq; --j) {
        if (freq[j]) return j;
      }
    }
  }

  return 0;
}

int main() {
  fastio;
  cin >> n;
  preSum[0] = 100000;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    preSum[i + 1] = preSum[i] + arr[i];
  }
  cin >> m;
  vector<Query> Q;
  for (int a, b, i{}; i < m; ++i) {
    cin >> a >> b;
    Q.pb(Query(a - 1, b + 1, i));
  }

  sort(all(Q));
  int s = Q[0].s, e = Q[0].e, res[MX];
  for (int i = s; i < e; ++i) {
    auto& dq = dqArr[preSum[i]];
    if (!dq.empty()) update(dq.back() - dq.front(), -1);
    dq.pb(i);
    update(dq.back() - dq.front(), 1);
  }

  res[Q[0].n] = findMx();

  for (int i = 1; i < m; ++i) {
    while (Q[i].s < s) {
      s--;
      auto& dq = dqArr[preSum[s]];
      if (!dq.empty()) update(dq.back() - dq.front(), -1);
      dq.push_front(s);
      update(dq.back() - dq.front(), 1);
    }

    while (e < Q[i].e) {
      auto& dq = dqArr[preSum[e]];
      if (!dq.empty()) update(dq.back() - dq.front(), -1);
      dq.push_back(e);
      update(dq.back() - dq.front(), 1);
      e++;
    }

    while (s < Q[i].s) {
      auto& dq = dqArr[preSum[s]];
      update(dq.back() - dq.front(), -1);
      dq.pop_front();
      if (!dq.empty()) update(dq.back() - dq.front(), 1);
      s++;
    }

    while (Q[i].e < e) {
      e--;
      auto& dq = dqArr[preSum[e]];
      update(dq.back() - dq.front(), -1);
      dq.pop_back();
      if (!dq.empty()) update(dq.back() - dq.front(), 1);
    }

    res[Q[i].n] = findMx();
  }

  for (int i = 0; i < m; ++i) cout << res[i] << "\n";
}