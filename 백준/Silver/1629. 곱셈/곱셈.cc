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

int a, b, c;
int my_pow(int n, int r) {
  if (r == 0) return 1;
  if (r % 2) return (1ll * n * my_pow(n, r - 1)) % c;
  int half = my_pow(n, r / 2);
  return (1ll * half * half) % c;
}
int main() {
  fastio;
  cin >> a >> b >> c;
  cout << my_pow(a, b) << "\n";
}