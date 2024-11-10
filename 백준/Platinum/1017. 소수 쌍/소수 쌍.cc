#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
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

const int MX = 200;
int n, A[MX], B[MX];
bool vis[MX];
vector<int> arr[2], adj[MX];
bool isPrime(int n) {
  int cnt = 0;

  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) cnt += 2;
    if (i * i == n) cnt--;
  }

  return cnt == 2;
}

void init() {
  for (int i = 0; i < MX; ++i) {
    A[i] = B[i] = -1;
    vis[i] = 0;
  }
}
bool dfs(int a) {
  vis[a] = 1;
  for (int b : adj[a]) {
    if (B[b] == -1 || !vis[B[b]] && dfs(B[b])) {
      A[a] = b;
      B[b] = a;
      return 1;
    }
  }

  return 0;
}
int main() {
  fastio;
  cin >> n;
  bool f = 0;
  for (int i = 0, x; i < n; ++i) {
    cin >> x;
    if (i == 0) f = x % 2;
    if (x % 2 == f) arr[f].pb(x);
    else arr[!f].pb(x);
  }

  vector<int> ans;

  for (int i = 1; i < si(arr[f]); ++i) {
    for (int j = 0; j < si(arr[!f]); ++j) {
      if (!isPrime(arr[f][i] + arr[!f][j])) continue;
      adj[2 * i].pb(2 * j + 1);
    }
  }

  for (int cnt{}, i = 0; i < si(arr[!f]); ++i, cnt = 0) {
    if (!isPrime(arr[f][0] + arr[!f][i])) continue;
    init();
    adj[0].pb(2 * i + 1);

    for (int j = 0; j < si(arr[f]); ++j) {
      fill(vis, vis + MX, 0);
      if (dfs(2 * j)) cnt++;
    }

    if (cnt == n / 2) ans.pb(arr[!f][i]);
    adj[0].pop_back();
  }

  sort(all(ans));
  if (si(ans)) {
    for (auto& i : ans) cout << i << " ";
  } else cout << "-1\n";
}