#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
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
  int n;
  cin >> n;
  string s;
  set<string> se;
  for_in(n) {
    cin >> s;
    sort(all(s));
    se.insert(s);
  }
  cout << si(se) << "\n";
}