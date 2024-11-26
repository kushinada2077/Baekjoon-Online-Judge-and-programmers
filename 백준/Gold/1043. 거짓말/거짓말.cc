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

int n, m, k;
set<int> tp;
vector<int> pp[51];
bool isPoss(int num) {
  for (auto i : pp[num]) {
    if (tp.contains(i)) return 0;
  }
  return 1;
}
int main() {
  fastio;
  cin >> n >> m >> k;
  for (int x, i = 0; i < k; ++i) {
    cin >> x;
    tp.insert(x);
  }
  for (int x, i = 0; i < m; ++i) {
    cin >> k;
    for (int j{}; j < k; ++j) {
      cin >> x;
      pp[i].pb(x);
    }
  }

  while (true) {
    int pre = si(tp);
    for (int i = 0; i < m; ++i) {
      if (!isPoss(i)) {
        for (auto j : pp[i]) tp.insert(j);
      }
    }
    if (pre == si(tp)) break;
  }

  int d = 0;
  for (int i = 0; i < m; ++i) {
    if (!isPoss(i)) d++;
  }

  cout << m - d << "\n";
}