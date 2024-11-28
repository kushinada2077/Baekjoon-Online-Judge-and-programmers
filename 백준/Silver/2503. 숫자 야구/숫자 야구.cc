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

int n, ans;
TP arr[101];
bool sol(int k) {
  for (int i = 0; i < n; ++i) {
    auto [a, b, c] = arr[i];
    int st{}, ball{};
    string tmp1 = to_string(k), tmp2 = to_string(a);
    for (int j = 0; j < 3; ++j) st += tmp1[j] == tmp2[j];
    for (int j = 0; j < 3; ++j) {
      for (int l = 0; l < 3; ++l) {
        if (j == l) continue;
        if (tmp2[j] == tmp1[l]) {
          ball++;
          break;
        }
      }
    }

    if (b != st || c != ball) return 0;
  }

  return 1;
}
int main() {
  fastio;
  cin >> n;
  for (int a, b, c, i{}; i < n; ++i) {
    cin >> a >> b >> c;
    arr[i] = TP(a, b, c);
  }

  int ans = 0;

  for (int i = 111; i <= 999; ++i) {
    int tmp = i;
    set<int> s;
    while (tmp) {
      s.insert(tmp % 10);
      tmp /= 10;
    }
    if (si(s) != 3) continue;
    bool f = 0;

    tmp = i;
    while (tmp) {
      if (tmp % 10 == 0) {
        f = 1;
        break;
      }
      tmp /= 10;
    }
    if (f) continue;
    ans += sol(i);
  }
  cout << ans << "\n";
}