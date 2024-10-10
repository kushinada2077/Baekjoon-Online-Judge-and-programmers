#include <algorithm>
#include <iostream>
#include <queue>
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

#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <vector>
#define PATH "/Users/leedongha/Downloads/PS/input.txt"
#define fastio cin.tie(0)->sync_with_stdio(0);
#define rep(n) for (int i = 0; i < n; ++i)
#define si(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define pb(...) push_back(__VA_ARGS__)
#define X first
#define Y second
#define ROOT 1
#define INF 0x3f3f3f3f
using ll = long long;
using namespace std;

int n, ans = -1;
bool chk[8];
vector<int> a, seq;
void bt(int v) {
  if (v == n) {
    int sum = 0;
    for (int i = 1; i < n; ++i) sum += abs(seq[i] - seq[i - 1]);
    ans = max(ans, sum);
    return;
  }

  for (int i = 0; i < n; ++i) {
    if (chk[i]) continue;
    chk[i] = 1;
    seq.pb(a[i]);
    bt(v + 1);
    chk[i] = 0;
    seq.pop_back();
  }
}
int main() {
  fastio;
  cin >> n;
  a = vector<int>(n);
  for (auto& i : a) cin >> i;
  bt(0);
  cout << ans << "\n";
}