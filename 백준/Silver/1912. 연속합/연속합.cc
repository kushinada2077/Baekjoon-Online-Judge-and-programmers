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

int n, ans = -INF, arr[100001];
set<int> sum;
int main() {
  fastio;
  cin >> n;
  sum.insert(0);
  for (int x, i = 0; i < n; ++i) {
    cin >> x;
    arr[i + 1] = arr[i] + x;
    ans = max(ans, arr[i + 1] - *sum.begin());
    sum.insert(arr[i + 1]);
  }

  cout << ans << "\n";
}