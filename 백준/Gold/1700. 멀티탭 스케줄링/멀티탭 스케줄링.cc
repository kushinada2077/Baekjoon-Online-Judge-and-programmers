#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
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
using TP = tuple<int, int, int>;
using P = pair<int, int>;

int n, k, A[105];
set<int> c;
int main() {
  fastio;
  cin >> n >> k;
  for (int i = 0; i < k; ++i) cin >> A[i];

  int ans{};
  for (int i = 0; i < k; ++i) {
    if (c.contains(A[i])) continue;
    if (si(c) < n) {
      c.insert(A[i]);
      continue;
    }

    int mxIdx = -1;
    bool f = 0;
    for (auto v : c) {
      if (f) break;
      for (int j = i + 1; j < k; ++j) {
        if (A[j] == v) {
          mxIdx = max(mxIdx, j);
          break;
        }
        if (j == k - 1) {
          c.erase(v);
          c.insert(A[i]);
          mxIdx = -1;
          f = 1;
        }
      }
    }

    if (mxIdx != -1) {
      c.erase(A[mxIdx]);
      c.insert(A[i]);
    }
    ans++;
  }

  cout << ans << "\n";
}