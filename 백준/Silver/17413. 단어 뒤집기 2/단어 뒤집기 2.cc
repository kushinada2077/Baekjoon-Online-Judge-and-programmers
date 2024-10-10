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

#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define rep(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using ll = long long;
using namespace std;

int main() {
  fastio;
  string s, tmp;
  getline(cin, s);
  vector<string> ans;
  bool state = 0;

  for (auto& c : s) {
    if (c == '<') {
      state = 1;
      if (si(tmp)) {
        reverse(all(tmp));
        ans.pb(tmp);
      }
      tmp = "";
    }

    if (c == '>') {
      state = 0;
      tmp += c;
      ans.pb(tmp);
      tmp = "";
      continue;
    }

    if (!state && c == ' ') {
      reverse(all(tmp));
      tmp += " ";
      ans.pb(tmp);
      tmp = "";
      continue;
    }

    tmp += c;
  }

  if (s.back() != '>') reverse(all(tmp));
  ans.pb(tmp);

  for (auto& s : ans) cout << s;
}