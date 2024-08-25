#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
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
using ll = long long;
using namespace std;

bool is_num(const string& s) {
  for (auto& c : s) {
    if (c < '0' || '9' < c) return false;
  }
  return true;
}
int main() {
  fastio;
  int n, m;
  cin >> n >> m;
  string s;
  vector<string> a;
  map<string, int> b;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    a.pb(s);
    b[s] = i + 1;
  }
  for (int i = 0; i < m; ++i) {
    cin >> s;
    if (is_num(s)) cout << a[stoi(s) - 1] << "\n";
    else cout << b[s] << "\n";
  }
}