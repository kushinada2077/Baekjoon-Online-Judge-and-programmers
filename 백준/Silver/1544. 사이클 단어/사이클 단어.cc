#include <algorithm>
#include <iostream>
#include <queue>
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

bool comp(const string& s1, const string& s2) {
  if (si(s1) != si(s2)) return false;
  int l = si(s1);
  for (int st = 0; st < l; ++st) {
    int idx = st;
    bool f = true;
    for (int i = 0; i < l; ++i) {
      if (s1[i] != s2[idx]) {
        f = false;
        break;
      }
      idx = (idx + 1) % l;
    }
    if (f) return true;
  }
  return false;
}
int main() {
  fastio;
  int n;
  cin >> n;
  vector<string> a(n);
  vector<bool> c(n, false);
  for (auto& i : a) cin >> i;
  for (int i = 0; i < si(a); ++i) {
    if (c[i]) continue;
    for (int j = i + 1; j < si(a); ++j) {
      if (comp(a[i], a[j])) {
        n--;
        c[j] = true;
      }
    }
  }
  cout << n << "\n";
}