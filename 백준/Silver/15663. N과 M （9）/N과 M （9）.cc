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

int n, m, seq[10], arr[10];
bool isUsed[10];
void sol(int k) {
  if (k == m) {
    for (int i = 0; i < m; ++i) cout << seq[i] << " ";
    cout << "\n";
    return;
  }

  int pre{};
  for (int i = 0; i < n; ++i) {
    if (isUsed[i] || pre == arr[i]) continue;
    isUsed[i] = 1;
    pre = seq[k] = arr[i];
    sol(k + 1);
    isUsed[i] = 0;
  }
}

int main() {
  fastio;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> arr[i];
  sort(arr, arr + n);
  sol(0);
}