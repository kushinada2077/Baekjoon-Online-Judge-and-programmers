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
  int n, m;
  cin >> n >> m;
  vector<vector<vector<int>>> mat(2, vector<vector<int>>(n, vector<int>(m)));
  for (int i = 0; i < 2; ++i) {
    for (auto& i : mat[i]) {
      for (auto& j : i) cin >> j;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cout << mat[0][i][j] + mat[1][i][j] << " ";
    cout << "\n";
  }
}