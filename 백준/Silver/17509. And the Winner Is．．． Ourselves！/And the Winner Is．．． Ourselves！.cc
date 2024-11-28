#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define L_PATH "input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define rep(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using TP = tuple<int, int, int>;
using P = pair<int, int>;

P A[12];
int main() {
  fastio;
  for (int i = 0; i < 11; ++i) {
    cin >> A[i].X >> A[i].Y;
  }
  sort(A, A + 11);
  int totT{}, ans{};
  for (int i = 0; i < 11; ++i) {
    totT += A[i].X;
    ans += totT + 20 * A[i].Y;
  }

  cout << ans << "\n";
}