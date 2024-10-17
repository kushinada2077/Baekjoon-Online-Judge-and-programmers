#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
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
using T = tuple<int, int, int>;
using P = pair<int, int>;

// 닫힌 방은 홀수번, 열린 방은 짝수번 눌려야 함
// 각 스위치는 두 번 이상 누르는 것은 의미가 없으므로 누르지 않거나 누르는 경우 두 가지뿐

inline int oppo(int v) { return v % 2 ? v + 1 : v - 1; }
const int MX = 100001;
int n, m, k, cnt, SN;
int dfsn[MX << 1], sn[MX << 1];
bool finished[MX << 1];
vector<int> adj[MX << 1], btn[MX], room;
stack<int> s;

int dfs(int cur) {
  int res = dfsn[cur] = ++cnt;
  s.push(cur);

  for (auto& nxt : adj[cur]) {
    if (dfsn[nxt] == 0) res = min(res, dfs(nxt));
    else if (finished[nxt] == 0) res = min(res, dfsn[nxt]);
  }

  if (res == dfsn[cur]) {
    while (1) {
      int v = s.top();
      s.pop();
      finished[v] = 1;
      sn[v] = SN;
      if (cur == v) break;
    }
    SN++;
  }
  return res;
}

int main() {
  fastio;
  cin >> n >> m;
  room.resize(n + 1);
  rep(n) cin >> room[i + 1];
  for (int a, b, x, i{}; i < m; ++i) {
    cin >> k;
    for (int j = 0; j < k; ++j) {
      cin >> x;
      btn[x].pb(i + 1);
    }
  }

  for (int i = 1; i <= n; ++i) {
    bool state = room[i];
    auto [a, b] = P(btn[i][0], btn[i][1]);
    a *= 2;
    b *= 2;
    // 열려 있으면 스위치 0번, 2번
    if (state) {
      adj[a].pb(b);
      adj[b].pb(a);
      adj[oppo(a)].pb(oppo(b));
      adj[oppo(b)].pb(oppo(a));
    }
    // 닫혀 있으면 스위치 1번
    else {
      adj[a].pb(oppo(b));
      adj[b].pb(oppo(a));
      adj[oppo(a)].pb(b);
      adj[oppo(b)].pb(a);
    }
  }

  for (int i = 1; i <= 2 * m; ++i) {
    if (dfsn[i] == 0) dfs(i);
  }

  bool ans = 1;
  for (int i = 1; i <= m; ++i) {
    if (sn[2 * i - 1] == sn[2 * i]) {
      ans = 0;
      break;
    }
  }

  cout << ans << "\n";
}