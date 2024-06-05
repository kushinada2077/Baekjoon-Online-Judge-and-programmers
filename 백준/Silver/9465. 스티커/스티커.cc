#define ll long long
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int n, t;
int d[100005][3];
int val[2][100005];
int f(int c, int st) {
  if (c > n) return 0;
  if (d[c][st] != -1) return d[c][st];

  int result = f(c + 1, 0);
  if (st == 0)
    result = max(result, max(f(c + 1, 1) + val[0][c], f(c + 1, 2) + val[1][c]));
  else if (st == 1)
    result = max(result, f(c + 1, 2) + val[1][c]);
  else if (st == 2)
    result = max(result, f(c + 1, 1) + val[0][c]);

  d[c][st] = result;
  return result;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < 3; ++j) d[i + 1][j] = -1;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> val[i][j + 1];
      }
    }
    cout << f(1, 0) << "\n";
  }
}