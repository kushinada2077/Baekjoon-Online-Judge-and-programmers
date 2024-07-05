#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#define ll long long
#define fastio cin.tie(0)->sync_with_stdio(0);
#define FOR_IN_1(n) for (int i = 0; i < n; ++i)
#define FOR_IN_2(i, n) for (int i = 0; i < n; ++i)
#define FOR_IN_3(i, m, n) for (int i = m; i < n; ++i)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define for_in(...) GET_MACRO(__VA_ARGS__, FOR_IN_3, FOR_IN_2, FOR_IN_1)(__VA_ARGS__)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
using namespace std;

int d[505][505];
// f(n, k) => 좌표 (n(row), k(col))까지 도달한 합
int main() {
  fastio;
  int n;
  cin >> n;
  vector<vector<int>> tri(n + 1, vector<int>(n + 1, 0));
  for_in(i, n) {
    for_in(j, i + 1) { cin >> tri[i + 1][j + 1]; }
  }
  for_in(i, 1, n + 1) for_in(j, 1, i + 1) d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + tri[i][j];
  cout << *max_element(d[n] + 1, d[n] + n + 1) << "\n";
}