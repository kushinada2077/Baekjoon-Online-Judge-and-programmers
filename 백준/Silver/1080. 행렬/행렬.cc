
#include <algorithm>
#include <bitset>
#include <iostream>
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

bitset<51> a[51], b[51];
void flip(int x, int y) {
  for (int i = x; i < x + 3; ++i) {
    for (int j = y; j < y + 3; ++j) a[i].flip(j);
  }
}
int main() {
  fastio;
  int n, m, ans = 0;
  cin >> n >> m;
  for_in(n) {
    string s;
    cin >> s;
    a[i] = bitset<51>(s);
  }
  for_in(n) {
    string s;
    cin >> s;
    b[i] = bitset<51>(s);
  }

  for (int i = 0; i < n - 2; ++i) {
    for (int j = 0; j < m - 2; ++j) {
      if (a[i][j] != b[i][j]) {
        flip(i, j);
        ans++;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] != b[i][j]) {
        cout << "-1\n";
        return 0;
      }
    }
  }

  cout << ans << "\n";
}