#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <tuple>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
using ll = long long;
using namespace std;

int n, m;
vector<int> a, arr, vis(8, false);
void f(int k) {
  if (k == m) {
    for (auto& i : a) cout << i << " ";
    cout << "\n";
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (vis[i]) continue;
    vis[i] = true;
    a.pb(i + 1);
    f(k + 1);
    vis[i] = false;
    a.pop_back();
  }
}
int main() {
  fastio;
  cin >> n >> m;
  f(0);
}