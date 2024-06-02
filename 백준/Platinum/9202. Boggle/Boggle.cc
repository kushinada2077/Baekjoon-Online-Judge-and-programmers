#define PAIR pair<long long, int>
#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

const int MX = 300000 * 8 + 5;
const int ROOT = 1;
int unused = 2;
int nxt[MX][26];
bool chk[MX];
vector<string> board(4);
bool vis[4][4];
unordered_set<string> word;

void insert(string& s) {
  int v = ROOT;
  for (auto c : s) {
    if (nxt[v][c] == 0) nxt[v][c] = unused++;
    v = nxt[v][c];
  }
  chk[v] = true;
}

bool find(string& s) {
  int v = ROOT;
  for (auto c : s) {
    if (nxt[v][c] == 0) return false;
    v = nxt[v][c];
  }
  return chk[v];
}

bool OOB(int a, int b) { return a < 0 || a >= 4 || b < 0 || b >= 4; }
void dfs(int x, int y, string& s) {
  if (OOB(x, y) || vis[x][y] || s.size() >= 8) return;
  s += board[x][y];
  vis[x][y] = true;
  if (find(s)) {
    word.insert(string(s));
  }
  for (int dir = 0; dir < 8; ++dir) {
    int nx = x + ("00122210"[dir] - '1');
    int ny = y + ("12221000"[dir] - '1');
    dfs(nx, ny, s);
  }
  s.pop_back();
  vis[x][y] = false;
}

int score(string& s) {
  int len = s.size();
  if (len == 1 || len == 2) return 0;
  if (len == 3 || len == 4) return 1;
  if (len == 5) return 2;
  if (len == 6) return 3;
  if (len == 7) return 5;
  if (len == 8) return 11;

  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int w;
  string s;
  cin >> w;
  while (w--) {
    cin >> s;
    insert(s);
  }

  cin >> w;
  while (w--) {
    word.clear();
    for (int i = 0; i < 4; ++i) {
      cin >> board[i];
    }
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        for (int k = 0; k < 4; ++k) fill(vis[i], vis[i] + 4, 0);
        s = "";
        dfs(i, j, s);
      }
    }

    vector<string> m(word.begin(), word.end());
    sort(m.begin(), m.end(), [](string a, string b) {
      if (a.size() == b.size()) return a < b;
      return a.size() > b.size();
    });
    int sum = 0;
    for (auto s : m) {
      sum += score(s);
    }
    cout << sum << " " << m[0] << " " << m.size() << "\n";
  }
}