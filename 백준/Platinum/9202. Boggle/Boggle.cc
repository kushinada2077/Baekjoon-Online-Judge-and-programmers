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

const int MX = 300000 * 8 + 5;
int w, b, unused = 2;
string s, word, board[4];
vector<int> ep;
vector<string> ans;
vector<vector<bool>> vis(4, vector<bool>(4, false));
int nxt[MX][26];
bool chk[MX];
int insert(const string& s) {
  int cur = ROOT;
  for (auto& c : s) {
    char p = c - 'A';
    if (!nxt[cur][p]) nxt[cur][p] = unused++;
    cur = nxt[cur][p];
  }
  chk[cur] = true;
  return cur;
}
bool find(const string& s) {
  int cur = ROOT;
  for (auto& c : s) {
    char p = c - 'A';
    if (!nxt[cur][p]) return false;
    cur = nxt[cur][p];
  }
  bool ret = chk[cur];
  if (chk[cur]) chk[cur] = false;
  return ret;
}
void dfs(int x, int y) {
  if (1 <= si(word) && si(word) <= 8 && find(word)) ans.pb(word);
  if (si(word) >= 8) return;
  for (int dir = 0; dir < 8; ++dir) {
    int nx = x + "21012020"[dir] - '1';
    int ny = y + "12102200"[dir] - '1';
    if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
    if (vis[nx][ny]) continue;
    vis[nx][ny] = true;
    word += board[nx][ny];
    dfs(nx, ny);
    vis[nx][ny] = false;
    word.pop_back();
  }
}
int score(int l) {
  if (l == 1 || l == 2) return 0;
  if (l == 3 || l == 4) return 1;
  if (l == 5) return 2;
  if (l == 6) return 3;
  if (l == 7) return 5;
  if (l == 8) return 11;
}
int main() {
  fastio;
  cin >> w;
  for_in(w) {
    cin >> s;
    ep.pb(insert(s));
  }
  cin >> b;
  while (b--) {
    ans.clear();
    for (auto& v : ep) chk[v] = true;
    for_in(4) cin >> board[i];
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        word = board[i][j];
        vis[i][j] = true;
        dfs(i, j);
        vis[i][j] = false;
      }
    }
    int sum = 0;
    sort(all(ans), [&](const string& a, const string& b) {
      if (si(a) == si(b)) return a < b;
      return si(a) > si(b);
    });
    for (auto& i : ans) sum += score(si(i));
    cout << sum << " " << ans[0] << " " << si(ans) << "\n";
  }
}