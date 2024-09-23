#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using ll = long long;
using namespace std;

vector<int> adj[26];
int indg[26], cnt;
bool chk[26], dup[26][26];
int main() {
  fastio;
  int n;
  cin >> n;
  vector<string> list(n);
  for (int i = 0; i < n; ++i) {
    cin >> list[i];
    for (auto& c : list[i]) {
      if (!chk[c - 'a']) {
        chk[c - 'a'] = 1;
        cnt++;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    string& s1 = list[i];
    for (int j = i + 1; j < n; ++j) {
      string& s2 = list[j];
      int l = max(si(s1), si(s2));
      for (int k = 0; k < l; ++k) {
        if (k >= min(si(s1), si(s2))) {
          if (si(s1) > si(s2)) {
            cout << "!\n";
            return 0;
          }
          break;
        } else if (s1[k] == s2[k]) continue;
        else if (dup[s1[k] - 'a'][s2[k] - 'a']) break;
        else {
          adj[s1[k] - 'a'].pb(s2[k] - 'a');
          indg[s2[k] - 'a']++;
          dup[s1[k] - 'a'][s2[k] - 'a'] = 1;
          break;
        }
      }
    }
  }

  queue<int> q;
  for (int i = 0; i < 26; ++i) {
    if (indg[i] == 0 && chk[i]) {
      q.push(i);
    }
  }

  string ans = "";
  bool f = false;
  for (int i = 0; i < cnt; ++i) {
    if (si(q) > 1) {
      f = true;
    } else if (si(q) == 0) {
      cout << "!\n";
      return 0;
    }
    int cur = q.front();
    q.pop();
    for (auto& nxt : adj[cur]) {
      if (--indg[nxt] == 0) {
        q.push(nxt);
      }
    }
    ans += cur + 'a';
  }
  if (f) cout << "?\n";
  else cout << ans << "\n";
}