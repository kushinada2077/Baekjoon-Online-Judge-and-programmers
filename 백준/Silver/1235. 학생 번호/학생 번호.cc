
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

int main() {
  fastio;
  int n;
  cin >> n;
  vector<string> student(n);
  for (auto& s : student) cin >> s;
  int l = si(student[0]);

  for (int k = 1; k < l; ++k) {
    bool f = true;
    set<string> ss;
    for (int i = 0; i < n; ++i) {
      string sub = student[i].substr(l - k, k);
      if (ss.find(sub) != ss.end()) {
        f = false;
        break;
      }
      ss.insert(sub);
    }
    if (f) {
      cout << k << "\n";
      return 0;
    }
  }
  cout << l << "\n";
}