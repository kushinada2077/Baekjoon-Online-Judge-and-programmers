#include <algorithm>
#include <deque>
#include <iostream>
#include <set>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using namespace std;

string v2s(vector<bool>& a) {
  string ret = "";
  for (auto i : a) ret += i ? "1" : "0";
  return ret;
}
int main() {
  fastio;
  int n, m, o, a, b, ans = 0;
  set<string> s;
  cin >> n >> m;
  vector<vector<bool>> train(n, vector<bool>(20, false));
  while (m--) {
    cin >> o;
    if (o == 1) {
      cin >> a >> b;
      train[a - 1][b - 1] = true;
    } else if (o == 2) {
      cin >> a >> b;
      train[a - 1][b - 1] = false;
    } else if (o == 3) {
      cin >> a;
      for (int i = 19; i > 0; --i) {
        train[a - 1][i] = train[a - 1][i - 1];
      }
      train[a - 1][0] = false;
    } else {
      cin >> a;
      for (int i = 0; i < 19; ++i) train[a - 1][i] = train[a - 1][i + 1];
      train[a - 1][19] = false;
    }
  }

  for (int i = 0; i < n; ++i) {
    string e = v2s(train[i]);
    if (s.find(e) != s.end()) continue;
    s.insert(e);
    ans++;
  }
  cout << ans << "\n";
}