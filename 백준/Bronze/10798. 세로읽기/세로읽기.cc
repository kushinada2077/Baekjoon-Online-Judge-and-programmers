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
  vector<vector<char>> a(5, vector<char>(15, '\0'));
  string s;
  for (int i = 0; i < 5; ++i) {
    getline(cin, s);
    for (int j = 0; j < si(s); ++j) a[i][j] = s[j];
  }

  for (int i = 0; i < 15; ++i) {
    for (int j = 0; j < 5; ++j) {
      if (a[j][i] != '\0') cout << a[j][i];
    }
  }
}