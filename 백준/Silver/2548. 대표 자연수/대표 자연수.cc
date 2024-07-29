#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <tuple>
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
  int n;
  cin >> n;
  vector<int> a(n), cnt(10005, 0), sum(10005, 0);
  for (auto& i : a) {
    cin >> i;
    cnt[i]++;
  }
  int tot = 0, num = 0;
  for (int i = 1; i < 10001; ++i) {
    tot += i * cnt[i];
    sum[i] = tot;
    num += cnt[i];
    cnt[i] = num;
  }
  int comp = 0x3f3f3f3f, idx = 0;
  for (int i = 1; i < 10001; ++i) {
    int diff = (i * cnt[i] - sum[i]) + (sum[10000] - sum[i]) - (i * (cnt[10000] - cnt[i]));
    if (diff < comp) {
      comp = diff;
      idx = i;
    }
  }
  cout << idx << "\n";
}