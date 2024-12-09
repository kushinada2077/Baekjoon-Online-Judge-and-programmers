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

int tc, n, dp[101][101];
string w, s;
bool match(const string& w, const string& s) {
  int pos = 0;
  while (pos < si(w) && pos < si(s) && (w[pos] == '?' || w[pos] == s[pos])) pos++;
  if (pos == si(w)) return pos == si(s);
  if (w[pos] == '*') {
    for (int skip = 0; pos + skip < si(s); ++skip) {
      if (match(w.substr(pos + 1), s.substr(pos + skip))) return true;
    }
  }
  return false;
}
bool match2(int wPos, int sPos) {
  int& ret = dp[wPos][sPos];
  if (ret != -1) return ret;
  // 1. w[wPos]와 s[sPos]가 다른 경우 => 매칭 실패
  // 2. wPos == si(w)인 경우 sPos == si(s)여야 매칭
  while (wPos < si(w) && sPos < si(s) && (w[wPos] == '?' || w[wPos] == s[sPos])) {
    wPos++;
    sPos++;
  }
  if (wPos == si(w)) return ret = (sPos == si(s));
  // 3. sPos == si(s)인 경우 남은 w가 전부 *여야 함
  // 4. w[wPos] == '*'인 경우
  if (w[wPos] == '*') {
    for (int skip = 0; sPos + skip <= si(s); ++skip) {
      if (match2(wPos + 1, sPos + skip)) return ret = true;
    }
  }

  return ret = false;
}
bool match3(int wPos, int sPos) {
  int& ret = dp[wPos][sPos];
  if (ret != -1) return ret;
  if (wPos < si(w) && sPos < si(s) && (w[wPos] == '?' || w[wPos] == s[sPos])) return ret = match3(wPos + 1, sPos + 1);
  if (wPos == si(w)) return ret = (sPos == si(s));
  if (w[wPos] == '*')
    if (match3(wPos + 1, sPos) || sPos < si(s) && match3(wPos, sPos + 1)) return ret = true;
  return ret = false;
}
int main() {
  fastio;
  cin >> w >> n;
  vector<string> ans;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    fill(&dp[0][0], &dp[0][0] + 101 * 101, -1);
    if (match3(0, 0)) ans.pb(s);
  }
  for (string& ss : ans) cout << ss << "\n";
}