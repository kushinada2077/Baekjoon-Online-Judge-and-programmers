#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <queue>
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

int main() {
  fastio;
  vector<string> a(5);
  for (auto& s : a) cin >> s;

  for (int j = 0; j < 15; ++j) {
    for (int i = 0; i < 5; ++i) {
      if (si(a[i]) > j) cout << a[i][j];
    }
  }
}