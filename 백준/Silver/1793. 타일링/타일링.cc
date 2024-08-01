#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
using ll = long long;
using namespace std;

string add(const string& s1, const string& s2) {
  int p1 = si(s1) - 1, p2 = si(s2) - 1;
  string ret = "";
  bool r = 0;
  while (p1 >= 0 || p2 >= 0 || r) {
    int res = r;
    r = 0;
    if (0 <= p1) res += s1[p1--] - '0';
    if (0 <= p2) res += s2[p2--] - '0';
    r = res / 10;
    ret += to_string(res % 10);
  }
  reverse(all(ret));
  return ret;
}

vector<string> dp(255, "-1");
string f(int n) {
  if (n == 0) return "1";
  if (n == 1) return "1";
  if (n == 2) return "3";
  string& ret = dp[n];
  if (ret != "-1") return ret;
  ret = add(f(n - 2), add(f(n - 1), f(n - 2)));
  return ret;
}
int main() {
  fastio;
  int n;
  while (cin >> n) cout << f(n) << "\n";
}