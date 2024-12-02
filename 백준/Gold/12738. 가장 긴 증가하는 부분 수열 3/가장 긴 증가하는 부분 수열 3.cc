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

int n, idx, seq[1000010];
int main() {
  fastio;
  cin >> n;
  seq[0] = -INF;
  for (int x, i = 0; i < n; ++i) {
    cin >> x;
    if (seq[idx] < x) seq[++idx] = x;
    else {
      int ii = lower_bound(seq, seq + idx + 1, x) - seq;
      seq[ii] = x;
    }
  }

  cout << idx << "\n";
}