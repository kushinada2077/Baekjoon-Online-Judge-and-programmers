#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <numeric>
#include <queue>
#include <tuple>
#include <unordered_map>
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

vector<int> failure(const string& s) {
  vector<int> f(si(s));
  int j = 0;
  for (int i = 1; i < si(s); ++i) {
    while (j && s[i] != s[j]) j = f[j - 1];
    if (s[i] == s[j]) f[i] = ++j;
  }
  return f;
}
int main() {
  fastio;
  int n;
  string s;
  cin >> n >> s;
  vector<int> f = failure(s);
  cout << n - f[n - 1] << "\n";
}