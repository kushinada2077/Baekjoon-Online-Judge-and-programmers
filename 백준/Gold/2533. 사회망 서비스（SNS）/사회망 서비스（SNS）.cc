#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int N, a, b, ans = 0x3f3f3f3f;
int d[1000005][2];
bool vis[1000005];
vector<int> adj[1000005];

// f(n, k) = n번 노드가 k = 0 칠해지지 않음, k = 1 칠해짐일 때 최솟값
int f(int n, bool k) {
  if (vis[n]) return 0;
  if (d[n][k] != -1) return d[n][k];
  vis[n] = true;
  int result = k;
  int result2 = k;
  for (auto v : adj[n]) {
    result += f(v, !k);
    if (k) result2 += min(f(v, k), f(v, !k));
  }
  vis[n] = false;
  if (k)
    d[n][k] = min(result, result2);
  else
    d[n][k] = result;
  return d[n][k];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N - 1; ++i) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < N + 1; ++j) fill(d[j], d[j] + 2, -1);
    ans = min(ans, f(1, i));
  }
  cout << ans;
}