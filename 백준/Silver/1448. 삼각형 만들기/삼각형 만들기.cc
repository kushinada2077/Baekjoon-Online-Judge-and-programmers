#include <algorithm>
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
  vector<int> a(n);
  for (auto& i : a) cin >> i;
  sort(all(a), greater<>());
  int ans = -1;
  for (int i = 0; i < n - 2; ++i) {
    int ab = a[i + 1] + a[i + 2];
    if (a[i] < ab && a[i] + ab > ans) ans = a[i] + ab;
  }
  cout << ans << "\n";
}