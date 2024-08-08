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

int main() {
  fastio;
  int n, m;
  string s, p;
  cin >> n >> m;
  map<string, string> h;
  for (int i = 0; i < n; ++i) {
    cin >> s >> p;
    h[s] = p;
  }
  for (int i = 0; i < m; ++i) {
    cin >> s;
    cout << h[s] << "\n";
  }
}