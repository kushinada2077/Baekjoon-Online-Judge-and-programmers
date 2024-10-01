#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
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

int a[11], seq[11];
int main() {
  fastio;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i + 1];
  for (int i = 1; i <= n; ++i) {
    int cnt = 0;
    int* loc = find(seq, seq + n, 0);
    while (cnt != a[i]) {
      loc++;
      if (*loc == 0) cnt++;
    }
    *loc = i;
  }

  for (int i = 0; i < n; ++i) cout << seq[i] << " ";
}