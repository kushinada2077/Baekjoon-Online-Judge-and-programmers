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
  vector<string> a(4);
  for (auto& s : a) cin >> s;
  sort(all(a));
  a.erase(unique(all(a)), a.end());
  for (int i = 0; i < si(a); ++i) {
    for (int j = 0; j < si(a); ++j) {
      cout << a[i] << " " << a[j] << "\n";
    }
  }
}