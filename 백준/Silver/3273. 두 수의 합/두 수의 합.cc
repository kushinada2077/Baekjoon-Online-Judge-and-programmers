#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define for_in(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using ll = long long;
using namespace std;

int n, x;
int arr[1000001], cnt[1000001];

int main() {
  fastio;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  cin >> x;

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    int diff = x - arr[i];
    if (0 < diff && diff < 1000001) ans += 1ll * cnt[diff];
    cnt[arr[i]]++;
  }

  cout << ans << "\n";
}