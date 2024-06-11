#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int N, a, b;
int d[1000005][2];
bool vis[1000005];
vector<int> adj[1000005];

// f(n, k) = 부모의 상태가 k(1이면 얼리어답터, 0이면 아님)인 n번 노드를 루트로
// 하는 서브트리에서 최소 얼리어답터 수
int f(int n, bool k) {
  if (vis[n]) return 0;
  if (d[n][k] != -1) return d[n][k];

  vis[n] = true;
  int result = 1, result2 = 0x3f3f3f3f;
  for (auto v : adj[n]) result += f(v, 1);
  if (k) {
    result2 = 0;
    for (auto v : adj[n]) result2 += f(v, 0);
  }
  result = min(result, result2);
  vis[n] = false;
  d[n][k] = result;
  return result;
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
  for (int i = 0; i < N + 1; ++i) fill(d[i], d[i] + 2, -1);
  cout << f(1, 1);
}