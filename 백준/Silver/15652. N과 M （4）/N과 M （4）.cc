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

int n, m, arr[10];
void sol(int k) {
  if (k == m) {
    for (int i = 0; i < m; ++i) cout << arr[i] << " ";
    cout << "\n";
    return;
  }

  int st = 1;
  if (k) st = arr[k - 1];
  for (int i = st; i <= n; ++i) {
    arr[k] = i;
    sol(k + 1);
  }
}

int main() {
  fastio;
  cin >> n >> m;
  sol(0);
}