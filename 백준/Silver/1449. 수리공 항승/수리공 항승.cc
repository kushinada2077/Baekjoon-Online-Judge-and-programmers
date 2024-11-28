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

int n, l, ans, arr[1010];
int main() {
  fastio;
  cin >> n >> l;
  for (int i = 0; i < n; ++i) cin >> arr[i];
  sort(arr, arr + n);
  int p = 0;

  do {
    ans++;
    p = lower_bound(arr + p, arr + n, arr[p] + l) - arr;
  } while (p < n);

  cout << ans << "\n";
}