#include <algorithm>
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

int n, m, x;
vector<int> a, num;
vector<bool> used(10, false);
unordered_set<string> se;
void f(int v) {
  if (v == m) {
    string tmp = "";
    for (auto& i : num) tmp += i;
    if (se.find(tmp) != se.end()) return;
    se.insert(tmp);
    for (auto& c : num) cout << c << " ";
    cout << "\n";
  }

  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      used[i] = true;
      num.pb(a[i]);
      f(v + 1);
      used[i] = false;
      num.pop_back();
    }
  }
}
int main() {
  fastio;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    a.pb(x);
  }
  sort(all(a));
  f(0);
}