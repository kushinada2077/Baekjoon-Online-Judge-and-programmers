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

const int MX = 200010;
const int sz = MX / 300 + 10;
int sqrtN;

struct Query {
  int s, e, n;
  Query(int s, int e, int n) : s(s), e(e), n(n) {}
  bool operator<(const Query& O) const {
    if (s / sqrtN != O.s / sqrtN) return s < O.s;
    return e < O.e;
  }
};

int n, m, arr[MX], freq[MX], cnt[2 * MX], bucket[sz];

void init() {
  for (int i = 0; i < MX; ++i) arr[i] = freq[i] = cnt[i] = 0;
  for (int i = MX; i < 2 * MX; ++i) cnt[i] = 0;
  fill(bucket, bucket + sz, 0);
}

void update(int num, int d) {
  if (freq[num]) {
    cnt[freq[num]]--;
    bucket[freq[num] / 300]--;
  }
  freq[num] += d;
  cnt[freq[num]]++;
  bucket[freq[num] / 300]++;
}

int findMx() {
  for (int i = sz - 1; i >= 0; --i) {
    if (bucket[i]) {
      for (int j = (i + 1) * 300 - 1; j >= i * 300; --j) {
        if (cnt[j]) return j;
      }
    }
  }

  return 1;
}

int main() {
  fastio;
  while (1) {
    init();
    cin >> n;
    if (n == 0) break;
    cin >> m;
    sqrtN = sqrt(n);
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      arr[i] += 100001;
    }
    vector<Query> Q;
    for (int a, b, i{}; i < m; ++i) {
      cin >> a >> b;
      Q.pb(Query(a - 1, b, i));
    }

    sort(all(Q));
    int s = Q[0].s, e = Q[0].e, res[MX]{};
    for (int i = s; i < e; ++i) {
      update(arr[i], 1);
    }

    res[Q[0].n] = findMx();

    for (int i = 1; i < m; ++i) {
      while (s < Q[i].s) update(arr[s++], -1);
      while (Q[i].s < s) update(arr[--s], 1);
      while (e < Q[i].e) update(arr[e++], 1);
      while (Q[i].e < e) update(arr[--e], -1);
      res[Q[i].n] = findMx();
    }

    for (int i = 0; i < m; ++i) cout << res[i] << "\n";
  }
}